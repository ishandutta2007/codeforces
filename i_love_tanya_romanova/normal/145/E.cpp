/*
Can't know what's high
Till you've been down so low
The future's bright
Lit up with no where to go
To and fro the pendulum throws

We are here and then we go
My shadow left me long ago

Understand what we don't know
This might pass
This might last
This may grow
Easy come and easy go
Easy left me a long time ago

I'm in the fire but I'm still cold
Nothing works, works for me anymore

To and fro the pendulum throws
To and fro the pendulum throws

(To and fro the pendulum throws)
(To and fro the pendulum throws)
(To and fro the pendulum throws)
(To and fro the pendulum throws)
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

long up[1<<22],topush[1<<22],dwn[1<<22],c4[1<<22],c7[1<<22];
string st;
long n,m,tests,l,r;

void merg(long v)
{ 
 up[v]=max(up[v*2]+c7[v*2+1],c4[v*2]+up[v*2+1]);
 dwn[v]=max(dwn[v*2]+c4[v*2+1],c7[v*2]+dwn[v*2+1]);
 c4[v]=c4[v*2]+c4[v*2+1];
 c7[v]=c7[v*2]+c7[v*2+1];
// up[v]=max(up[v],c4[v*2]+c7[v*2+1]);
// dwn[v]=max(dwn[v],c7[v*2]+c4[v*2+1]);
}

void push(long v)
{
 if (topush[v])
 {
  swap(up[v],dwn[v]);
  swap(c4[v],c7[v]);
  topush[v*2]^=1;
  topush[v*2+1]^=1;
  topush[v]=0;
 }
}

void build(long v,long l,long r)
{
 if (l==r)
 {
  up[v]=dwn[v]=1;
  if (st[l]=='4')c4[v]=1;
  else c7[v]=1;
  return ;
 }
 long mid=l+r;
 mid/=2;
 build(v*2,l,mid);
 build(v*2+1,mid+1,r);
 merg(v);
}

void update(long v,long tl,long tr,long l,long r)
{
 push(v);
 if (tr<l||tl>r)return;
// cout<<v<<"   "<<l<<"   "<<tl<<" "<<r<<" "<<tr<<" "<<c4[v]<<" "<<c7[v]<<endl;
 if (l<=tl&&r>=tr)
 {
  topush[v]=1;
  push(v);
 }
 else
 {
 long mid=tl+tr;
 mid/=2;
 update(v*2,tl,mid,l,r);
 update(v*2+1,mid+1,tr,l,r);
 merg(v);
// cout<<"%"<<v<<"  "<<up[v]<<" "<<dwn[v]<<" "<<topush[v]<<" "<<dwn[v*2]<<" "<<c7[v*2]<<" "<<dwn[v*2+1]<<" "<<c4[v*2+1]<<endl;
 }
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>st;build(1,0,n-1);

long tests=m;
for (;tests;--tests)
{
 cin>>st;
 if (st=="count")
 {
  cout<<up[1]<<endl;
  continue;
 }
 else
 {
  cin>>l>>r;
  --l;
  --r;
  update(1,0,n-1,l,r);
 }
}

cin.get();cin.get();
return 0;}