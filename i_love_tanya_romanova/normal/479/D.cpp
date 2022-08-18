/*
I've become resistant to myself
To my weaknesses and pain
I've become the one who wants to live
And just feel alive again
I've changed myself
I've become addicted to being strong
Started out my second life
And the remnants of your tears and smiles
Shift deleted from my mind
Without knowing how it hurts...
I feel safe
Without knowing how it hurts...
I feel safe
Is this
What I
Really
Wanted?
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
#define free adsgasdg

using namespace std;

long n,l,x,y,a[1<<20];
set<long> has;
long hx,hy;
long ans;
long thx,thy;

void check(long ps)
{
 if (ps<0||ps>l)return;
 hx=thx;
 hy=thy;
 if (has.find(ps+x)!=has.end())hx=1;
 if (has.find(ps+y)!=has.end())hy=1;
 if (has.find(ps-x)!=has.end())hx=1;
 if (has.find(ps-y)!=has.end())hy=1;
 if (hx&&hy)ans=ps;
}

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>l>>x>>y;
for (int i=0;i<n;i++)
{
 cin>>a[i];
 has.insert(a[i]);
}

hx=hy=0;

for (int i=0;i<n;i++)
{
 if (has.find(a[i]+x)!=has.end())hx=1;
 if (has.find(a[i]+y)!=has.end())hy=1;
 if (has.find(a[i]-x)!=has.end())hx=1;
 if (has.find(a[i]-y)!=has.end())hy=1;
}

thx=hx;
thy=hy;

if (hx&&hy)
{
 cout<<0<<endl;
}
else
{
 ans=-1;
 for (int i=0;i<n;i++)
 {
  check(a[i]-x);
  check(a[i]+x);
  check(a[i]-y);
  check(a[i]+y);
 }
 if (ans>=0)
  cout<<1<<endl<<ans<<endl;
  else
  {
   cout<<2<<endl;
   cout<<x<<" "<<y<<endl;
  }
}
cin.get();cin.get();
return 0;}