/*
There's a place that I keep deep inside me
It can trigger my mind
All along I knew it has been with me
Since I was just a child

I just summon power within my soul
It has given me life, beyond life I take
Blame for my murderous problem my signature
Always reminds

It's a message in blood
It's your cryptic warning
Within the message in blood
Marks the years of pain,
And your godforsaken ending to life

I'm provoked into sick confrontations, brutal
Time after time, bed of nails, suffocation,
life's ending, slay in different designs
One mans misery is another mans mystery
No one cares to understand my
Demented means
Sticks and stones can break all your
brittle bones, epitaph written at your feet

It's a message in blood
It's your cryptic warning
Within the message in blood
Marks the years of pain,
And your godforsaken ending to life
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
#define clone agsdahfaassdg

using namespace std;

long long n,m,g,fact[2000000];
long long rem,lsig,ans;

long long pw(long long a,long long b)
{
     if(b==0)return 1;
     if (b%2)return a*pw(a,b-1)%bs;
     return pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

long long gc(long long n,long long m)
{
     long long res=fact[n];
     res*=inv(fact[m]);
     res%=bs;
     res*=inv(fact[n-m]);
     return res%bs;
}

int main(){
//freopen("rmq.in","r",stdin);
//freopen("rmq.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

fact[1]=1;
fact[0]=1;
for (int i=2;i<=1000000;i++)
fact[i]=fact[i-1]*i%bs;


cin>>n>>m>>g;


for (int stp=0;stp<n+m;stp++)
{
 if (stp>n)continue;
 rem=n-stp;
 rem+=m-1;
 if (m==0)continue;
 lsig=(stp%2!=0);
 if (stp==n+m-1)
 {
  lsig=1-lsig;
 }   
 if (lsig!=g)continue;
//cout<<rem<<" "<<n-stp<<endl;
 ans+=gc(rem,n-stp);
 ans%=bs;
}

if (m==0)
{lsig=1-(n%2);
 if (lsig==g)++ans;}
 cout<<ans%bs<<endl;
 
cin.get();cin.get();
return 0;}