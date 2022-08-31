/*
,  .
  ,   ,
 ,    ,
  ,    ,
  .

,    ,
     ,
     .

     ,
  ,    ,
     ,
 ,     
    .

,    ,
     ,
-     .

,  ,
  ,   .
 ,    ,
  ,   ,
   .

,    ,
     ,
     ,
-     .
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,k,ar[300000],t;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);


cin>>n>>k;

if (n==1)
{
 if (k>0)cout<<-1<<endl;
 else cout<<1<<endl;
 return 0;
}
if (k<n/2)
{
 cout<<-1<<endl;
 return 0;
}

t=k-(n/2-1);

ar[1]=t;
ar[2]=t*2;

for (int i=3;i<=n;i++)
ar[i]=500000000+i;

for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";
 cout<<ar[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}