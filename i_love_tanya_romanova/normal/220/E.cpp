/*
Beyond the horizon of the place we lived when we were young
In a world of magnets and miracles
Our thoughts strayed constantly and without boundary
The ringing of the division bell had begun
Along the Long Road and on down the Causeway
Do they still meet there by the Cut
There was a ragged band that followed in our footsteps
Running before time took our dreams away
Leaving the myriad small creatures trying to tie us to the ground
To a life consumed by slow decay
The grass was greener
The light was brighter
With friends surrounded
The nights of wonder
Looking beyond the embers of bridges glowing behind us
To a glimpse of how green it was on the other side
Steps taken forwards but sleepwalking back again
Dragged by the force of some inner tide
At a higher altitude with flag unfurled
We reached the dizzy heights of that dreamed of world
Encumbered forever by desire and ambition
There's a hunger still unsatisfied
Our weary eyes still stray to the horizon
Though down this road we've been so many times
The grass was greener
The light was brighter
The taste was sweeter
The nights of wonder
With friends surrounded
The dawn mist glowing
The water flowing
The endless river
Forever and ever
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

using namespace std;

long t1[200000],t2[200000];
long long inv,ninv;
long long ans;
long a,b,ar[200000];
set<long> sett;
map<long, long> mapp;
set<long>::iterator it;
long n,k;
long calc;
long l;

long sum1(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t1[r];
 return res;
}

void inc1(long i,long val)
{
 for (;i<=n;i=(i|(i+1)))
  t1[i]+=val;
}

long sum2(long r)
{
 long res=0;
 for (;r>=0;r=(r&(r+1))-1)
  res+=t2[r];
 return res;
}

void inc2(long i,long val)
{
 for (;i<=n;i=(i|(i+1)))
  t2[i]+=val;
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for(int i=1;i<=n;i++)
{cin>>ar[i];sett.insert(ar[i]);}

calc=1;
for (it=sett.begin();it!=sett.end();++it)
{
 mapp[*it]=calc;
 ++calc;
}

for (int i=1;i<=n;i++)
 ar[i]=mapp[ar[i]];

for (int i=1;i<=n;i++)
{
 inv+=(i-1)-sum1(ar[i]);
 inc1(ar[i],1);
}

l=n;

for(int i=n;i;i--)
{
// cout<<inv<<endl;
 // move r
 ninv=l-sum1(ar[i]);
 inv+=ninv;
 ninv=sum2(ar[i]-1);
 inv+=ninv;
 inc2(ar[i],1);
 
 while (l>=i||(inv>k&&l>0))
 {
  ninv=l-sum1(ar[l]);
  inv-=ninv;
  ninv=sum2(ar[l]-1);
  inv-=ninv;
  inc1(ar[l],-1);
  --l;
 }

 ans+=l;
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}