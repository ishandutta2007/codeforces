/*
Passion in my eyes, I lived it everyday
But how could you go throw it all away?
In my dreams it's me and you, it's there I saw it all come true
As time went by faith in you grew, so one thing's left for me to do

I feel it burn inside, burning me like the rising sun
Lifted into the sky, took away the only thing I loved
I know after tonight all your power crumbles in my arms
So don't worry, I'll be fine, when my life ends, I'll leave this scar

And I felt down
I need you there every note and every word
Seems so hard to take
Finally, were destined

A smoking gun in hand, now don't you realize what you've done
Put a bullet in his back, your hero since you were so young
How could you kill the man who brought salvation through your pain
He must mean everything to end it all this shameful way

Passion in my eyes, I lived it everyday
But how could you go throw it all away?
In my dreams it's me and you, it's there I saw it all come true
As time went by faith in you grew, so one thing's left for me to do

I started here so young and helped you get along
Just did it for the love, and people healed through us
Don't live your life in vain, don't take it out on me
You're cracked, so just remember, I'm not your enemy
I don't deserve to fall this way, by a man who felt betrayed

I felt so down now you're around to rescue me
Every note and every word I'm listening, yeah
Sometimes problems seem too deep to take, too hard to take
Sometimes I cry thinking my future looks so bleak

Finally, together we were destined
I know what's best for us in the end
Someone hear me, someone stop me
Someone listen, why aren't you listening?

Passion in my eyes, I lived it everyday
But how could you go throw it all away?
In my dreams it's me and you, it's there I saw it all come true
As time went by faith in you grew, so one thing's left for me to do
In my dreams it's me and you, it's there I saw it all come true
As time went by faith in you grew, so one thing's left to finish you
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,a,b;
vector<long> g[200000];
set<pair<long, long> > done;
vector<pair<long, pair<long, long> > > ans;
long ptr[300000];

long dfs(long v)
{
// cout<<v<<endl;
 vector<long> dd;
 dd.reserve(16);
 for (;ptr[v]<g[v].size();ptr[v]++)
 {
  long q=g[v][ptr[v]];
//  ++ptr[v];
  pair<long, long> p=make_pair(min(v,q),max(v,q));
  if (done.find(p)!=done.end())continue;
  if (p.first>p.second)swap(p.first,p.second);
  done.insert(p);
  long t=dfs(q);
  if (t==0)
  dd.push_back(q);
  else
  {
   ans.push_back(make_pair(v,make_pair(q,t)));
  }
 }
 long t=dd.size()%2;
 for (int i=t;i<dd.size();i+=2)
 {
  long a,b;
  a=dd[i];
  b=dd[i+1];
  ans.push_back(make_pair(a,make_pair(v,b)));
  done.insert(make_pair(min(a,v),max(a,v)));
  done.insert(make_pair(min(b,v),max(b,v)));
 }
 if (dd.size()%2==0)return 0;
 done.insert(make_pair(min(dd[0],v),max(dd[0],v)));
 return dd[0];
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
if (m%2)
{
 cout<<"No solution"<<endl;
 return 0;
}
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

dfs(1);
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}

cin.get();cin.get();
return 0;}