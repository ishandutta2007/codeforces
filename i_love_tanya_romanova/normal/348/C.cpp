/*
The time is running
It's running so fast that you don't notice
Years are passing by
And you're growing older
What happened to all your dreams?
Did they become true at all?

We cannot undo the deeds of the years
They leave you on your own
With all your deepest fears

Don't look for the future
Don't live in the past
Just take it day by day 'cause life goes fast
The minutes, the hours
The days and the years will fly so
Live still when you have the time

We cannot undo the deeds of the years
They leave you on your own
With all your deepest fears

Wheel of the time
Turns again tonight
Eternally decides our destiny
Wheel of the time
Turns again tonight
Without reason or rhyme

The hands of time
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

bool has[500][100001];
vector<long> v;
long long n,num,quer,ar[200000];
long sz,q;
vector<vector<long> > heavy;
vector<vector<long> > light;
long tp[200000];
vector<vector<long> > inter1,inter2;
long long ans1[200000],ans2[200000];
string st;
long long nu,val;
long long ps[200000];
long long toad[200000];
long long res;

int main(){
//freopen("revolutions.in","r",stdin);
//freopen("revolutions.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
cin>>num>>quer;

for (int i=1;i<=n;i++)
cin>>ar[i];

// cut tab+

for (int i=1;i<=num;i++)
{
    cin>>sz;
    v.clear();
    for (int j=1;j<=sz;j++)
    {cin>>q;v.push_back(q);}
    sort(v.begin(),v.end());
    
    if (v.size()>256)
    {
     heavy.push_back(v);
     ps[i]=heavy.size()-1;
     tp[i]=2;
     for (int j=0;j<v.size();j++)
     has[heavy.size()-1][v[j]]=1;
    }
    else 
    {
     light.push_back(v);
     ps[i]=light.size()-1;
     tp[i]=1;
    }
}

// p inter

inter1.resize(light.size());
for (int i=0;i<inter1.size();i++)
 inter1[i].resize(heavy.size());
 
 inter2.resize(heavy.size());
 for (int i=0;i<inter2.size();i++)
  inter2[i].resize(heavy.size());
  
for (int i=0;i<light.size();i++)
{
    for (int j=0;j<heavy.size();j++)
    {       
            inter1[i][j]=0;
            for (int q=0;q<light[i].size();q++)
            if (has[j][light[i][q]])inter1[i][j]++;
    }
}


for (int i=0;i<heavy.size();i++)
{
    for (int j=0;j<heavy.size();j++)
    {     
            inter2[i][j]=0;
            for (int q=0;q<heavy[i].size();q++)
            if (has[j][heavy[i][q]])inter2[i][j]++;
    }
}
// prec sum OD

for (int i=0;i<light.size();i++)
{
    for (int j=0;j<light[i].size();j++)
    ans1[i]+=ar[light[i][j]];
}
for (int i=0;i<heavy.size();i++)
{
    for (int j=0;j<heavy[i].size();j++)
    ans2[i]+=ar[heavy[i][j]];   
}

// quer
/*
for (int i=0;i<inter2.size();i++)
 {for (int j=0;j<inter2[0].size();j++)
 cout<<inter2[i][j]<<" ";
 cout<<endl;
}*/

for (;quer;--quer)
{
 cin>>st;
 if (st=="?")
 {
   cin>>nu;
     if (tp[nu]==1)// req light
     {
      nu=ps[nu];
//      cout<<"%"<<nu<<endl;
      ans1[nu]=0;
      for (int j=0;j<light[nu].size();j++)
      {
       ans1[nu]+=ar[light[nu][j]];   
      }
      for (int j=0;j<heavy.size();j++)
      ans1[nu]+=toad[j]*inter1[nu][j];
      cout<<ans1[nu]<<endl;
     }
     else // req heavy
     {
      nu=ps[nu];
      res=ans2[nu];
      for (int j=0;j<heavy.size();j++)
      res+=toad[j]*inter2[nu][j];
      cout<<res<<endl;
     }
 }
 else
 {
     cin>>nu;
     cin>>val;
     if (tp[nu]==1)// add light
     {
      nu=ps[nu];
      for (int j=0;j<light[nu].size();j++)
       ar[light[nu][j]]+=val;
      for (int j=0;j<heavy.size();j++)
       ans2[j]+=inter1[nu][j]*val;
     }
     else // add heavy
     {
      nu=ps[nu];
      toad[nu]+=val;
     }
 }   
}

cin.get();cin.get();
return 0;}