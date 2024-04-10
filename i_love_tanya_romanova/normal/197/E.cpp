/*
Well, it rains and it pours when you're out on your own
If I crash on the couch can I sleep in my clothes?
'Cause I've spent the night dancing I'm drunk, I suppose
If it looks like I'm laughing I'm really just asking to leave

This alone, you're in time for the show
You're the one that I need, I'm the one that you loathe
You can watch me corrode like a beast in repose
Cause I love all the poison and away with the boys in the band

I've really been on a bender and it shows
So why don't you blow me a kiss before she goes?

Give me a shot to remember
And you can take all the pain away from me
A kiss and I will surrender
The sharpest lives are the deadliest to lead

A light to burn all the empires
So bright the sun is ashamed to rise and be
In love with all of these vampires
So you can leave like the sane abandoned me

There's a place in the dark where the animals go
You can take off your skin in the cannibal glow
Juliet loves the beat and the lust it commands
Drop the dagger and lather the blood on your hands, Romeo

I've really been on a bender and it shows
So why don't you blow me a kiss before she goes?

Give me a shot to remember
And you can take all the pain away from me
A kiss and I will surrender
The sharpest lives are the deadliest to lead

A light to burn all the empires
So bright the sun is ashamed to rise and be
In love with all of these vampires
So you can leave like the sane abandoned me

Give me a shot to remember
And you can take all the pain away from me
A kiss and I will surrender
The sharpest lives are the deadliest to lead

A light to burn all the empires
So bright the sun is ashamed to rise and be
In love with all of these vampires
So you can leave like the sane abandoned me
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

long n,a[300000],b[300000];
vector<long> g[20000];
vector<long > vec;
long used[30000];
long ans[300000];
long dx,dy;
vector<long> sons[300000];
long sub[300000];

void dfs(long v)
{
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  sons[v].push_back(q);
  dfs(q);
  sub[v]+=sub[q];
 }
 sub[v]++;
}

void build(long v,vector<long> vec)
{
 long lm=0;
 for (int i=0;i<vec.size();i++)
  if (a[vec[i]]<a[vec[lm]]|(a[vec[i]]==a[vec[lm]]&&b[vec[i]]<b[vec[lm]]))
   lm=i;
 
 ans[vec[lm]]=v;
 vector<pair<double, long> >vv;
 for (int i=0;i<vec.size();i++)
  if (i!=lm)
  {
   dx=a[vec[i]]-a[vec[lm]];
   dy=b[vec[i]]-b[vec[lm]];
   vv.push_back(make_pair(atan2(dy+.0,dx+.0),vec[i]));
  }
 sort(vv.begin(),vv.end());
 long cur=0;
 
 for (int i=0;i<sons[v].size();i++)
 {
  vector<long> p;
  long q=sons[v][i];
  while (p.size()<sub[q]){p.push_back(vv[cur].second);++cur;}
  build(q,p);
 }
 
}

int main(){
//freopen("circular.in","r",stdin);
//freopen("circular.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<n;i++)
{
 long a,b;
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

dfs(1);
for (int i=1;i<=n;i++)
{
 cin>>a[i]>>b[i];
 vec.push_back(i);
}

build(1,vec);

for (int i=1;i<=n;i++)
{
 if (i-1)cout<<" ";
 cout<<ans[i];   
}
cout<<endl;

cin.get();cin.get();
return 0;}