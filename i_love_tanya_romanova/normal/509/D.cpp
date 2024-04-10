/*
 ,  ,
 ,  ,
  ,  ...
 ,  
  ,  
 ,   !

:
    
 ,   .
   ,
  ,    .

   ,
 ,  ,
,    .
,    ,
 ,     ,
  ,   .



  !
 !  !
     !
 ! !
 !  !
   !
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

long long n,m,w[200][200],b[1<<10],a[1<<10];

long long gcd(long long a,long long b)
{
 if (a<0)a=-a;
 if (b<0)b=-b;
 while (a&&b)a>=b?a%=b:b%=a;
 return a+b;
}

long long temp,er,k;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>w[i][j];

for (int i=1;i<=m;i++)
{
 b[i]=w[1][i];   
}

for (int i=1;i<=n;i++)
{
 a[i]=w[i][1]-b[1];
}
/*
for (int i=1;i<=n;i++)
 cout<<a[i]<<" ";
cout<<endl;
for (int i=1;i<=m;i++)
 cout<<b[i]<<" ";
cout<<endl;
*/
temp=0;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  temp=gcd(temp,a[i]+b[j]-w[i][j]);
 }

if (temp!=0)
{
 er=0;
 for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++)
   if (w[i][j]>=temp)
    er=1;
}

if (er)
cout<<"NO"<<endl;
else
{
 if (temp==0)
  k=1000000007;
  else k=temp;
  cout<<"YES"<<endl;
  cout<<k<<endl;
  for (int i=1;i<=n;i++)
  {
   if (i>1)cout<<" ";
   cout<<(a[i]+k)%k;
  }
  cout<<endl;
  for (int i=1;i<=m;i++)
  {
   if (i>1)cout<<" ";
   cout<<(b[i]+k)%k;
  }
  cout<<endl;
}

cin.get();cin.get();
return 0;}