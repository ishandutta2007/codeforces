/*
I curse you all!

I, in the kingdom of wrath
Upon the ashes of cities burned
I shall make the world the bloodiest of ages

Your days are numbered
Your world is finished
Your life is over, extinct
To fight is futile!

I curse you all!

Fury within
I deplore you all
Fury within

I, upon the day of wrath
Amidst the smoke and flames of ruin
I shall make you burn upon the stakes

Usesless your attempt to overthrow me
Spineless, you cower with lack of loyalty
I shall not grant you resolve for your wrongs

Plead for mercy, you shall be denied
You beg for empathy, so pathetic your deceit, your lies
I thrive in your weakness, confessor of heresy
Never again shall I believe in your lies!

Hate! Hate!
Hate! Hate!
Hate! Hate!
Hate! Hate!

Hate! Hate! I demand my vengeance
Hate! Hate! I shall never retreat
Hate! Hate! Suffer through unsurmountable pain
Hate! Hate! You coward, you Judas

I denounce your ideology
I will overrule your ways
As I thrust myself upon thee

You shall suffer the fate of dis
Dissolve in the ashes of earth
You must face the day of reckoning!

I curse you all!
Fury Within!
I deplore you all!
Fury Within!
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define eps 1e-14
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
//#define N 120000

using namespace std;

long fib[700000],fsum[700000];
pair<long, long> ad[1<<20];
long ans[1<<20];
long n,m;
long s[1<<20];
long a[1<<20];
long tp,l,r;

long makefib(long ind, long a,long b)
{
 if (ind==1)return a;
 if (ind==2)return b;
 return (1ll*fib[ind-1]*b+1ll*fib[ind-2]*a)%bs;
}

void doadd(long v,long l,long r,long a,long b)
{
// cout<<"^^"<<v<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
 ad[v].first+=a;
 ad[v].second+=b;
 ad[v].first%=bs;
 ad[v].second%=bs;
 if (l==r)
  ans[v]=ans[v]+a,ans[v]%=bs;
 else if (l+1==r)
  ans[v]=ans[v]+(b+a)%bs,ans[v]%=bs;
  else
  ans[v]=(ans[v]+1ll*fsum[r-l]*b+1ll*(fsum[r-l-1]+1)*a)%bs;
}

void push(long v,long l,long r)
{
 if (l==r)return;
 long m=l+r;
 m/=2;
 long v1,v2;
 doadd(v*2,l,m,ad[v].first,ad[v].second);
 long val1,val2;
 val1=makefib(m-l+2,ad[v].first,ad[v].second);
 val2=makefib(m-l+3,ad[v].first,ad[v].second);
 /*cout<<"^^^^"<<m<<" "<<l<<" "<<r<<" "<<ad[v].first<<" "<<ad[v].second<<
 " "<<val1<<" "<<val2<<endl;
*/ doadd(v*2+1,m+1,r,val1,val2);
 ad[v]=make_pair(0,0);
}

void update(long v,long tl,long tr,long l,long r,long L, long R)
{
//cout<<v<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
 if (l>r)return;
 push(v,tl,tr);
 if (l==tl&&r==tr)
 {
  doadd(v,l,r,fib[l-L+1],fib[l-L+2]);
  return;
 }
 push(v,tl,tr);
 long tm=tl+tr;
 tm/=2;
 update(v*2,tl,tm,l,min(r,tm),L,R);
 long aa,bb;
// cout<<v<<"^"<<tl<<" "<<tr<<" "<<tm<<" "<<aa<<" "<<bb<<" %%"<<a<<" "<<b<<endl;
 update(v*2+1,tm+1,tr,max(l,tm+1),r,L,R);
 ans[v]=ans[v*2]+ans[v*2+1];
 ans[v]%=bs;
}

long sum(long v,long tl,long tr,long l,long r)
{
 if (l>r)return 0;
 if (l==tl&&r==tr)
{ 
  //  cout<<l<<" ^^ "<<r<<" "<<ans[v]<<endl; 
  return ans[v];
}

 push(v,tl,tr);
 long tm=tl+tr;
 tm/=2;
 long res=sum(v*2,tl,tm,l,min(r,tm))+
 sum(v*2+1,tm+1,tr,max(l,tm+1),r);
 return res%bs;
}

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
    cin>>a[i];

for (int i=1;i<=n;i++)
{
 s[i]=s[i-1]+a[i];
 s[i]%=bs;
}

fib[1]=fib[2]=1;
for (int i=3;i<=500000;i++)
{
 fib[i]=fib[i-1]+fib[i-2];
 fib[i]%=bs;
}

for (int i=1;i<=500000;i++)
{
 fsum[i]=fsum[i-1]+fib[i];
 fsum[i]%=bs;
}

/*while (cin>>n>>m>>tp)
cout<<makefib(tp,n,m)<<endl;
*/

for (int i=0;i<m;i++)
{
 cin>>tp>>l>>r;
 if (tp==1)
 {
  update(1,1,n,l,r,l,r);
 }
 else
 cout<<((sum(1,1,n,l,r)+s[r]-s[l-1])%bs+bs)%bs<<endl;
}

cin.get();cin.get();
return 0;}