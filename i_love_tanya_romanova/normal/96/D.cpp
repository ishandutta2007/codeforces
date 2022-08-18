/*
Take my eyes the things I've seen in this world coming to an end
My reflection fades, I'm weary of these earthly bones and skin
You may pass through me and leave no trace, I have no mortal face
Solar winds are whispering, you may hear me call

We can shed our skins and swim into the darkened void beyond
We will dance among the world that orbit stars, they're on our side
All the oxygen that trapped us in a carbon spider's web
Solar winds are whispering, you may hear the sirens of the dead

Left the elders to their parley meant to satisfy our lust
Leaving Damocles still hanging over all their promised trust
Walk away from freedoms offered by their jailers in their cage
Step into the light startripping over mortals in their rage

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We are, with the Goddess of the sun tonight

The preacher loses face with Christ
Religion's cruel device is gone
Empty flesh and hallowed bones
Make pacts of love but die alone

The crucible of pain will forge
The blanks of sin, begin again
You are free to choose a life to live
Or one that's left to lose

Virgins in the teeth of God are meat and drink to feed the damned
You may pass through me and I will feel the life that you live less
Step into my light startripping, we will rage against the night
Walk away from comfort offered by your citizens of death

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We're one with the goddess of the sun tonight

Take my eyes for what I've seen
I will give my sight to you
You are free to choose whatever
Life to live or life to lose

Whatever God, you know
He knows you, better than you believe
In your once and future grave
You'll fall endlessly deceived

Look into our face reflected in the moon glow in your eyes
Remember you can choose to look but not to see and waste your hours
You believe you have the time but I tell you your time is short
See your past and future all the same and it cannot be bought

Starblind - with sun
The stars are one
We are the light that brings the end of night

Starblind - with sun
The stars are one
We're one with the Goddes of the sun tonight

Take my eyes for what I've seen
I will give my sight to you
You are free to choose whatever
Life to live or life to lose

Whatever God, you know
He knows you, better than you believe
In your once and future grave
You'll fall endlessly deceived

The preacher loses face with Christ
Religion's cruel device is gone
Empty flesh and hollow bones
Make pacts of love but die alone

The crucible of pain will forge
The blanks of sin, begin again
You are free to choose a life to live
Or one that's left to lose
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

long long n,m,start,fin,a,b,c,
v1[200000],v2[200000];
vector<pair<long long,long long> > g[20000];
long long dist[200000];
set<pair<long long, long long> > ::iterator it;
set<pair<long long, long long> > sett;
long long qv;
pair<long long, long long> tp;
long long tc;
long long d[1200][1200];
long long bst,bp;
long long ans[20000];
long long used[200000];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>start>>fin;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 g[a].push_back(make_pair(b,c));
 g[b].push_back(make_pair(a,c));
}

for (int i=1;i<=n;i++)
 cin>>v1[i]>>v2[i];
 
for (int st=1;st<=n;st++)
{
 for (int i=1;i<=n;i++)
  dist[i]=1e18;
 dist[st]=0;
 sett.clear();
 for (int i=1;i<=n;i++)
  sett.insert(make_pair(dist[i],i));
  
 for (int iter=1;iter<=n;iter++)
 {
  it=sett.begin();
  tp=(*it);
  sett.erase(it);
  qv=tp.second;
  for (int i=0;i<g[qv].size();i++)
  {
   long long q=g[qv][i].first;
   long long c=g[qv][i].second;
   tc=c+dist[qv];
   if (dist[q]>tc)// upd
   {
    sett.erase(make_pair(dist[q],q));
    dist[q]=tc;
    sett.insert(make_pair(dist[q],q));
   }
  }
 }
 for (int i=1;i<=n;i++)
  if (dist[i]>v1[st])d[st][i]=1e18;
  else d[st][i]=v2[st];
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
  cout<<d[i][j]<<" ";
 cout<<endl;
}*/
for (int i=1;i<=n;i++)
 ans[i]=1e18;
ans[start]=0;

for (int iter=1;iter<=n;iter++)
{
 bst=bp=1e18+1e12;
 for (int i=1;i<=n;i++)
 {
  if (used[i]==0&&ans[i]<bst)
  {
   bst=ans[i];
   bp=i;
  }
 }
 used[bp]=1;
 for (int i=1;i<=n;i++)
  if (d[bp][i]+bst<ans[i])
   ans[i]=d[bp][i]+bst;
}
if (ans[fin]>1e17)ans[fin]=-1;
cout<<ans[fin]<<endl;

cin.get();cin.get();
return 0;}