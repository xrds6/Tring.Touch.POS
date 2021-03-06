#include <QCoreApplication>
#include <QGuiApplication>
#include <QKeyEvent>
#include <QQuickItem>
#ifdef _WIN32
#include <Windows.h>
#endif
#include "headers/keyemitter.h"

KeyEmitter::KeyEmitter()
{
}

KeyEmitter::~KeyEmitter()
{
}

void KeyEmitter::emitKey(Qt::Key key)
{
    QQuickItem* receiver = qobject_cast<QQuickItem*>(QGuiApplication::focusObject());
    if(!receiver) {
        return;
    }
    QKeyEvent pressEvent = QKeyEvent(QEvent::KeyPress, key, Qt::NoModifier, QKeySequence(key).toString());
    QKeyEvent releaseEvent = QKeyEvent(QEvent::KeyRelease, key, Qt::NoModifier);
    QCoreApplication::sendEvent(receiver, &pressEvent);
    QCoreApplication::sendEvent(receiver, &releaseEvent);
}
