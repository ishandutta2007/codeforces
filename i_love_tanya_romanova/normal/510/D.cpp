/*
 ,     ,
    .
      ,
      
   (4)

:
, ,   ,
    .
, ,   ,
    .

  ,   ,
    .
       ,
    
   (4)



    ,  ,
    .
  ,    ,
     .


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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAG 10000

using namespace std;

long n,l[1<<20],c[1<<20];
set<long> reach;

long gcd(long a,long b)
{
 if(a<0)a=-a;
 if (b<0)b=-b;
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}
map<long, long> d;
set<long>::iterator it;
set<pair<long, long> > ::iterator it1;
long val,q;
set<pair<long, long> > ts;
long cost;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
reach.insert(0);
d[0]=0;

for (int i=1;i<=n;i++)
 cin>>l[i];
for (int i=1;i<=n;i++)
 cin>>c[i];

for (int i=1;i<=n;i++)
{
 for (it=reach.begin();it!=reach.end();++it)
 {
  val=(*it);
  q=gcd(val,l[i]);
  ts.insert(make_pair(q,c[i]+d[val]));
 }
 for (it1=ts.begin();it1!=ts.end();it1++)
 {
  val=(*it1).first;
  cost=(*it1).second;
  if (reach.find(val)==reach.end())
  {
   reach.insert(val);
   d[val]=cost;
  }
  if (d[val]>cost)d[val]=cost;
 }
 ts.clear();
}

if (reach.find(1)==reach.end())
cout<<-1<<endl;
else cout<<d[1]<<endl;

cin.get();cin.get();
return 0;}