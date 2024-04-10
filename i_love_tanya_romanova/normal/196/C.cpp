/*
Well your eyes are out of my soul, cold and tired
Open like a door to a winter's night
Silver sky becomes a background that begins to grey
Won't find me falling the second I awake

I thought I was going backwards
Walking down the lane
Found a foggy street
Now I'm not the same
Through a maze of walls and fences
Nothing can be heard
Where a million images are spun to just one

My memories are twisted here as I stand
They hold no meaning for me now without a sound
I can hear the bells are ringing calmly in my ears
Cross the fields that stretch forever
It won't disappear
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