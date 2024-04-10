/*
Can't overcome it, it's what I do best
I'll pick your pocket for your last red cent
It's a disease, I'm stricken like the rest
Never return anything I'm lent

It wasn't me, yeah you know it wasn't me
It must've been someone who looked like me
Innocent until proven guilty
And you ain't got a thing on me

Your possessions, your worldly possessions
Mean more to me than your protective obsessions
You wanna hide 'em, lock 'em up inside and
Throw away the key so I can't find em
It's a shame, it's a god-damned shame
I'm the culprit but you're the one to blame
I'll take another lesson from my mother
It's better to take than get took

Steal a dollar, steal a dime
Force of habit will hit you every time
In your pockets, invade your space
Force of habit anytime or anyplace
Pay attention keep an eye on all your cash
Force of habit will deprive you of your stash
If I do it, yeah, if I get caught
Force of habit is the problem that I got

Mama told me look but don't touch,
but that only made me want it more
Doesn't matter if you're a friend or foe,
'cause your house is my candy store
I admit I know I got a problem,
but temptation is controlling me
I can't resist a five-fingered discount,
everything for me is free
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

long long n,w[500000],a,b,c;
long long sz[500000];
long long ans,temp;

long long gett(long long x)
{
 if (x==w[x])return x;
 return w[x]=gett(w[x]);
}

void merg(long long a,long long b)
{
 a=gett(a);
 b=gett(b);
 if (rand()%2)swap(a,b);
  w[a]=b;
  sz[b]+=sz[a];
}

bool luck(long long x)
{
 while (x)
 {
  if (x%10!=4&&x%10!=7)return false;
  x/=10;
 }
 return true;
}

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
w[i]=i,sz[i]=1;

for (int i=1;i<n;i++)
{
 cin>>a>>b>>c;
 if (luck(c)==0)merg(a,b);
}

ans=n*(n-1)*(n-2);

for (int i=1;i<=n;i++)
{
 if (w[i]!=i)continue;
 temp=sz[i];
 ans-=temp*(temp-1)*(temp-2);
 ans-=temp*(n-temp)*(temp-1)*2;
}

cout<<ans<<endl;


cin.get();cin.get();
return 0;}