/*
Depredate, Restraint is not an option
This world has fallen, Now scorched and barren

The rage of lunatics, shall lead us nevermore
The hand, long forgotten, shall feed the blessed now

Arise our Golem Defeat this enemy
God strength upon the leach infested
Rise our ancient wisdom and bring your pestilence

Rectify, With haste your wrath awakened
Malfeasance, You scorn this world
Enshrined by grace, your shadow blinds the feeble
Disentail the noble few

Arise our ancient Golem Defeat this enemy
God strength upon the leach infested
Rise our ancient wisdom destroy this wasteland
Enshrined by Grace devour this presceance

Light the flame of redemption
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
//#include <memory.h>

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
#define bs 1000000009

//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long n,ar[500000],smin[400000][22],sgcd[400000][22];
long l,r,m;

long gcd(long a,long b)
{
 while (a&&b)a>b?a%=b:b%=a;
 return a+b;
}

vector<long> v;

long solve(long x)
{
 long p=1;
 long pw=0;
 while (p*2<=x+1){pw++;p*=2;}
 long res=0;
 long temp,temp1;
 
 v.clear();
// if (x==4)
// cout<<1+x-p+1<<" "<<p<<" "<<sgcd[1+x-p+1][pw]<<endl;
 
 for (int i=1;i+x<=n;i++)
 {
     temp=gcd(sgcd[i][pw],sgcd[i+x-p+1][pw]);
     temp1=min(smin[i][pw],smin[i+x-p+1][pw]);
     if (temp==temp1){v.push_back(i);++res;}
 }
 return res;
}
int main(){
//freopen("elect.in","r",stdin);
//freopen("elect.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>ar[i];

for (int i=1;i<=n;i++)
sgcd[i][0]=smin[i][0]=ar[i];

for (int pw=1;pw<=20;pw++)
for (int i=1;i<=n;i++)
{
    if (i+(1<<pw)>n+1)continue;
    sgcd[i][pw]=gcd(sgcd[i][pw-1],sgcd[i+(1<<pw)/2][pw-1]);
    smin[i][pw]=min(smin[i][pw-1],smin[i+(1<<pw)/2][pw-1]);
}

l=0;
r=n-1;
while (l<r)
{
      m=l+r+1;
      m/=2;
      if (solve(m)>0)l=m;
      else r=m-1;
}

cout<<solve(l)<<" "<<l<<endl;

for (int i=0;i<v.size();i++)
{if (i)cout<<" ";
cout<<v[i];}
cout<<endl;

cin.get();cin.get();
return 0;}