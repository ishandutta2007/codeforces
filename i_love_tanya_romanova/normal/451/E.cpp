/*
If ever words were spoken, painful and untrue
I said, "I loved but I lied"
In my life all I wanted
Was the keeping of someone like you
As it turns out, deeper within me
Love was twisted and pointed at you

Never ending pain, quickly ending life

You keep this love, thing, love, child, love, toy
You keep this love, fist, love, scar, love, break
You keep this love, love, love
Love, love, love
You keep this love

I'd been the tempting one, stole her from herself
This gift in pain, her pain was life
And sometimes I feel so sorry
I regret this the hurting of you
But you make me so unhappy
I'd take my life and leave love with you

I'd kill myself for you, I'd kill you for myself

You keep this love, thing, love, child, love, toy
You keep this love, fist, love, scar, love, break
You keep this love, love, love
Love, love, love
You keep this love

No more head trips

You keep this love, thing, love, child, love, toy
You keep this love, fist, love, scar, love, break
You keep this love, love, love
Love, love, love
You keep this love

You keep this love
You keep this love
You keep this love
You keep this love
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
#define N 120000

using namespace std;

long long n,s,ar[200000],t,val,temp;
long long invv[2000];

long gbit(long a)
{
 long s=0;
 for (int i=0;i<25;i++)
  if (a&(1<<i))++s;
  return s;
}

long long pw(long long a,long long b)
{
     if (b==0)return 1;
     if (b%2)return (a*pw(a,b-1))%bs;
     return  pw(a*a%bs,b/2);
}

long long inv(long long x)
{
 return pw(x,bs-2);
}

long long gc(long long n,long long m)
{
 long long res=1;
 for (long long i=n;i>n-m;--i)
 {
  res=res*(i%bs);
  res%=bs;
 }
 for (int i=1;i<=m;i++)
{  res=res*invv[i];res%=bs;}
return res;
}

long long ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=1;i<=100;i++)
 invv[i]=inv(i);
 
cin>>n>>s;
for (int i=0;i<n;i++)
{
 cin>>ar[i];
}

for (int mask=0;mask<(1<<n);mask++)
{
 t=gbit(mask);
 val=s;
 for (int i=0;i<n;i++)
  if (mask&(1<<i))val-=ar[i]+1;
 if (val<0)continue;
 temp=gc(val+n-1,n-1);
// cout<<val<<"   "<<val+n-1<<"  "<<n-1<<" "<<temp<<endl;
 if (t%2)ans=ans-temp;
 else ans=ans+temp;
 ans%=bs;
 while (ans<0)ans+=bs;
// cout<<ans<<" "<<mask<<" "<<endl;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}