#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
class student
{
  public:
  string name;
  float perc;
  string caste;
  string allot;
  string seatcat;
  
};

class college
{
  public:
  string name;
  int gen; int obc; int sc; int st;
};  

int main() 
{
  int ns,nc;
  cout<<"Enter no. of students: "; cin>>ns;
  cout<<"Enter no. of colleges: ";cin>>nc;
  student s[ns];college c[nc];
  ifstream myfile;
  myfile.open("students.csv");

    for(int k=0;k<ns;k++)
  {
    string l;
    getline(myfile,s[k].name,',');
    getline(myfile,l,',');
    s[k].perc=atof(l.c_str());
    getline(myfile,s[k].caste,',');
    s[k].allot="NULL";
  }
  myfile.close();

  myfile.open("colleges.csv");
  for(int k=0;k<nc;k++)
  {
    string lgen,lobc,lsc,lst;

    getline(myfile,c[k].name,',');
    getline(myfile,lgen,',');
    c[k].gen=atoi(lgen.c_str());
    getline(myfile,lobc,',');
    c[k].obc=atoi(lobc.c_str());
    getline(myfile,lsc,',');
    c[k].sc=atoi(lsc.c_str());
    getline(myfile,lst,',');
    c[k].st=atoi(lst.c_str()); 
  }
myfile.close();

int i,j; student t1;
  
for(i=0;i<ns;i++) //student sort
{
    for(j=0;j<ns-1-i;j++)
    {
      if(s[j].perc<s[j+1].perc)
      {t1=s[j];s[j]=s[j+1];s[j+1]=t1;}

    }
}


for(i=0;i<ns;i++) //alloter
{
  
  for(j=0;j<nc;j++)
 {
  if(s[i].allot=="NULL")
{
  if(s[i].caste=="gen")
  {
    if(c[j].gen>0){s[i].allot=c[j].name;s[i].seatcat="gen"; c[j].gen--;}
    
  }

  else if(s[i].caste=="obc")
  {
    if(c[j].gen>0){s[i].allot=c[j].name;s[i].seatcat="gen"; c[j].gen--;}

    else if(c[j].obc>0){s[i].allot=c[j].name;s[i].seatcat="obc";c[j].obc--;}
  }

  else if (s[i].caste=="sc")
  {
    if(c[j].gen>0){s[i].allot=c[j].name;s[i].seatcat="gen"; c[j].gen--;}

    else if (c[j].sc>0){s[i].allot=c[j].name;s[i].seatcat="sc";c[j].sc--;}
  }

  else if (s[i].caste=="st")
  {
    if(c[j].gen>0){s[i].allot=c[j].name;s[i].seatcat="gen"; c[j].gen--;}

    else if (c[j].st>0){s[i].allot=c[j].name;s[i].seatcat="st";c[j].st--;}
  }
}
  }

}

cout<<endl<<"RESULTS"<<endl;
for(i=0;i<ns;i++)
{
	if(s[i].name[0]=='\n') {s[i].name=s[i].name.substr(1,s[i].name.size()-1);}
	if(s[i].allot[0]=='\n') {s[i].allot=s[i].allot.substr(1,s[i].allot.size()-1);}
  cout<<"Name: "<<s[i].name<<endl;
  cout<<"Allotment: "<<s[i].allot<<endl;
  cout<<"Seat category: "<<s[i].seatcat<<endl;
  cout<<"Candidate category: "<<s[i].caste<<endl<<endl;
}





}
