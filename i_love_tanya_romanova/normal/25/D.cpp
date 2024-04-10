/*
What were all those dreams we shared
those many years ago?
What were all those plans we made now
left beside the road?
Behind us in the road

More than friends, I always pledged
cause friends they come and go
People change, as does everything
I wanted to grow old
I just want to grow old

Slide up next to me
I'm just a human being
I will take the blame
But just the same
this is not me

You see?
Believe...

I'm better than this
Don't leave me so cold
I'm buried beneath the stones
I just want to hold on
I know I'm worth your love

Enough...
I don't think
there's such a thing

It's my fault now
Having caught a sickness in my bones
How it pains to leave you here
With the kids on your own
Just don't let me go

Help me see myself
cause I can no longer tell
Looking out from the inside
of the bottom of a well

It's hell...
I yell...

But no one hears before I disappear
whisper in my ear
Give me something to echo
in my unknown future's ear

My dear...
The end
comes near...
I'm here...
But not much longer.
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,w[200000];
long a,b;
vector<long> vec;
vector<pair<long, long > > g,ans;
long gett(long x)
{
 while (x!=w[x])x=w[x];
 return x;
}

void merge(long a,long b)
{
 a=gett(a);
 b=gett(b);
 if (rand()%2)w[a]=b;else w[b]=a;
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
w[i]=i;

for (int i=1;i<n;i++)
{
 cin>>a>>b;
 if (gett(a)==gett(b))
 {
  g.push_back(make_pair(a,b));
 }
 else merge(a,b);
}

for(int i=1;i<=n;i++)
{
 if (w[i]==i) vec.push_back(i);
}
for (int i=1;i<vec.size();i++)
 ans.push_back(make_pair(vec[i],vec[0]));

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 cout<<g[i].first<<" "<<g[i].second<<" "<<ans[i].first<<" "<<ans[i].second<<endl;
}
cin.get();cin.get();
return 0;}