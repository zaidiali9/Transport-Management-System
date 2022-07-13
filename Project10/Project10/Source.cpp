#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;
class TMS;
class name;
class service;
class person;
class features;
class Vehical;
class Customer;
class driver;
class Delivery;
class ride;
class date;
class mtime;
class TMS
{
public: 
	virtual void addacustomer() {}
	virtual void printinfo(){}
	virtual void addadriver(){}
	virtual void setinitials(int h){}
	virtual void addavehical(){}
	virtual void printserviceinfo(){}
	virtual int getid(){return 0;}
	virtual void filewriting(fstream& obj) {}
	virtual int getliecencecount(){return 0;}
	virtual void setservice(TMS** D, TMS** C, TMS** V){}
	virtual void writehistory(int date, int month){}
	virtual int getstatus(){return 0;}
	virtual void setstatusbook(){}
	virtual void setstatuscancel(){}
	virtual void setdriversranking(){}
	virtual void setvehicalranking(){}
	virtual void sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj) {}
	virtual void gethistory(){}
	virtual void sethistory1(int noofpeo, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj){}
	virtual void getuserhistory(TMS** D, TMS** V){}
	virtual void setoverallranking(){}
	virtual float getoverallranking(){return 2.0;}
	virtual int getdid(){return 5;}
	virtual int getvod(){return 5;}
	virtual float getsalary(){return 0.0;}
	virtual void cancelservice(TMS** D, TMS** V){}
	virtual void setcancelationhistory(int id){}
	virtual void pen_ser_petd(int day, int month, int year){}
	virtual void filehis(service* po) {}
	virtual bool samevehical(int a){return false;}
	virtual void destructor(){}
	virtual void p_d_ups() {}
	virtual int getdis() { return 0; }
	virtual bool get_sta()
	{
		return true;
	}
};
void menu()
{
	cout << "Press  1 to add new customer" << endl;
	cout << "Press  2 to Add a Driver" << endl;
	cout << "Press  3 to Add a Vehical" << endl;
	cout << "Press  4 to Print list of Customers" << endl;
	cout << "Press  5 to Print list of all Drivers" << endl;
	cout << "Press  6 to Print list of All Vehicals " << endl;
	cout << "Press  7 to Service history of a perticular vehical" << endl;
	cout << "Press  8 to Booking history of the perticular customer" << endl;
	cout << "Press  9 to Service history of the drivers" << endl;
	cout << "Press 10 to Print list of all Drivers who have the ranking above 4.5" << endl;
	cout << "Press 11 to Print list of all drivers having multiple liecences and their liecence information" << endl;
	cout << "Press 12 to get the salaries of the drivers" << endl;
	cout << "Press 13 to Book a service" << endl;
	cout << "Press 14 to cancel the Service" << endl;
	cout << "Press 15 for the List of customers who have used the same vehical" << endl;
	cout << "Press 16 for the list of the drivers who have completed the delivery service on the same days" << endl;
	cout << "Press 17 to print the list of all pending services on that perticular date" << endl;
	cout << "Press 18 to print the pending services of the perticular driver" << endl;
	cout << "Press 19 to get the all canceled services by a customer" <<endl;
	cout << "Press 20 to remove the Driver" << endl;
	cout << "Press 21 to remove a Vehical" << endl;
	cout << "Press 22 to complete a booking " << endl;
}
class name :public TMS   
{
public:
	name();
	~name();
	friend ostream& operator<<(ostream& out, const name& n);
	friend istream& operator>>(istream& in, const name& n);
	name operator=(char a[])
	{
		int i = 0;
		for (;a[i] != ' ';i++)
		{
			fname[i] = a[i];
		}
		fname[i] = '\0';
		i++;
		int j = 0;
		for (;a[i] != '\0';i++, j++)
		{
			lname[j] = a[i];
		}
		lname[j] = '\0';
		return *this;
	}
	void setname()
	{
		cout << "First Name:" << endl;
		cin.getline(fname, 10);
		cout << "Last Name:" << endl;
		cin.getline(lname, 10);
	}
	void destructor()
	{
		delete fname;
		delete lname;
	}
	private:
		char* fname;
		char* lname;
};
name::name()
{
	fname = new char[10];
	lname = new char[10];
}
name::~name()
{
}
ostream& operator<<(ostream& out, const name& n)
{
	out << n.fname << " " << n.lname;
	return out;
}
istream& operator>>(istream& in, const name& n)
{
	in.ignore();
	in.getline(n.fname, 10);
	in.getline(n.lname, 10);
	return in;
}
class date :public TMS
{
public:
	date(int i, int j, int k);
	~date();
	friend ostream& operator<<(ostream& out, const date& n);
	friend istream& operator>>(istream& cin, date& n)
	{
		bool flag = 0;
		while (flag != 1)
		{
			cout << "Year:" << endl;
			cin >> n.year;
			if (n.year > 0)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Month:" << endl;
			cin >> n.month;
			if (n.month > 0 && n.month <= 12)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Day:" << endl;
			cin >> n.day;
			if (n.day > 0 && n.day <= 31)
			{
				flag = 1;
			}
		}
		return cin;
	}
	void setdate()
	{
		bool flag = 0;
		while (flag != 1)
		{
			cout << "Year:" << endl;
			cin >> year;
			if (year > 0)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Month:" << endl;
			cin >> month;
			if (month > 0 && month <= 12)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Day:" << endl;
			cin >> day;
			if (day > 0 && day <= 31)
			{
				flag = 1;
			}
		}
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	date operator=(date& obj)
	{
		year = obj.year;
		month = obj.month;
		day = obj.day;
		return *this;
	}
	friend bool operator==(date& obj, date& obj2)
	{
		if (obj2.day == obj.day && obj2.month == obj.month && obj2.year == obj.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int day;
	int month;
	int year;
};
date::date(int i = 0, int j = 0, int k = 0)
{
	day = i;
	month = j;
	year = k;
}
date::~date()
{
}
ostream& operator<<(ostream& out, const date& n)
{
	out << n.day << "/" << n.month << "/" << n.year;
	return out;
}
class mtime :public TMS
{
public:
	mtime(int hour, int min, int sec);
	~mtime();
	friend ostream& operator<<(ostream& out, const mtime& n);
	friend istream& operator>>(istream& input, mtime& n);
	void settime()
	{
		bool flag = 0;
		while (flag != 1)
		{
			cout << "Hour:" << endl;
			cin >> hour;
			if (hour > 0 && hour <= 24)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Min:" << endl;
			cin >> min;
			if (min > 0 && min <= 60)
			{
				flag = 1;
			}
		}
		flag = 0;
		while (flag != 1)
		{
			cout << "Second:" << endl;
			cin >> sec;
			if (sec > 0 && sec <= 60)
			{
				flag = 1;
			}
		}
	}
private:
	int hour;
	int min;
	int sec;
};
ostream& operator<<(ostream& out, const mtime& n)
{
	out << n.hour << ":" << n.min << ":" << n.sec << endl;
	return out;
}
istream& operator>>(istream& input, mtime& n)
{
	bool flag = 0;
	while (flag != 1)
	{
		cout << "Hour:" << endl;
		input >> n.hour;
		if (n.hour > 0 && n.hour <= 24)
		{
			flag = 1;
		}
	}
	flag = 0;
	while (flag != 1)
	{
		cout << "Minutes:" << endl;
		input >> n.min;
		if (n.min > 0 && n.min <= 60)
		{
			flag = 1;
		}
	}
	flag = 0;
	while (flag != 1)
	{
		cout << "Seconds:" << endl;
		input >> n.sec;
		if (n.sec > 0 && n.sec <= 60)
		{
			flag = 1;
		}
	}
	return input;
}
mtime::mtime(int hour = 0, int min = 0, int sec = 0)
{
	this->hour = hour;
	this->min = min;
	this->sec = sec;
}
mtime::~mtime()
{
}
class service :public TMS
{
public:
	service();
	~service();
	void setservice()
	{
		cout << "Source:" << endl;
		cin.get(source, 10);
		cout << "Destination:" << endl;
		cin.get(destination, 10);
		cout << "Distance:" << endl;
		cin >> distance;
		cout << "Booking Date:" << endl;
		cin >> bookingdate;
		cout << "Time:" << endl;
		cin >> bookingtime;
	}
	virtual void setstatusofride()
	{
		status = false;
	}
	int getsid()
	{
		return sid;
	}
	int getdid()
	{
		return did;
	}
	int getvod()
	{
		return vid;
	}
	bool getservicestatus()
	{
		return status;
	}
	int getbookdate_obj1()
	{
		return bookingdate.getday();
	}
	int getbookdate_obj2()
	{
		return bookingdate.getyear();
	}
	int getbookdate_obj3()
	{
		return bookingdate.getmonth();
	}
	void destructor()
	{
		delete source;
		delete destination;
	}
protected:
	char* source;
	char* destination;
	float distance;
	date bookingdate;
	mtime bookingtime;
	bool status;
	float fuelrate;
	int cid;
	int did;
	int vid;
	int sid;
	float Driverranking;
	float vehicalranking;
};
service::service()
{
	source = new char[10];
	destination = new char[10];
	distance = 0.0;
	status = false;
	fuelrate = 150.46;
	cid = 0;
	did = 0;
	vid = 0;
	sid = 0;
	Driverranking = 0.0;
	vehicalranking = 0.0;
}
service::~service()
{
}
class Ride :public service
{
public:
	Ride();
	Ride(int noofpeople, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	~Ride();
	void printserviceinfo();
	void setservice(TMS** D, TMS** C, TMS** V);
	void setdriversranking();
	int getdis()
	{
		return distance;
	}
	void destructor()
	{
		delete ridetype;
	}
private:
	int noofpessengers;
	char* ridetype;
};
Ride::Ride()
{
	noofpessengers = 0;
	ridetype = new char[20];
	Driverranking = 0.0;
	vehicalranking = 0.0;
}
void Ride::setdriversranking()
{
	cout << "Rate your Driver" << endl;
	cin >> Driverranking;
}
Ride::Ride(int noofpeople, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	this->noofpessengers = noofpeople;
	this->ridetype = new char[30];
	int i = 0;
	for (;ridetype[i] != '\0';i++)
	{
		this->ridetype[i] = ridetype[i];
	}
	this->ridetype[i] = '\0';
	i = 0;
	for (;source[i] != '\0';i++)
	{
		this->source[i] = source[i];
	}
	this->source[i] = '\0';
	i = 0;
	for (;destination[i] != '\0';i++)
	{
		this->destination[i] = destination[i];
	}
	this->destination[i] = '\0';
	this->distance = distance;
	this->fuelrate = fuelrate;
	this->cid = cid;
	this->vid = vid;
	this->did = did;
	this->sid = sid;
	this->bookingdate = obj;
}
Ride::~Ride()
{
}
void Ride::printserviceinfo()
{
	cout << "Source:" << source << endl;
	cout << "Destination:" << destination << endl;
	cout << "Distance:" << distance << endl;
	cout << "Status:" << status << endl;
	cout << "Fuel Price:" << fuelrate << endl;
	cout << "Customer ID:" << cid << endl;
	cout << "Number of Passengers:" << noofpessengers << endl;
	cout << "RideType:" << ridetype << endl;
	cout << "Vehical Ranking:" << vehicalranking << endl;
	cout << "Driver Ranking:" << Driverranking << endl;
	cout << endl << endl;
}
void Ride::setservice(TMS** D, TMS** C, TMS** V)
{
	bool flag = false;
	int check = 0;
	cout << "Customer ID:" << endl;
	cin >> cid;
	for (int i = 0;i < 15;i++)
	{
		if (C[i]->getid() == cid)
		{
			flag = true;
			check = i;
			break;
		}
	}
	if (flag == true)
	{
		cout << "Destination:" << endl;
		cin.ignore();
		cin.get(destination, 10);
		cin.ignore();
		cout << "Source:" << endl;
		cin.ignore();
		cin.get(source, 10);
		cin.ignore();
		cout << "Distance:" << endl;
		cin >> distance;
		cout << "Bookings Date" << endl;
		cin >> bookingdate;
		cout << "Booking Time:" << endl;
		cin >> bookingtime;
		status = false;
		fuelrate = 106.6;
		cout << "Number Of Passengers:" << endl;
		cin >> noofpessengers;
		cout << "RideType:" << endl;
		cin.ignore();
		cin.get(ridetype, 30);
		cin.ignore();
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getstatus() == 1 || D[i]->getstatus() == 3)
				{
					D[i]->printinfo();
				}
			}
		}
		cout << "Enter the DID you want to select " << endl;
		cin >> did;
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr && V[i]->get_sta())
			{
				V[i]->printinfo();
			}
		}
		cout << "Enter the registration no of the car to select the Vehical" << endl;
		int re;
		cin >> re;
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr)
			{
				if (V[i]->getid() == re)
				{
					V[i]->setstatusbook();
					sid = V[i]->getid();
				}
			}
		}
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getid() == did)
				{
					D[i]->setstatusbook();
					break;
				}
			}
		}
		for (int i = 0;i < 15;i++)
		{
			if (C[i] != nullptr)
			{
				if (C[i]->getid() == cid)
				{
					C[i]->sethistory1(noofpessengers, ridetype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
				}
			}
		}
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr)
			{
				if (V[i]->getid() == re)
				{
					V[i]->sethistory1(noofpessengers, ridetype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
				}
			}
		}
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getid() == did)
				{
					D[i]->sethistory1(noofpessengers, ridetype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
					break;
				}
			}
		}
		cout << "Your Fare is :" << distance * 15 << " RS" << endl;
	}
}
class Delivery :public service
{
public:
	Delivery();
	Delivery(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	~Delivery();
	void printserviceinfo();
	int getdis()
	{
		return distance;
	}
	void setservice(TMS** D, TMS** C, TMS** V);
	void destructor()
	{
		delete goodtype;
	}
private:
	float goodsweight;
	char* goodtype;
};
Delivery::Delivery()
{
	goodsweight = 0.0;
	goodtype = new char[30];
}
Delivery::Delivery(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	this->goodsweight = goodweight;
	this->goodtype = new char[30];
	int i = 0;
	for (;goodtype[i] != '\0';i++)
	{
		this->goodtype[i] = goodtype[i];
	}
	this->goodtype[i] = '\0';
	i = 0;
	for (;source[i] != '\0';i++)
	{
		this->source[i] = source[i];
	}
	this->source[i] = '\0';
	i = 0;
	for (;destination[i] != '\0';i++)
	{
		this->destination[i] = destination[i];
	}
	this->destination[i] = '\0';
	this->distance = distance;
	this->fuelrate = fuelrate;
	this->cid = cid;
	this->vid = vid;
	this->did = did;
	this->sid = sid;
	this->bookingdate = obj;
}
Delivery::~Delivery()
{
}
void Delivery::setservice(TMS** D, TMS** C, TMS** V)
{
	bool flag = false;
	int check = 0;
	cout << "Customer ID:" << endl;
	cin >> cid;
	for (int i = 0;i < 15;i++)
	{
		if (C[i]->getid() == cid)
		{
			flag = true;
			check = i;
			break;
		}
	}
	if (flag == true)
	{
		cout << "Destination:" << endl;
		cin.ignore();
		cin.get(destination, 10);
		cin.ignore();
		cout << "Source:" << endl;
		cin.ignore();
		cin.get(source, 10);
		cin.ignore();
		cout << "Distance:" << endl;
		cin >> distance;
		cout << "Booking Date:" << endl;
		cin >> bookingdate;
		cout << "Booking Time:" << endl;
		cin >> bookingtime;
		status = false;
		fuelrate = 106.6;
		cout << "GoodWeight:" << endl;
		cin >> goodsweight;
		cout << "GoodType:" << endl;
		cin.ignore();
		cin.get(goodtype, 30);
		cin.ignore();
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getstatus() == 1 || D[i]->getstatus() == 3)
				{
					D[i]->printinfo();
				}
			}
		}
		cout << "Enter the DID you want to select " << endl;
		cin >> did;
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr && V[i]->get_sta())
			{
				V[i]->printinfo();
			}
		}
		cout << "Enter the registration no of the car to select the Vehical" << endl;
		int re;
		cin >> re;
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr)
			{
				if (V[i]->getid() == re)
				{
					V[i]->setstatusbook();
					sid = V[i]->getid();
					break;
				}
			}
		}
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getid() == did)
				{
					D[i]->setstatusbook();
					break;
				}
			}
		}
		for (int i = 0;i < 15;i++)
		{
			if (C[i] != nullptr)
			{
				if (C[i]->getid() == cid)
				{
					C[i]->sethistory(goodsweight, goodtype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
				}
			}
		}
		for (int i = 0;i < 20;i++)
		{
			if (V[i] != nullptr)
			{
				if (V[i]->getid() == re)
				{
					V[i]->sethistory(goodsweight, goodtype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
				}
			}
		}
		for (int i = 0;i < 10;i++)
		{
			if (D[i] != nullptr)
			{
				if (D[i]->getid() == did)
				{
					D[i]->sethistory(goodsweight, goodtype, source, destination, distance, fuelrate, cid, did, re, sid, bookingdate);
				}
			}
		}
		cout << "Your Fare is :" << distance * 15 << " RS" << endl;;
	}
}
void Delivery::printserviceinfo()
{
	cout << "Source: " << source << endl;
	cout << "Destination: " << destination << endl;
	cout << "Distance: " << distance << endl;
	cout << "Status:" << status << endl;
	cout << "Fuel Price: " << fuelrate << endl;
	cout << "Customer ID: " << cid << endl;
	cout << "Ridetype: " << goodtype << endl;
	cout << "Weight: " << goodsweight << endl;
	cout << endl << endl;
}
class person :public TMS
{
public:
	person();
	~person();
	friend ostream& operator<<(ostream& out, const person& obj);
	virtual void setinitials(int g) {
	}
	virtual void getintials() {

	}
	virtual void readintials() {


	}
	virtual void writeupdated()
	{

	}
	virtual void setstatusbook()
	{

	}
	virtual void setstatuscancel()
	{

	}
protected:
	date DOB;
	int age;
	int nid;
	name pname;
};
ostream& operator<<(ostream& out, const person& obj)
{
	out << "Name:" << obj.pname << endl;
	out << "Date Of Birth:" << obj.DOB << endl;
	out << "Age:" << obj.age << endl;
	out << "Nid:" << obj.nid << endl;
	return out;
}
person::person()
{
	age = 0;
	nid = (rand() % 10000) + 1000;
}
person::~person()
{
}
class Customer :public person
{
public:
	Customer(int c, date dob, char a[], int k);
	Customer();
	~Customer();
	void setinitials(int g);
	void readintials();
	void setcustomerid();
	void printinfo();
	int getid();
	void sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	void gethistory();
	void sethistory1(int noofpeople, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	void getuserhistory(TMS** D, TMS** V);
	void cancelservice(TMS** D, TMS** V);
	void filehis(service* po);
	bool samevehical(int a);
	void destructor()
	{
		for (int i = 0;i < 50;i++)
		{
			bookinghistory[i] = nullptr;
			delete[]bookinghistory[i];
		}
		delete[] bookinghistory;
		//pname.destructor();
	}
private:
	int cid;
	service** bookinghistory;
};
Customer::Customer(int c, date dob, char a[], int k)
{
	cid = c;
	DOB = dob;
	pname = a;
	age = k;
	bookinghistory = new service * [50];
	for (int i = 0;i < 50;i++)
	{
		bookinghistory[i] = new service[1];
	}
	for (int i = 0;i < 50;i++)
	{
		bookinghistory[i] = nullptr;
	}
}
bool Customer::samevehical(int a)
{
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] != nullptr)
		{
			if (bookinghistory[i]->getvod() == a)
			{
				return true;
			}
		}
	}
	return false;
}
void Customer::filehis(service* po)
{
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] == nullptr)
		{
			bookinghistory[i] = po;
			break;
		}
	}
}
void Customer::cancelservice(TMS** D, TMS** V)
{
	int dod = 0;
	int vod = 0;
	int d;
	cout << "Enter the Service id which is same as the Registration no of the car" << endl;
	int sd;
	cin >> sd;
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] != nullptr)
		{
			if (bookinghistory[i]->getsid() == sd)
			{
				bookinghistory[i]->setstatusofride();
				dod = bookinghistory[i]->getdid();
				vod = bookinghistory[i]->getvod();
				d = bookinghistory[i]->getdis();
				cout << "The Ride has been Successfully Cancelled" << endl;
				cout << "Your Fare is: " << (d * 15) * 0.15 << endl;
				break;
			}
		}
	}
	//for (int i = 0;i < 20;i++)
	//{
	//	if (V[i] != nullptr)
	//	{
	//		if (V[i]->getid() == vod)
	//		{
	//			V[i]->setoverallranking();
	//			break;
	//		}
	//	}
	//}
	for (int i = 0;i < 10;i++)
	{
		if (D[i] != nullptr)
		{
			if (D[i]->getid() == dod)
			{
				D[i]->setstatuscancel();
				D[i]->setcancelationhistory(sd);
				break;
			}
		}
	}
}
void Customer::getuserhistory(TMS** D, TMS** V)
{
	int dod = 0;
	int vod = 0;
	cout << "Enter the Service id which is same as the Registration no of the car" << endl;
	int sd;
	cin >> sd;
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] != nullptr)
		{
			if (bookinghistory[i]->getsid() == sd)
			{
				bookinghistory[i]->setstatusofride();
				dod = bookinghistory[i]->getdid();
				vod = bookinghistory[i]->getvod();
				break;
			}
		}
	}
	for (int i = 0;i < 20;i++)
	{
		if (V[i] != nullptr)
		{
			if (V[i]->getid() == vod)
			{
				V[i]->setoverallranking();
				break;
			}
		}
	}
	for (int i = 0;i < 10;i++)
	{
		if (D[i] != nullptr)
		{
			if (D[i]->getid() == dod)
			{
				D[i]->setoverallranking();
				break;
			}
		}
	}
}
void Customer::gethistory()
{
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] != nullptr)
		{
			bookinghistory[i]->printserviceinfo();
		}
	}
}
void Customer::sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	int check = 0;
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] == nullptr)
		{
			bookinghistory[i] = new Delivery(goodweight, goodtype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			check = 1;
			break;
		}
	}
	if (check == 1)
	{
		cout << "The Delivery has succesfully booked" << endl;
		fstream obj1;
		obj1.open("CustomerHistory.txt", ios::app);
		if (obj1)
		{
			obj1 << goodweight << "," << goodtype << "," << source << "," << destination << "," << distance << "," << cid << "," << did << "," << vid << "," << sid << "," << obj << "\n";
		}
		obj1.close();
	}
	else
	{
		cout << "The Delivery has an error is booking" << endl;
	}
}
void Customer::sethistory1(int noofpeople, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	int check = 0;
	for (int i = 0;i < 50;i++)
	{
		if (bookinghistory[i] == nullptr)
		{
			bookinghistory[i] = new Ride(noofpeople, ridetype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			check = 1;
			break;

		}
	}
	if (check == 1)
	{
		cout << "The Delivery has succesfully booked" << endl;
		fstream obj1;
		obj1.open("CustomerHistory1.txt", ios::app);
		if (obj1)
		{
			obj1 << noofpeople << "," << ridetype << "," << source << "," << destination << "," << distance << "," << cid << "," << did << "," << vid << "," << sid << "," << obj<<"\n";
		}
		obj1.close();
	}
	else
	{
		cout << "The Delivery has an error in booking" << endl;
	}
}
int Customer::getid()
{
	return cid;
}
void Customer::printinfo()
{
	cout << "Name: " << pname << endl;
	cout << "Customer ID: " << cid << endl;
	cout << "Date Of Birth: " << DOB << endl;
	cout << "Age: " << age << endl;
	cout << endl;
}
Customer::Customer()
{
	cid = 0;
	age = 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bookinghistory = new service * [12];
	for (int i = 0;i < 12;i++)
	{
		bookinghistory[i] = new service[days[i]];
	}
}
void Customer::setcustomerid()
{
	cout << "Enter the cid between 0-9" << endl;
	cin >> cid;
}
Customer::~Customer()
{
}
void Customer::setinitials(int g)
{
	fstream obj;
	cout << "Name: " << endl;
	cin >> pname;
	cout << "Date Of Brith:" << endl;
	cin >> DOB;
	cout << "Customer ID:" << endl;
	cin >> cid;
	cout << "Age:" << endl;
	cin >> age;
	obj.open("customers.txt", ios::app);
	obj << pname << "," << DOB << "," << cid << "," << age << "\n";
	obj.close();
}
void Customer::readintials()
{

}
class Driver :public person
{
public:
	Driver();
	Driver(int age, int DID, int lino, int sal, int exper, date dob, char a[], char** s);
	~Driver();
	void setinitials(int g);
	void printinfo();
	int getid();
	int getstatus()
	{
		return status;
	}
	int getliecencecount();
	void setstatusbook()
	{
		status = 2;
	}
	void setstatuscancel()
	{
		status = 3;
	}
	void setoverallranking()
	{
		cout << "Rate your driver" << endl;
		cin >> overallranking;
		salary = (salary + ((((overallranking) / 100)) * salary));
	}
	float getoverallranking()
	{
		return overallranking;
	}
	float getsalary()
	{
		return salary;
	}
	void destructor()
	{
		for (int i = 0;i < 50;i++)
		{
			servicehistoryofdriver[i] = nullptr;
			delete[] servicehistoryofdriver[i];
		}
		delete[]servicehistoryofdriver;
		for (int i = 0;i < nooflicences;i++)
		{
			licenceslist[i] = nullptr;
			delete[] licenceslist[i];
		}
		delete[] licenceslist;
		//pname.destructor();
	}
	void filehis(service* p);
	void filewriting(fstream& obj);
	void gethistory();
	void setcancelationhistory(int id);
	void pen_ser_petd(int day, int month, int year);
	void p_d_ups();
	void sethistory1(int noofpeo, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	void sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
private:
	int did;
	char** licenceslist;
	int nooflicences;
	float overallranking;
	float salary;
	int experiences;
	int status;
	service** servicehistoryofdriver;
};
void Driver::p_d_ups()
{
	cout << "Name: " << pname << endl;
	cout << "Salary: " << salary << endl;
	cout << endl << endl;
}
Driver::Driver()
{
	did = 0;
	overallranking = 0.0;
	nooflicences = 1;
	salary = 0;
	experiences = 0;
	status = 1;
	licenceslist = new char* [nooflicences];
	for (int i = 0;i < nooflicences;i++)
	{
		licenceslist[i] = new char[50];
	}
	servicehistoryofdriver = new service * [50];
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0;i < 50;i++)
	{
		servicehistoryofdriver[i] = new service[1];
	}
	for (int i = 0;i < 50;i++)
	{
		servicehistoryofdriver[i] = nullptr;
	}
}
void Driver::filehis(service* p)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] == nullptr)
		{
			servicehistoryofdriver[i] = p;
			break;
		}
	}
}
void Driver::pen_ser_petd(int day, int month, int year)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] != nullptr)
		{
			if (!servicehistoryofdriver[i]->getservicestatus())
			{
				if (day == servicehistoryofdriver[i]->getbookdate_obj1() && month == servicehistoryofdriver[i]->getbookdate_obj3() && year == servicehistoryofdriver[i]->getbookdate_obj2())
				{
					servicehistoryofdriver[i]->printserviceinfo();
				}

			}
		}
	}
}
void Driver::setcancelationhistory(int ID)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] != nullptr)
		{
			if (servicehistoryofdriver[i]->getsid() == ID)
			{
				servicehistoryofdriver[i] = nullptr;
				break;
			}
		}
	}
}
void Driver::gethistory()
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] != nullptr)
		{
			if (!servicehistoryofdriver[i]->getservicestatus())
			{
				servicehistoryofdriver[i]->printserviceinfo();
			}
		}
	}
}
int Driver::getliecencecount()
{
	return nooflicences;
}
int Driver::getid()
{
	return did;
}
void Driver::printinfo()
{
	cout << "Name: " << pname << endl;
	cout << "Driver ID: " << did << endl;
	cout << "Salary: " << salary << endl;
	cout << "Experiences: " << experiences << endl;
	cout << "Age: " << age << endl;
	cout << "Date Of Brith: " << DOB << endl;
	cout << "Liecence List: " << endl;
	for (int i = 0;i < nooflicences;i++)
	{
		cout <<(i+1)<<"-> "<< licenceslist[i] << endl;
	}
	cout << "Salary: " << salary << endl;
	cout << endl;
}
Driver::Driver(int age, int DID, int lino, int sal, int exper, date dob, char a[], char** s)
{
	did = DID;
	overallranking = 0.0;
	nooflicences = lino;
	salary = sal;
	experiences = exper;
	status = 1;
	licenceslist = new char* [nooflicences];
	pname = a;
	this->age = age;
	DOB = dob;
	for (int i = 0;i < nooflicences;i++)
	{
		licenceslist[i] = new char[50];
	}
	for (int i = 0;i < nooflicences;i++)
	{
		int j = 0;
		for (;s[i][j] != '\0';j++)
		{
			licenceslist[i][j] = s[i][j];
		}
		licenceslist[i][j] = '\0';
	}
	servicehistoryofdriver = new service * [50];
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0;i < 50;i++)
	{
		servicehistoryofdriver[i] = new service[1];
	}
	for (int i = 0;i < 50;i++)
	{
		servicehistoryofdriver[i] = nullptr;
	}
}
Driver::~Driver()
{
}
void Driver::sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] == nullptr)
		{
			servicehistoryofdriver[i] = new Delivery(goodweight, goodtype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			break;
		}
	}
}
void Driver::sethistory1(int noofpeo, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistoryofdriver[i] == nullptr)
		{
			servicehistoryofdriver[i] = new Ride(noofpeo, ridetype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			break;
		}
	}
}
void Driver::setinitials(int g)
{
	fstream obj;
	cout << "Name:" << endl;
	cin >> pname;
	cout << "Date Of Birth:" << endl;
	cin >> DOB;
	cout << "Age:" << endl;
	cin >> age;
	cout << "Number Of Licences: " << endl;
	cin >> nooflicences;
	cout << "Salary: " << endl;
	cin >> salary;
	cout << "Experiences: " << endl;
	cin >> experiences;
	cout << "Drivers ID:" << endl;
	cin >> did;
	licenceslist = new char* [nooflicences];
	for (int i = 0;i < nooflicences;i++)
	{
		licenceslist[i] = new char[50];
	}
	cout << "Licence List:" << endl;
	for (int i = 0;i < nooflicences;i++)
	{
		cout << "Enter your liecencetype" << endl;
		cin.ignore();
		cin.get(licenceslist[i], 50);
	}
	obj.open("Drivers.txt", ios::app);
	if (obj)
	{
		obj << "\n";
		obj << pname << "," << DOB << "," << age << "," << nooflicences << "," << salary << "," << experiences << "," << did;
		obj << ",";
		for (int i = 0;i < nooflicences;i++)
		{
			obj << licenceslist[i] << ",";
		}
	}
	obj.close();
}
void Driver::filewriting(fstream& obj)
{
	obj << pname << "," << DOB << "," << age << "," << nooflicences << "," << salary << "," << experiences << "," << did;
	obj << ",";
	for (int i = 0;i < nooflicences;i++)
	{
		obj << licenceslist[i] << ",";
	}
	obj << "\n";
}
class feature :public TMS
{
public:
	feature();
	feature(int fid, float cost, char* description);
	~feature();
	void setfeatures();
	feature operator=(feature& obj)
	{
		int i = 0;
		this->fid = obj.fid;
		this->cost = obj.cost;
		for (;description[i] != '\0';i++)
		{
			this->description[i] = obj.description[i];
		}
		this->description[i];
		return *this;
	}
	friend ostream& operator<<(ostream& output, feature& obj)
	{
		output << "Feature ID: " << obj.fid << endl;
		output << "Vehical Cost: " << obj.cost << endl;
		output << obj.description;
		return output;
	}
	void writefeatures(fstream& obj)
	{
		obj << fid << "," << description << "," << cost << ",\n";
	}

private:
	int fid;
	char* description;
	float cost;
};
feature::feature()
{
	fid = 0;
	description = new char[50];
	cost = 0.0;
}
feature::feature(int fid, float cost, char* description)
{
	this->fid = fid;
	this->cost = cost;
	int i = 0;
	this->description = new char[50];
	for (;description[i] != '\0';i++)
	{
		this->description[i] = description[i];
	}
	this->description[i] = description[i] = '\0';
}
void feature::setfeatures()
{
	cout << "Feature ID" << endl;
	cin >> fid;
	cout << "Description Of Car:" << endl;
	cin.ignore();
	cin.getline(description, 50);
	cout << "Cost OF Car:" << endl;
	cin >> cost;
	fstream obj;
	obj.open("Vehical.txt", ios::app);
	if (obj)
	{
		obj << fid << "," << description << "," << cost << ",\n";
	}
	obj.close();
}
feature::~feature()
{
}
class Vehical :public TMS
{
public:
	Vehical();
	Vehical(int vid1, int reg, int avg, char li[], char fu[], date& obj, feature& obj1)
	{
		vid = 0;
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		registrationnumber = 0;
		avgmileage = 60;
		licencetype = new char[10];
		status = false;
		fueltype = new char[50];
		overallranking = 0.0;
		servicehistory = new service * [50];
		for (int i = 0;i < 50;i++)
		{
			servicehistory[i] = new service[1];
		}
		for (int i = 0;i < 50;i++)
		{
			servicehistory[i] = nullptr;
		}
		vid = vid1;
		registrationnumber = reg;
		avgmileage = avg;
		int i = 0;
		for (;li[i] != '\0';i++)
		{
			licencetype[i] = li[i];
		}
		licencetype[i] = '\0';
		i = 0;
		for (;fu[i] != '\0';i++)
		{
			fueltype[i] = fu[i];
		}
		fueltype[i] = '\0';
		manufacturingdate = obj;
		list = obj1;
	}
	void filehis(service* p);
	void setstatuscancel()
	{
		status = false;
	}
	void sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	void sethistory1(int noofpeo, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj);
	~Vehical();
	void setlist(feature& list1);
	void addavehical();
	void printinfo();
	int getid();
	bool get_sta();
	void gethistory();
	void setstatusbook()
	{
		status = true;
	}
	void setoverallranking()
	{
		cout << "Rate your vehical" << endl;
		cin >> overallranking;
	}
	void filewriting(fstream& obj);
	void destructor()
	{
		for (int i = 0;i < 50;i++)
		{
			servicehistory[i] = nullptr;
			delete[] servicehistory[i];
		}
		delete[] servicehistory;
	}
private:
	int vid;
	int registrationnumber;
	int avgmileage;
	char* licencetype;
	bool status;
	char* fueltype;
	float overallranking;
	date manufacturingdate;
	feature list;
	service** servicehistory;
};
bool Vehical::get_sta()
{
	if (status)
	{
		return false;
	}
	else
	{
		return true;
	}
}
Vehical::Vehical()
{
	vid = 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	registrationnumber = 0;
	avgmileage = 60;
	licencetype = new char[10];
	status = false;
	fueltype = new char[50];
	overallranking = 0.0;
	servicehistory = new service * [50];
	for (int i = 0;i < 50;i++)
	{
		servicehistory[i] = new service[1];
	}
	for (int i = 0;i < 50;i++)
	{
		servicehistory[i] = nullptr;
	}
}
void Vehical::filewriting(fstream& obj)
{
	obj << vid << "," << registrationnumber << "," << avgmileage << "," << licencetype << "," << fueltype << "," << manufacturingdate << ",";
	list.writefeatures(obj);
}
int Vehical::getid()
{
	return registrationnumber;
}
void Vehical::filehis(service* p)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistory[i] == nullptr)
		{
			servicehistory[i] = p;
			break;
		}
	}
}
void Vehical::gethistory()
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistory[i] != nullptr)
		{
			servicehistory[i]->printserviceinfo();
		}
	}
}
void Vehical::sethistory(float goodweight, char goodtype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistory[i] == nullptr)
		{
			servicehistory[i] = new Delivery(goodweight, goodtype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			break;
		}
	}
}
void Vehical::sethistory1(int noofpeo, char ridetype[], char source[], char destination[], float distance, float fuelrate, int cid, int did, int vid, int sid, date& obj)
{
	for (int i = 0;i < 50;i++)
	{
		if (servicehistory[i] == nullptr)
		{
			servicehistory[i] = new Ride(noofpeo, ridetype, source, destination, distance, fuelrate, cid, did, vid, sid, obj);
			break;
		}
	}
}
void Vehical::addavehical()
{
	fstream objveh;
	cout << "Vehical ID:" << endl;
	cin >> vid;
	cout << "Registration Number: " << endl;
	cin >> registrationnumber;
	cout << "Average Milage:" << endl;
	cin >> avgmileage;
	cout << "Liecence Type :" << endl;
	cin.ignore();
	cin.get(licencetype, 10);
	cout << "Fuel Type:" << endl;
	cin.ignore();
	cin.get(fueltype, 50);
	cout << "Manufacturing Date: " << endl;
	cin >> manufacturingdate;
	cout << "Features OF The Vehical: " << endl;
	objveh.open("Vehical.txt", ios::app);
	if (objveh)
	{
		objveh << vid << "," << registrationnumber << "," << avgmileage << "," << licencetype << "," << fueltype << "," << manufacturingdate << ",";
	}
	objveh.close();
	list.setfeatures();
}
void Vehical::printinfo()
{
	cout << "Vehical ID: " << vid << endl;
	cout << "Registration Numebr: " << registrationnumber << endl;
	cout << "Average Milage: " << avgmileage << endl;
	cout << "Licence Required: " << licencetype << endl;
	cout << "Fuel Type: " << fueltype << endl;
	cout << "Manufacturing Date: " << manufacturingdate << endl;
	cout << "Feature: " << list << endl;
	cout << endl;
}
Vehical::~Vehical()
{
}
void CUR_SOR(int rows, int cols)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cur_p;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	cur_p.X = cols;
	cur_p.Y = rows;
	SetConsoleCursorPosition(hOutput, cur_p);
}
int main()
{
	int pref_, g = 0, h1 = 0, op = 0, h = 0;
	fstream cobj, readfile, readfiledrivers;
	fstream np;
	TMS** drivers;
	TMS** customers;
	TMS** ride;
	TMS** delivery;
	TMS** vehical;
	service** readhistoryd;
	service** readhistoryR;
	readhistoryd = new service * [100];
	for (int i = 0;i < 100;i++)
	{
		readhistoryd[i] = new service[1];
	}
	for (int i = 0;i < 100;i++)
	{
		readhistoryd[i] = nullptr;
	}
	readhistoryR = new service * [100];
	for (int i = 0;i < 100;i++)
	{
		readhistoryR[i] = new service[1];
	}
	for (int i = 0;i < 100;i++)
	{
		readhistoryR[i] = nullptr;
	}
	vehical = new TMS * [20];
	for (int i = 0;i < 20;i++)
	{
		vehical[i] = new TMS[1];
	}
	for (int i = 0;i < 20;i++)
	{
		vehical[i] = nullptr;
	}
	drivers = new TMS * [10];
	for (int i = 0;i < 10;i++)
	{
		drivers[i] = new TMS[1];
	}
	for (int i = 0;i < 10;i++)
	{
		drivers[i] = nullptr;
	}
	customers = new TMS * [15];
	for (int i = 0;i < 15;i++)
	{
		customers[i] = new TMS[1];
	}
	for (int i = 0;i < 15;i++)
	{
		customers[i] = nullptr;
	}
	delivery = new TMS * [100];
	for (int i = 0;i < 100;i++)
	{
		delivery[i] = new TMS[1];
	}
	for (int i = 0;i < 100;i++)
	{
		delivery[i] = nullptr;
	}
	ride = new TMS * [100];
	for (int i = 0;i < 100;i++)
	{
		ride[i] = new TMS[1];
	}
	for (int i = 0;i < 100;i++)
	{
		ride[i] = nullptr;
	}
	fstream objcount, obj;
	obj.open("Vehical.txt", ios::in);
	if (obj)
	{
		int objh=0;
		objcount.open("vehicalobjectcount.txt", ios::in);
		objcount >> objh;
		op = objh;
		objcount.close();
		char vehicaldata[500];
		while (obj.getline(vehicaldata, 500))
		{
			int i = 0, month = 0, day = 0, year = 0, vid = 0, reg = 0, avgmile = 0, fid = 0, cost = 0;
			char liecencety[40], fuelty[40];
			for (;vehicaldata[i] != ',';i++)
			{
				vid = (vid * 10) + (vehicaldata[i] - 48);
			}
			i++;
			for (;vehicaldata[i] != ',';i++)
			{
				reg = (reg * 10) + (vehicaldata[i] - 48);
			}
			i++;
			for (;vehicaldata[i] != ',';i++)
			{
				avgmile = (avgmile * 10) + (vehicaldata[i] - 48);
			}
			i++;
			int j = 0;
			for (;vehicaldata[i] != ',';i++, j++)
			{

				liecencety[j] = vehicaldata[i];
			}
			liecencety[j] = '\0';
			i++;
			j = 0;
			for (;vehicaldata[i] != ',';i++, j++)
			{
				fuelty[j] = vehicaldata[i];
			}
			fuelty[j] = '\0';
			i++;
			for (;vehicaldata[i] != '/';i++)
			{
				day = (day * 10) + (vehicaldata[i] - 48);
			}
			i++;
			for (;vehicaldata[i] != '/';i++)
			{
				month = (month * 10) + (vehicaldata[i] - 48);
			}
			i++;
			for (;vehicaldata[i] != ',';i++)
			{
				year = (year * 10) + (vehicaldata[i] - 48);
			}
			i++;
			for (;vehicaldata[i] != ',';i++)
			{
				fid = (fid * 10) + (vehicaldata[i] - 48);
			}
			i++;
			char* p;
			p = new char[50];
			j = 0;
			for (;vehicaldata[i] != ',';i++, j++)
			{
				p[j] = vehicaldata[i];
			}
			p[j] = '\0';
			i++;
			for (;vehicaldata[i] != ',';i++)
			{
				cost = (cost * 10) + (vehicaldata[i] - 48);
			}
			feature nw(fid, cost, p);
			date kj(day, month, year);
			vehical[objh] = new Vehical(vid, reg, avgmile, liecencety, fuelty, kj, nw);
			objh--;
		}
	}
	obj.close();
	fstream obj_count;int d=0;
	obj_count.open("Customerobjcoun.txt", ios::in);
	obj_count >> d;
	int jl = d;
	obj_count.close();
	readfile.open("Customers.txt", ios::in);
	char fname[100];
	if (readfile)
	{
		char data[100];
		while (readfile.getline(data, 100))
		{
			int month = 0, day = 0, year = 0, ag_e = 0, g = 0;
			int i = 0;
			for (;data[i] != ' ';i++)
			{
				fname[i] = data[i];
			}
			fname[i] = ' ';
			i++;
			for (;data[i] != ',';i++)
			{
				fname[i] = data[i];
			}
			fname[i] = '\0';
			i++;
			for (;data[i] != '/';i++)
			{
				month = (month * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != '/';i++)
			{
				day = (day * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				year = (year * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				g = (g * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != '\0';i++)
			{
				ag_e = (ag_e * 10) + (data[i] - 48);
			}
			date dob(day, month, year);

			customers[jl] = new Customer(g, dob, fname, ag_e);
			jl--;
		}
	}
	readfile.close();
	readfiledrivers.open("Drivers.txt", ios::in);
	fstream dvobj;
	int dvj=0;
	dvobj.open("Driversobjcount.txt", ios::in);
	dvobj >> dvj;
	h1 = dvj;
	dvobj.close();
	if (readfiledrivers)
	{
		char data[100];
		while (readfiledrivers.getline(data, 100))
		{
			int month = 0, day = 0, year = 0, ag_e = 0, noli = 0;int sal = 0, exp = 0;
			int i = 0;
			h = 0;
			for (;data[i] != ' ';i++)
			{
				fname[i] = data[i];
			}
			fname[i] = ' ';
			i++;
			for (;data[i] != ',';i++)
			{
				fname[i] = data[i];
			}
			fname[i] = '\0';
			i++;
			for (;data[i] != '/';i++)
			{
				day = (day * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != '/';i++)
			{
				month = (month * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				year = (year * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				ag_e = (ag_e * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				noli = (noli * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				sal = (sal * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				exp = (exp * 10) + (data[i] - 48);
			}
			i++;
			for (;data[i] != ',';i++)
			{
				h = (h * 10) + (data[i] - 48);
			}
			char** lilis;
			lilis = new char* [noli];
			for (int l = 0;l < noli;l++)
			{
				lilis[l] = new char[50];
			}
			i++;
			for (int o = 0;o < noli;o++)
			{
				int k = 0;
				for (;data[i] != ',' && data[i] != '\0';k++, i++)
				{
					lilis[o][k] = data[i];
				}
				lilis[o][k] = '\0';
				i++;
			}
			i++;
			date dob(day, month, year);
			drivers[dvj] = new Driver(ag_e, h, noli, sal, exp, dob, fname, lilis);
			dvj--;
		}
	}
	readfiledrivers.close();
	np.open("CustomerHistory.txt", ios::in);
	if (np)
	{
		char his_data[100];
		int qw = 0;
		while (np.getline(his_data, 100))
		{
			int i = 0;
			int j = 0;
			int weight = 0, cid = 0, did = 0, vid = 0, sid = 0, day = 0, mon = 0, year = 0, dis = 0;
			char goodtype[50], source[50], destiny[50];
			for (;his_data[i] != ',';i++)
			{
				weight = (weight * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != ',';i++,j++)
			{
				goodtype[j] = his_data[i];
			}
			goodtype[j] = '\0';
			i++;
			for (j = 0;his_data[i] != ',';i++, j++)
			{
				source[j] = his_data[i];
			}
			source[j] = '\0';
			i++;
			for (j = 0;his_data[i] != ',';i++, j++)
			{
				destiny[j] = his_data[i];
			}
			destiny[j] = '\0';
			i++;
			for (;his_data[i] != ',';i++)
			{
				dis = (dis * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != ',';i++)
			{
				cid = (cid * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != ',';i++)
			{
				did= (did * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != ',';i++)
			{
				vid = (vid * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != ',';i++)
			{
				sid = (sid * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != '/';i++)
			{
				day = (day * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != '/';i++)
			{
				mon = (mon * 10) + (his_data[i] - 48);
			}
			i++;
			for (;his_data[i] != '\0';i++)
			{
				year = (year * 10) + (his_data[i] - 48);
			}
			double fuelrate = 180.566;
			date lk(day, mon, year);
			readhistoryd[qw] = new Delivery (weight,goodtype,source,destiny,dis,fuelrate,cid,did,vid,sid,lk);
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->getid() == cid)
					{
						customers[i]->filehis(readhistoryd[qw]);
						break;
					}
				}
			}
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getid() == did)
					{
						drivers[i]->filehis(readhistoryd[qw]);
						break;
					}
				}
			}
			for (int i = 0;i < 20;i++)
			{
				if (vehical[i] != nullptr)
				{
					if (vehical[i]->getid() == vid)
					{
						vehical[i]->filehis(readhistoryd[qw]);
						break;
					}
				}
			}

			qw++;
		}
	}
	np.close();
	fstream al;
	al.open("CustomerHistory1.txt", ios::in);
	if (al)
	{
		int qw = 0;
		char newdata[100];
		while (al.getline(newdata, 100))
		{
			int i = 0;
			int j = 0;
			int weight = 0, cid = 0, did = 0, vid = 0, sid = 0, day = 0, mon = 0, year = 0, dis = 0;
			char goodtype[50], source[50], destiny[50];
			for (;newdata[i] != ',';i++)
			{
				weight = (weight * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != ',';i++, j++)
			{
				goodtype[j] = newdata[i];
			}
			goodtype[j] = '\0';
			i++;
			for (j = 0;newdata[i] != ',';i++, j++)
			{
				source[j] = newdata[i];
			}
			source[j] = '\0';
			i++;
			for (j = 0;newdata[i] != ',';i++, j++)
			{
				destiny[j] = newdata[i];
			}
			destiny[j] = '\0';
			i++;
			for (;newdata[i] != ',';i++)
			{
				dis = (dis * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != ',';i++)
			{
				cid = (cid * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != ',';i++)
			{
				did = (did * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != ',';i++)
			{
				vid = (vid * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != ',';i++)
			{
				sid = (sid * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != '/';i++)
			{
				day = (day * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != '/';i++)
			{
				mon = (mon * 10) + (newdata[i] - 48);
			}
			i++;
			for (;newdata[i] != '\0';i++)
			{
				year = (year * 10) + (newdata[i] - 48);
			}
			double fuelrate = 180.566;
			date lk(day, mon, year);
			readhistoryR[qw] = new Ride(weight,goodtype,source,destiny,dis,fuelrate,cid,did,vid,sid,lk);
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->getid() == cid)
					{
						customers[i]->filehis(readhistoryR[qw]);
						break;
					}
				}
			}
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getid() == did)
					{
						drivers[i]->filehis(readhistoryR[qw]);
						break;
					}
				}
			}
			for (int i = 0;i < 20;i++)
			{
				if (vehical[i] != nullptr)
				{
					if (vehical[i]->getid() == vid)
					{
						vehical[i]->filehis(readhistoryR[qw]);
						break;
					}
				}
			}
			qw++;
		}
	}
	al.close();
	int program = 1;
	while (program==1)
	{
		menu();
		cin >> pref_;
		if (pref_ == 1)
		{
			system("cls");
			if (d != 0)
			{
				d++;
			}
			fstream customerobjectcount;
			cout << "In this choice you will going to sign up" << endl;
			customers[d] = new Customer;
			customers[d]->setinitials(d);
			customerobjectcount.open("Customerobjcoun.txt", ios::out);
			if (customerobjectcount)
			{
				customerobjectcount << d;
			}
			customerobjectcount.close();
		}
		if (pref_ == 2)
		{
			system("cls");
			if (h1 != 0)
			{
				h1++;
			}
			fstream diversobjectcount;
			cout << "In this choice you will be going to add a new driver" << endl;
			drivers[h1] = new Driver;
			diversobjectcount.open("Driversobjcount.txt", ios::out);
			if (diversobjectcount)
			{
				diversobjectcount << h1;
			}
			drivers[h1]->setinitials(h1);
			diversobjectcount.close();
		}
		if (pref_ == 3)
		{
			system("cls");
			if (op != 0)
			{
				op++;
			}
			fstream vehicalobjectcount;
			vehicalobjectcount.open("vehicalobjectcount.txt", ios::out);
			if (vehicalobjectcount)
			{
				vehicalobjectcount << op;
			}
			vehicalobjectcount.close();
			cout << "In this choice you are going to enter the vehical in the Transport management system " << endl;
			vehical[op] = new Vehical;
			vehical[op]->addavehical();
		}
		if (pref_ == 4)
		{
			system("cls");
			cout << "In this you will be geting the list of all the customers" << endl;
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					customers[i]->printinfo();
				}
			}
		}
		if (pref_ == 5)
		{
			system("cls");
			cout << "In this you will be geting the list of all the Drivers" << endl;
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					drivers[i]->printinfo();
				}
			}
		}
		if (pref_ == 6)
		{
			system("cls");
			for (int i = 0;i < 20;i++)
			{
				if (vehical[i] != nullptr)
				{
					vehical[i]->printinfo();
				}
			}
		}
		if (pref_ == 7)
		{
			system("cls");
			int re_g;
			cout << "Enter the Vehical Registration no " << endl;
			cin >> re_g;
			for (int i = 0;i < 20;i++)
			{
				if (vehical[i] != nullptr)
				{
					if (vehical[i]->getid() == re_g)
					{
						vehical[i]->gethistory();
					}
				}
			}
		}
		if (pref_ == 8)
		{
			system("cls");
			cout << "Enter the customer id" << endl;
			int x;
			cin >> x;
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->getid() == x)
					{
						customers[i]->gethistory();
					}
				}
			}
		}
		if (pref_ == 9)
		{
			system("cls");
			int d_d;
			cout << "Enter the Drivers Id" << endl;
			cin >> d_d;
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getid() == d_d)
					{
						drivers[i]->gethistory();
					}
				}
			}
		}
		if (pref_ == 10)
		{
			system("cls");
			cout << "In this choice you are getting the list of the drivers whose rating are more then 4.5" << endl;
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getoverallranking() >= 4.5)
					{
						drivers[i]->printinfo();
					}
				}
			}
		}
		if (pref_ == 13)
		{
			system("cls");
			int a, l = 0,k=0;
			cout << "Enter which type of ride you want " << endl;
			cout << "Press 1 for the Delivery service" << endl;
			cout << "Press 2 for the Ride service" << endl;
			cin >> a;
			if (a == 1)
			{
				delivery[k] = new Delivery;
				delivery[k]->setservice(drivers, customers, vehical);
			}
			else if (a == 2)
			{
				ride[k] = new Ride;
				ride[k]->setservice(drivers, customers, vehical);
			}
		}
		if (pref_ == 11)
		{
			system("cls");
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getliecencecount() >= 2)
					{
						drivers[i]->printinfo();
					}
				}
			}
		}
		if (pref_ == 12)
		{
			system("cls");
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					drivers[i]->p_d_ups();
				}
			}
		}
		if (pref_ == 18)
		{
			system("cls");
			int as;
			cout << "Enter the drivers id of which you want to get pending services" << endl;
			cin >> as;
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getid() == as)
					{
						drivers[i]->gethistory();
					}
				}
			}
		}
		if (pref_ == 15)
		{
			int v_id;
			cout << "Vehical ID or Registration Numeber" << endl;
			cin >> v_id;
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->samevehical(v_id))
					{
						customers[i]->printinfo();
					}
				}
			}
		}
		if (pref_ == 20)
		{
			system("cls");
			int divid;
			cout << "Enter the drivers id of the driver you want to delete" << endl;
			cin >> divid;
			bool flag = false;
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					if (drivers[i]->getid() == divid)
					{
						drivers[i] = nullptr;
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
			{
				cout << "The Driver is deleted " << endl;
				h1--;
				fstream file, filev;
				file.open("Driversobjcount.txt", ios::out);
				if (file)
				{
					file << h1;
				}
				file.close();
				filev.open("Drivers.txt", ios::out);
				if (filev)
				{
					for (int i = 0;i < 10;i++)
					{
						if (drivers[i] != nullptr)
						{
							drivers[i]->filewriting(filev);
						}
					}
				}
				filev.close();
			}
			else
			{
				cout << "The Driver not found" << endl;
			}
		}
		if (pref_ == 21)
		{
			system("cls");
			int reg;
			cout << "Enter the Registration number of the car you want to delete" << endl;
			cin >> reg;
			bool flag = false;
			for (int i = 0;i < 20;i++)
			{
				if (vehical[i] != nullptr)
				{
					if (vehical[i]->getid() == reg)
					{
						vehical[i] = nullptr;
						flag = true;
						break;
					}
				}
			}
			if (flag == true)
			{
				cout << "The Vehical is deleted " << endl;
				op--;
				fstream file, filev;
				file.open("vehicalobjectcount.txt", ios::out);
				if (file)
				{
					file << op;
				}
				file.close();
				filev.open("Vehical.txt", ios::out);
				if (filev)
				{
					for (int i = 0;i < 20;i++)
					{
						if (vehical[i] != nullptr)
						{
							vehical[i]->filewriting(filev);
						}
					}
				}
				filev.close();
			}
			else
			{
				cout << "The Vehical not found" << endl;
			}
		}
		if (pref_ == 14)
		{
			system("cls");
			cout << "In this choice you will be canceling the service " << endl;
			cout << "Enter Customer ID" << endl;
			int lk;
			cin >> lk;
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->getid() == lk)
					{
						customers[i]->cancelservice(drivers, vehical);
					}
				}
			}
		}
		if (pref_ == 17)
		{
			system("cls");
			int day = 0, month = 0, year = 0;
			while (day <= 0 || day > 31)
			{
				cout << "Day:";cin >> day;
			}
			cout << endl;
			while (month <= 0 || month > 12)
			{
				cout << "Month:";cin >> month;
			}
			cout << endl;
			while (year <= 0 || year > 3000)
			{
				cout << "Year:";cin >> year;
			}
			for (int i = 0;i < 10;i++)
			{
				if (drivers[i] != nullptr)
				{
					drivers[i]->pen_ser_petd(day, month, year);
				}
			}
		}
		if (pref_ == 22)
		{
			system("cls");
			cout << "Enter the customer ID of which you want to complete the Service " << endl;
			int kl;
			cin >> kl;
			for (int i = 0;i < 15;i++)
			{
				if (customers[i] != nullptr)
				{
					if (customers[i]->getid() == kl)
					{
						customers[i]->getuserhistory(drivers, vehical);
					}
				}
			}
		}
		cout << "Press 1 to continue or press 0 to terminate the Program " << endl;
		cin >> program;
		while (program != 1 && program != 0)
		{
			cout << "Enter the Valid Input" << endl;
			cout << "Press 1 to continue or press 0 to terminate the Program " << endl;
			cin >> program;
		}
	}
	for (int i = 0;i < 15;i++)
	{
		if (customers[i] != nullptr)
		{
			customers[i]->destructor();
		}
	}
	for (int i = 0;i < 10;i++)
	{
		if (drivers[i] != nullptr)
		{
			drivers[i]->destructor();
		}
	}
	for (int i = 0;i < 20;i++)
	{
		if (vehical[i] != nullptr)
		{
			vehical[i]->destructor();
		}
	}
	for (int i = 0;i < 10;i++)
	{
		drivers[i] = nullptr;
		delete[] drivers[i];
	}
	delete[] drivers;
	for (int i = 0;i < 20;i++)
	{
		vehical[i] = nullptr;
		delete[] vehical[i];
	}
	delete[] vehical;
	for (int i = 0;i < 15;i++)
	{
		customers[i] = nullptr;
		delete[] customers[i];
	}
	delete[] customers;
	for (int i = 0;i < 100;i++)
	{
		readhistoryd[i] = nullptr;
		delete[] readhistoryd[i];
	}
	delete[] readhistoryd;
	for (int i = 0;i < 100;i++)
	{
		readhistoryR[i] = nullptr;
		delete[] readhistoryR[i];
	}
	delete[] readhistoryR;
	for (int i = 0;i < 100;i++)
	{
		ride[i]=nullptr;
		delete[] ride[i];
	}
	delete[]ride;
	for (int i = 0;i < 100;i++)
	{
		delivery[i] = nullptr;
		delete[] delivery[i];
	}
	delete[] delivery;
	return 0;
}