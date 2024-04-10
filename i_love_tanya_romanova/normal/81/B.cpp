/*
Two seconds make the difference
You always know
You will never question
You never doubt
Cause you're the one
Its nothing to you
A pile of broken glass
A broken stick
A load of trash
But its a world to me
A reason to give
A reason to fight
A reason to live
How could you understand?
As you don't even care
How could you understand?
My choice
Cause you don't care
You don't dare
To question yourself
You always know
You will never question
You never doubt
Cause you're the one
*/
 
//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
 
using namespace std;

bool isdig(char c)
{
 return (c>='0'&&c<='9');
}

string st;
long temp;
vector<long> vec;
long lnum,ldig,flag;
long dots;
long ldot;
string tres;
vector<string> tv;

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

getline(cin,st);
for (int i=0;i<st.size();i++)
{
 if (isdig(st[i]))
 {
  tres+=st[i];
  temp=temp*10+st[i]-48;
  if (temp>100)temp=100;
  continue;
 }   
 else
 {
     if (temp){vec.push_back(temp);tv.push_back(tres);}
     temp=0;tres="";
     if (st[i]==' ')continue;
     
     if (st[i]=='.'){++dots;
     if (dots==3){vec.push_back(-1);dots=0;}}
     
     if (st[i]==','){vec.push_back(-2);}
 }
}

if (temp){vec.push_back(temp);tv.push_back(tres);}
reverse(tv.begin(),tv.end());


ldot=-2;
lnum=-2;
for (int i=0;i<vec.size();i++)
{
 if (vec[i]==-1)
 {
  if(flag)cout<<" ";
  flag=1;
  ldot=i;
  cout<<"...";
  continue;
 }
 if (vec[i]==-2)
 {
  if (i>0&&vec[i-1]==-2)cout<<" ";
  cout<<",";flag=1;
  continue;
 }
 if (vec[i]>0)
 {
  if (lnum>ldot||(i>0&&vec[i-1]==-2))cout<<" ";
  lnum=i;
  cout<<tv.back();
  tv.pop_back();
  flag=1;
 }
}
cout<<endl;

cin.get();cin.get();
return 0;}