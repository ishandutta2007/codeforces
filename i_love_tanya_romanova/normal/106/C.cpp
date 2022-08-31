/*
    ,
    ,
  
   .

   ,
   ,
     ,
   .

:
   ,
    .
   ,
  ----.

   ,
   ,
   ,
   .

   ,
   ,
   ,
    .



    ,
    ,
   
   .


*/

#pragma comment(linker, "/STACK:16777216")
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

long a[2000],b[2000],c[2000],cc[2000],d[2000],c0,b0,n,m,
dp[2000];
long answ;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>b0>>c0;
for (int i=1;i<=m;i++)
 cin>>a[i]>>b[i]>>cc[i]>>d[i];

for (int i=0;i<=100;i++)
 for (int j=0;j<=100;j++) 
 dp[i]=-1e9;
 
 dp[n]=0;

for (int i=0;i<=n;i+=b0)
{
 dp[n-i]=max(dp[n-i],dp[n]+i/b0*c0);
}

for (int i=1;i<=m;i++)
{
 for (int has=0;has<=n;has++)
  for (int made=1;made<=100;made++)
   if (made*b[i]<=a[i]&&cc[i]*made<=has)
   {
    dp[has-cc[i]*made]=max(dp[has-cc[i]*made],dp[has]+
     made*d[i]);
   }
}
answ=0;
for (int i=0;i<=100;i++) 
 answ=max(answ,dp[i]);
cout<<answ<<endl;

cin.get();cin.get();
return 0;}