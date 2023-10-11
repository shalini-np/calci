#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QRegularExpression>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




        // Connect number buttons
        connect(ui->num0, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num1, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num2, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num3, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num4, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num5, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num6, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num7, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num8, SIGNAL(clicked()), this, SLOT(onDigitClicked()));
        connect(ui->num9, SIGNAL(clicked()), this, SLOT(onDigitClicked()));

        // Connect other number buttons (0-9) and operator buttons (+, -, *, /, %, =) here
        connect(ui->numper, SIGNAL(clicked()), this, SLOT(onOperationClicked()));
        connect(ui->numadd, SIGNAL(clicked()), this, SLOT(onOperationClicked()));
        connect(ui->numsub, SIGNAL(clicked()), this, SLOT(onOperationClicked()));
        connect(ui->nummul, SIGNAL(clicked()), this, SLOT(onOperationClicked()));
        connect(ui->numdiv, SIGNAL(clicked()), this, SLOT(onOperationClicked()));
        connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(onEqualClicked()));
        connect(ui->numclear, SIGNAL(clicked()), this, SLOT(onClearClicked()));
}

MainWindow::~MainWindow()
{
        delete ui;
}

void MainWindow::onDigitClicked()
{
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (button) {
            QString digit = button->text();
            ui->resultdisplay->setText(ui->resultdisplay->text() + digit);
        }
}

void MainWindow::onOperationClicked()
{
        QPushButton *button = qobject_cast<QPushButton *>(sender());
        if (button) {
            QString op = button->text();
            ui->resultdisplay->setText(ui->resultdisplay->text() + op);
        }
}

void MainWindow::onEqualClicked()
{
        QString expression = ui->resultdisplay->text();
        QRegularExpression rx("([0-9.]+)([+\\-*/%])([0-9.]+)");

        QRegularExpressionMatch match = rx.match(expression);

        if (match.hasMatch()) {
            double left = match.captured(1).toDouble();
            double right = match.captured(3).toDouble();
            QString op = match.captured(2);

            double result = 0.0;
            if (op == "+")
                result = left + right;
            else if (op == "-")
                result = left - right;
            else if (op == "*")
                result = left * right;
            else if (op == "/")
            {
                if (right != 0.0)
                    result = left / right;
                else
                    ui->resultdisplay->setText("Error");
            } else if (op == "%")
            {
                if (right != 0)
                    result = (left / right) * 100;
                else
                    ui->resultdisplay->setText("Error");
            }

            ui->resultdisplay->setText(QString::number(result));
        } else
        {
            ui->resultdisplay->setText("Error: Invalid expression");
        }
}


void MainWindow::onClearClicked()
{
        ui->resultdisplay->clear();
}



