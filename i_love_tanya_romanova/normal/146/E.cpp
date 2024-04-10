/*
Unrestrained by the illusions
that hold a world at bay
Unbaptized in flames of delusion
For me the world was but a grave

The time is nigh for another revolution
As the sun gives away to greater light
Just a leap in a private evolution
A crop laid out for the reaping,
with a global scythe

Fear not the world falling at your feet
For there are greater things coming to be

The time is ripe for this transformation
As all good talks must come to an end
And where life will greet its negation
And upon this soil no Sun will ever ascend

For I am becoming...
and I'll grow my wings before the fall

As it comes forth from primordial darkness
And takes only what needs to be reclaimed
These slumbering aeons will bear as witness
To the beauty of a world dressed in flame...
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
#define right adsgasgadsg

using namespace std;

long n,k;
long ttl;
map<long, long> mapp;
set<long> nice;
long ar[200000];
long calc[20000];
long dp[4][100500];
long fr;
long temp;
long answ;
long long fact[200000];

void ad(long&a,long &b)
{
     a+=b;
     if (a>=bs)a-=bs;
}

long long pw(long long a,long long b)
{
 if (b==0)return 1;
 if (b%2) return a*pw(a,b-1)%bs;
 return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);    
}

void generate(long x)
{
 if (x>0)
 {
  ++ttl;
  mapp[x]=ttl-1;
  nice.insert(x);
 }
 if (x<100000000)
 {
  generate(x*10+4);
  generate(x*10+7);
 }
}

long long gf(long x)
{
 return fact[x];
}

long gc(long n,long m)
{
 if (m>n)return 0;
 long long res=1;
 res*=gf(n);
 res*=inv(gf(m));
 res%=bs;
 res*=inv(gf(n-m));
 return res%bs;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

fact[0]=1;
for (int i=1;i<=100000;i++)
 fact[i]=fact[i-1]*i%bs;
 
cin>>n>>k;
generate(0);
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (nice.find(ar[i])!=nice.end())
 {
  ++calc[mapp[ar[i]]];
 }
 else ++fr;
}

dp[0][0]=1;

for (int i=0;i<ttl;i++)
{
 for (int j=0;j<=n;j++)
 {
  dp[1-i%2][j]=0;
 }
 
 for (int usd=0;usd<=n;usd++)
 {
  ad(dp[(i+1)%2][usd],dp[i%2][usd]);
  temp=1ll*calc[i]*dp[i%2][usd]%bs;
  ad(dp[(i+1)%2][usd+1],temp);
 }
}

answ=0;
for (int ch=0;ch<=k;ch++)
{
 temp=dp[ttl%2][ch]*1ll*gc(fr,k-ch)%bs;
 ad(answ,temp);
}
cout<<answ<<endl;

cin.get();cin.get();
return 0;}