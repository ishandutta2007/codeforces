/*
Winding your way down on Baker Street
Light in your head and dead on your feet
Another crazy day, you drink the night away
And forget about everything

This city's dance makes you feel so cold
Its got so many people, but its got no soul
And its taken you so long to find out you were wrong
When you thought it had everything

You used to think that it was so easy
You used to say that it was so easy
But you're trying, you're trying now

Another year and then you'll be happy
Just one more year and then you'll be happy
But you're crying, you're crying now

Way down the street there's a light in his place
He opens the door, he's got that look on his face
And he asks where you've been
You tell him who you've seen
And you talk about everything

He's got this dream about buying some land
He's gonna give up the booze and the one night stands
And then he'll settle down in this quiet little town
And forget about everything

But you know he'll always keep moving
You know he's never gonna stop moving
'Cause he's rolling, he's a rolling stone

When you wake up, it's a new morning
The sun is shining, it's a new morning
But you're going, you're going home
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

string st;
char tp[1<<19];
long n;
long lvl[1<<19];
long l[1<<19],r[1<<19];
set<pair<long, long> > s;
set<pair<long, long> > ::iterator it;
long a,b;
vector<pair<long, long> > ans;

int main(){
//freopen("magic.in","r",stdin);
//freopen("magic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
cin>>st;
for (int i=1;i<=n;i++)
 tp[i]=st[i-1];

for (int i=1;i<=n;i++)
 cin>>lvl[i];

for (int i=1;i<=n;i++)
{
 l[i]=i-1;
 r[i]=i+1;
}

for (int i=1;i<n;i++)
{
 if (tp[i]!=tp[i+1])
 {
 s.insert(make_pair(abs(lvl[i]-lvl[i+1]),i));
 }
}

while (s.size())
{
 it=s.begin();
 a=(*it).second;
 b=r[a];
 s.erase(it);
 ans.push_back(make_pair(a,b));
 if (l[a]!=0&&tp[l[a]]!=tp[a])
  s.erase(make_pair(abs(lvl[l[a]]-lvl[a]),l[a]));
 if (r[b]!=n+1&&tp[r[b]]!=tp[b])
  s.erase(make_pair(abs(lvl[r[b]]-lvl[b]),b));
 if (l[a]!=0&&r[b]!=n+1&&tp[l[a]]!=tp[r[b]])
  s.insert(make_pair(abs(lvl[l[a]]-lvl[r[b]]),l[a]));
 if (l[a]!=-1)
  r[l[a]]=r[b];
 if (r[b]!=n+1)
  l[r[b]]=l[a];
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

cin.get();cin.get();
return 0;}