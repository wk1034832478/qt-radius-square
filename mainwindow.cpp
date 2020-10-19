#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QMessageBox>

const static double PI = 3.1416;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString tmpNum;
    bool ok;
    double radius = 0, square = 0;
    // 获取输入半径
    QString rad = ui->radiusEdit->text();
    // 转化
    radius = rad.toFloat(&ok);
    if (!ok) {
       QMessageBox::information(NULL, "提示", "输入有误，请输入正确的半径！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }

    // 进行面积计算
    square = radius * radius * PI;

    // 将面积数据回填到另外一个输入框当中
    tmpNum.setNum(square);
    ui->squareEdit->setText(tmpNum);
}

void MainWindow::on_radiusEdit_textEdited(const QString &arg1)
{
    QString tmpNum;
    bool ok;
    double radius = 0, square = 0;
    // 获取输入半径
    QString rad = ui->radiusEdit->text();
    // 转化
    radius = rad.toFloat(&ok);
    if (!ok) {
       QMessageBox::information(NULL, "提示", "输入有误，请输入正确的半径！", QMessageBox::Yes , QMessageBox::Yes);
        return;
    }

    // 进行面积计算
    square = radius * radius * PI;

    // 将面积数据回填到另外一个输入框当中
    tmpNum.setNum(square);
    ui->squareEdit->setText(tmpNum);
}
