/*
This everflowing steram
Disappears without a trace
That everglowing dream
Never worth the lengthy chase

Not follow me
The leader of exploration
I'm the one that you obey
Command the chain into perfection
End your days in victory

Inspiration high
For the mission possible
Desperation low
For falling fathers
On your broken ribs
Behold the second coming
Since we drew the first breath
Sweetheart
We're in control for operation
Everblack...

Narrow minded ignorants
Come that way, I'll raise the flag
Hear them all forever chanting
Everblack

Picture this
The impact of soldiers blazing
Like a deadly tidal wave
A sight that's so amazing
It surely takes your breath away

Mass hysteria
We love the feeling
Monumentally
extremely arise
Like the crescent moon
That speaks to me
Behold the second coming
Since we drew the first breath
Sweetheart
We're in control for operation
Everblack...

Narrow minded ignorants
Come that way, I'll raise the flag
Hear the whole world chanting
Everblack

The future is now or never
A phase to overcome
Mercenary lives forever
We'll conquer one by one
Purple heart
The metal of honour is chosen
For the ones that slay the weak
Our mission everblasting
Ddestination bittersweet

This evergrowing dream
Disappears without a trace
Forever flowing steram
Runnung deep inside my veins

We're the brothers of slaughter
Operation Everblack
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

long n,m,v;
vector<pair<long, long>  >g;
set<pair<long, long> > was;
long rem;

void add_edge(long a,long b)
{
 if (a==b)return ;
 if (was.find(make_pair(a,b))!=was.end())return;
 if (g.size()==m)return;
 if (was.find(make_pair(b,a))!=was.end())return;
 was.insert(make_pair(a,b));
 was.insert(make_pair(b,a));
 g.push_back(make_pair(a,b));
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>v;
if (m<n-1||m>(n-1)*(n-2)/2+1)cout<<-1<<endl;
else
{
 if (v==1)rem=2;else rem=1;
 for (int i=1;i<=n;i++)
  if (i!=v)add_edge(v,i);
 for (int i=1;i<=n;i++)
  {
   if (g.size()==m)break;
   for (int j=1;j<=n;j++)
  {
   if (i!=rem&&j!=rem)add_edge(i,j);
  }
  }
  for (int i=0;i<g.size();i++)
   cout<<g[i].first<<" "<<g[i].second<<endl;
}

cin.get();cin.get();
return 0;}