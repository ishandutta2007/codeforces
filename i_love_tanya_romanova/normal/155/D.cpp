/*
Secret bureaucracy, it's just a lie
The devil's henchmen, in suit and tie
A sacred brotherhood; an ancient rite
Politicians and the double lives they hide

Violate your rights, no more equality
Surrender freedom, your Social Security
We, the people face unconstitutional lies
In greed we trust, in revolution we die

Our founding fathers are rolling in their graves
The land of liberty needs a regime change
Until you no longer know right from wrong
The constitution isn't worth the paper it's written on

Screams from the future, warn of calamity
The coming plagues of the new disease
The illuminati, one world currency
One world religion, one World everything
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

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,pr[200000];
vector<long> vec[200000];
long used[200000],active[200000],er;
string st;
long val;
long temp;

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
pr[1]=1;
for (int i=2;i<=100000;i++)
 if (pr[i]==0){
  for (int j=i*2;j<=100000;j+=i)
  {
   pr[j]=1;
   vec[j].push_back(i);
  }
  vec[i].push_back(i);}

for (;m;--m)
{
 cin>>st;
 if (st=="+")
 {
  cin>>val;
  if (used[val]){cout<<"Already on"<<endl;continue;}
  er=0;
  for (int j=0;j<vec[val].size();j++)
  {
   temp=vec[val][j];
   if (active[temp])er=active[temp];
  }
  if (er){cout<<"Conflict with "<<er<<endl;}
  else
  {
   cout<<"Success"<<endl;
   for (int j=0;j<vec[val].size();j++)
   {
    temp=vec[val][j];
    active[temp]=val;
   }
   used[val]=1;
  }
 }
 else
 {
  cin>>val;
  if(used[val]==0)
  cout<<"Already off"<<endl;
  else
  {
   cout<<"Success"<<endl;
   used[val]=0;
   for (int j=0;j<vec[val].size();j++)
   {
    temp=vec[val][j];
    active[temp]=0;
   }
  }
 }
}

cin.get();cin.get();
return 0;}