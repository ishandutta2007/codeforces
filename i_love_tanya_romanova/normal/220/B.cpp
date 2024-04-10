/*
It's time to be born again
Don't talk about sex that's a sin
Confess your evils to the man
He'll do everything he can
Don't go mass you'll go to Hell
We'll all be there it'll be swell

Pulling your lives
With such lies
Weak don't survive

We're being sucked up
Into the vacuum culture
This way this way, it's too late
Your addicted
Come on control yourself
Snatch that bottle off the shelve

You're trapped now with
Spiritual law
Spiritual law

Fiddle with your rosaries
Holy water only makes me bleed
Touch that cross to my head
It may burn but I won't be dead

To burn your rosaries
To burn it all
Death to us all

It is time to concentrate the mindless sheep
Don't be late, you'll be slammed
You'll be mauled, you'll be thrown into the walls
Everybody thinks it's cool tanning outside daddy's pool
I think it's way too late, time to regenerate

Your hurt infractions you know it
It's not too late it's not too late
Your hurt infractions you know it
There's one chance left
Get on your knees drink the wine
Chew the wafer

People screaming can I be dreaming
Is this the truth I can't tell
Whether this is Heaven or Hell
Wolfs bane and the sound of a silver bell

The air is thick
The smell of death is everywhere
It's all around but I won't submit to death
You can go with the

Man don't lie why do they cry
Man don't lie why do they cry
Man don't lie why do they cry

Ruling your lives
With such lies
Weak won't survive

It is time to concentrate the mindless sheep
Don't be late, you'll be slammed
You'll be mauled, you'll be thrown into the walls
Everybody thinks it's cool tanning outside daddy's pool
I think it's way too late, time to regenerate

You're hurt infractions you know it
It's not too late it's not too late
Your hurt infractions you know it
It's not too late it's not too late

Spiritual law, no way
I want to see Christ today
Spiritual law, no way
I want to see Christ today
Spiritual law, no way
I want to see Christ today
Spiritual law, no way
I want to see Christ today
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

long n,tests,ar[200000];
long calc[200000];
vector<long> t,vec[200000];
long l,r,ans;
long mapp[200000];
long c[105000][520];
long td;
bool nice[200000];

long gett(long x,long p)
{
 return c[p][mapp[x]];
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>tests;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 if (ar[i]<=100000)
  calc[ar[i]]++;
}

for (int i=1;i<=n;i++)
if (calc[i]>=i)
{
 t.push_back(i);
 nice[i]=1;
 mapp[i]=td;
 ++td;
}

for (int i=1;i<=n;i++)
{
    for (int j=0;j<t.size();j++)
     c[i][j]=c[i-1][j];
    if (ar[i]<=100000&&nice[ar[i]]==1)
     c[i][mapp[ar[i]]]++;
}

for (;tests;--tests)
{
 cin>>l>>r;
 ans=0;
 for (int i=0;i<t.size();i++)
 {long v=gett(t[i],r);
  if (v<t[i])continue;
  v-=gett(t[i],l-1);
  if (v==t[i])++ans;}
 cout<<ans<<"\n";
}

cin.get();cin.get();
return 0;}