/*
Why does this morning feel different from all the others
The Hand that once gave life has begun to smother
From my within my lungs the air has been released
And I cannot feel the chill in the morning breeze

Yet I am at ease...

For me there is no warmth left even in the Sun
Safe from the earth this crest will be undone
Naked and alone, upon an altar made of stone
I fear has become final throne

Upon the third circle on the first day
Where nothing moves but the daevas in the wind
The wind bears a silent calling to mountains far away
Summoning the birds of prey

"On the second day the vultures came
The beasts of birds, the sentinels of decay
Deeper each day they tore into my flesh
Feasting upon my loins and the insides through my chest
For days it lasted until they ran out of meat
leaving behind only bones for the Sun to bleach"

Upon this silent altar, upon my dreamless bed
Leaving the world bereft and the vultures fed
Slowly all will be gone that has ever signed to me
As the remains quietly wash into the sea...
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