#include <QtCore/QCoreApplication>
#include <QDir>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	/*QString strlibPath(QDir::toNativeSeparators(QCoreApplication::applicationDirPath()) +
		QDir::separator() + "plugins");
	a.addLibraryPath(strlibPath);*/
	QTextCodec *codec = QTextCodec::codecForLocale();
	QTextCodec::setCodecForLocale(codec);

	QStringList drivers = QSqlDatabase::drivers();
	foreach(QString driver, drivers)
		qDebug() << driver;

	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("test");
	db.setUserName("root");
	db.setPassword("123456");
	if (!db.open())
	{
		qDebug() << "Unable to open database";
	}
	else
	{
		qDebug() << "OK!";
	}
	return a.exec();
}
