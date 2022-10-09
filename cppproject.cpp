#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include <cstring>

#include<stdio.h>
using namespace std;
class filegenerate{                         //class for creating the file
public:
    filegenerate(){
        ofstream fout;
        fout.open("sayantan.txt");
        fout<<"sayantan";
        fout.close();
    }
};
class turnover{                             
        public:
        double gain;
        void show()
		{
		ifstream x("ooo.txt");                      //taking provide the of the file
        if(!x)
        cout<<"gain = 0 ";
        else{
        x>>gain;
        cout<<"\nTOTAL STARTING PROFIT:  "<<gain<<endl;           //the total profit initially
        x.close();
        }
        
        }

};
class product:public virtual turnover{
public:
           int quantity;
           char name[20];
           char id[20];
           double percostprice;
           double persellprice;
           double cost;
           double sell;
           void cal()                                         //function for calculation logics
		   {
		    cost=percostprice*quantity;                           //logic related to cost
        	sell=persellprice*quantity;                         //logic related to sell
            gain=gain +(sell-cost)*365;                       //logic related to gain
			}
           void filegenerate();                               //function to generate file
           void get();

};
void product::get()
{
 int s;
cout<<"\nnumber of products produced?\n";
cin>>s;
for(int i=0;i<s;i++)                                          //loop for counting number of products
{
  cout<<"\nprovide the product name: \n";
  cin>>name;
  cout<<"\nprovide the product id: \n";
  cin>>id;
  cout<<"\nprovide the cost price of product: \n";
  cin>>percostprice;
  cout<<"\nprovide the selling price of product: \n";
  cin>>persellprice;
  cout<<"\ntotal product quantitytity: \n";
  cin>>quantity;
    cal();
    filegenerate();
  }
 
}
void product::filegenerate()
{
char filegenerate[20];
strcpy(filegenerate,id);                                    //to copy the string
strcat(filegenerate,".txt");                                //to concatinate the string
ofstream f(filegenerate);                                   //to open and write in file
f<< "\nproduct name: "<<name<< "\nproduct id: "<<id<<"\ncost price of product: " <<percostprice<<"\nselling price of product: "<<persellprice<<"\nquantitytity: "<<quantity<<"\n total cost: "<<cost<<"\nsell: "<<sell;
f.close();
}

class employee:public virtual turnover{
         protected:
         double salary;
         char post[12];
         char empid[10];
         int postquantity;
         void cal()
         {
		 gain=(gain-salary*postquantity)*12;
         }
         void getemployee();
         void filegenerate();
};
void employee::getemployee()
{
  cout<<"\nprovide the salary: \n";
  cin>>salary;
  cout<<"\nprovide the number of employees: \n";
  cin>>postquantity;
  for(int i=0;i<postquantity;i++)                                       //loop for counting the number of employee
  {
  	cout<<"provide the employee name\n";
  	cin>>post;
  cout<<"\nprovide the employee ID\n";
  cin>>empid;
  cal();
  filegenerate();
}
}
 void employee::filegenerate()
{  char filegenerate[20];
strcpy(filegenerate,empid);
strcat(filegenerate,".txt");
ofstream f(filegenerate);
f<< "\nnumber of working employees: "<<postquantity<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
f.close();
}

class amount:public employee, public product
{

 public:
    void add();
    void update_item();
    void update_emp();

};
void amount::add()
{
	int ch;
	char name[20];
	while(1)
	{
		cout<<"1.)provide the for product\n2.)Input for employee\n3.)Exit\n";
		cout<<"Enter choice\n";
		cin>>ch;
		if(ch==1){
				get();
				ofstream x("ooo.txt");
 				x<<gain;
 				x.close();
			}
			else if(ch==2){
				getemployee();
				ofstream x("ooo.txt");
 				x<<gain;
 				x.close();
				}
			else if(ch==3)
				break;
			else
				cout<<"Invaid Option. Please re-enter\n";
			}
		}

 
	void amount::update_item()
	{
	char id[20];
	char pid[20];
    char c;
    cout<<"\nprovide the product ID to modify\n";
    cin>>id;
    char filegenerate[20];
    char filegenerate2[20];
    strcpy(filegenerate,id);
    strcat(filegenerate,".txt");
    fstream fout(filegenerate, ios::in|ios::out);
    if(!fout)
    {
    	cout<<"file couldn't be opened. product ID is Invalid. \n";
	}
	else {
	cout<<"file found! \n";
    cout<<"\nupdate product name: \n";
  	cin>>name;
 	cout<<"\nupdate percostprice of product: \n";
  	cin>>percostprice;
 	cout<<"\nupdate persellprice of product: \n";
  	cin>>persellprice;
 	cout<<"\nupdate total product quantity: \n";
 	cin>>quantity;
    cost=percostprice*quantity;
    sell=persellprice*quantity;
	gain=gain +(sell-cost)*365;
  	fout<<"\nproduct name: "<<name<< "\nproduct id: "<<id<<"\npercostprice ofproduct: " <<percostprice<<"\npersellprice of product: "<<persellprice<<"\nquantitytity: "<<quantity<<"\n total cost: "<<cost<<"\nsell: "<<sell;
	fout.close();
}
}
   void amount::update_emp()	
	{
	char id[20];
    char c;
    cout<<"\nprovide the employee ID to modify: ";
    cin>>id;
    char filegenerate[20];
    strcpy(filegenerate,id);
    strcat(filegenerate,".txt");
    fstream fout(filegenerate, ios::in|ios::out);
     if(!fout)
    {								
    	cout<<"filegenerate couldn't be opened. product ID is Invalid. \n";
	}
	cout<<"modify employee name: \n";
  	cin>>post;
  	fout<< "\nnumber of working employees: "<<postquantity<< "\nemployee salary: "<<salary<< "\nemployee name :"<<post<<"\nemployee id: "<<empid;
 	fout.close();
}

void admin()
{
  while(1)
  {
 
	cout<<"\n\t\t\t     WELCOME TO THE SAYANTAN'S SHOP MANAGEMENT SYSTEM \n";
	cout<<"\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n";
 	cout<<"\n\t\t\t1. Add Entries\n\n\t\t\t2. Show profit\n\n\t\t\t3. Search Product Details\n\n\t\t\t4. Search Employee Details\n\n\t\t\t5. Modify Product Details\n\n\t\t\t6. Modify Employee Details\n\n\t\t\t7. Exit\n";
  cout<<"\n\n\t\t\tEnter a option : \n";
  int u;
  cin>>u;
if(u==1)
  {
  amount a;
  a.show();
  a.add();
}
  else if(u==2)
  {
  amount d;
  d.show();
}
  else if(u==3)
  {  
   char id[20];
   char c;
    cout<<"\nprovide the ID to search\n";
    cin>>id;
    char filegenerate[20];
    strcpy(filegenerate,id);
    strcat(filegenerate,".txt");
    ifstream x(filegenerate);
    if(!x)
    {
    	cout<<"Product ID is Invalid. \n";
	}
    while(x)
    {x.get(c);
     cout<<c;
    }
    

    x.close();
}
   else if(u==4)
   {
   	char eid[20];
   	char d;
   	cout<<"\nprovide the employee ID to search\n";
    cin>>eid;
   	char filegenerate[20];
   	strcpy(filegenerate,eid);
   	strcat(filegenerate,".txt");
   	ifstream y(filegenerate);
   	 if(!y)
    {
    	cout<<"Employee ID is Invalid. \n";
	}
   	while(y)
   	{
   	y.get(d);
   	cout<<d;
   }
 
   y.close();
}
else if(u==5)
{
	amount u;
	u.update_item();
}
 else if(u==6)
 {
 	amount v;
 	v.update_emp();
 }
  else if(u==7)
  {
  break;
}
  else cout<<"Invalid option. Please select valid options\n";
 }

}

int main(){                                                 // its the main function
    int ch;
   
    while(1){
        cout<<"\n \t\t\t______________________________________________\n";
        cout<<"\n\t\t\tWELCOME TO MY SAYANTAN'S SHOP MANAGEMENT SYSTEM \n";
        cout<<"\n \t\t\t______________________________________________\n\n";
        cout<<"\n \t\t\t* * * * * * * * * * * * ";
        cout<<"\n\t\t\t  1. ENTER MANAGEMENT SYSTEM";
        cout<<"\n\t\t\t  2. EXIT";
        cout<<"\n\t\t\t* * * * * * * * * * * *\n";
        cout<<"\n\t\t\t Enter Your choice: ";
        cin>>ch;
        switch(ch){
            case 1:
                admin();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout<<"Please enter a valid option\n";
                break;
        }
    }
    return 0;
}


