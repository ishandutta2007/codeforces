/*
It's morning and I feel it
All the sins I was in last night
Dear Jesus, please save me
'Cause I think I've fallen down into the depths this time

Am I dreamin' or still sleepin'
I wonder if I'm ever gonna make it out
Now you're gone and I'm here and I feel so bitter
Waking up alive another day

It never seems easy when you'll find another day
Where I looked at what I'm facing, don't know if I can take it
And I could scream out loud but I'm wasting my time
This pain only reminds me I'm still alive

Now these feelings, they're creeping
Like a chill crawling up my spine
It's lonely, it's not easy
Coming home all alone each and every night

And as time goes by I feel so bitter
Waking up alive another day

It never seems easy when you'll find another day
Where I looked at what I'm facing, don't know if I can take it
I could scream out loud but I'm wasting my time
This pain only reminds me I'm still alive

Don't wake me up if there's gonna be hell to pay
All the weight of the world keeps pushing me down, pushing me down
So, just let me sleep even if I'm in too deep
Keep me locked in my dreams so I can't get out, I can't get out

It's been so hard but I'm doing much better
Waking up alive another day

It never seems easy when you'll find another day
Where I looked at what I'm facing, don't know if I can take it
And I could scream out loud but I'm wasting my time
This pain only reminds me I'm still alive

This pain only reminds me I'm still alive
This pain only reminds me I'm still alive
And I could scream out loud but I'm wasting my time
This pain only reminds me I'm still alive
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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define right adsgasgadsg
#define free adsgasdg
#define MAG 200

using namespace std;

long n,m,a[1<<19],b[1<<19],c[1<<19],ttl[1<<19];
vector<long> edges[1<<19];
vector<long> heavy,light;
long q,v1[1<<19],v2[1<<19],cur;
long w[1<<19],d[1<<19];
long qv1,qv2;
long ans[1<<19];
set<pair<long, long> > have_quer;
long done[1<<20];
long mapp[1<<20];
map<pair<long, long> ,long> quer_map;
vector<long> affected;
vector<pair<long, long> > to_check;
pair<long, long> tp;

long get(long x)
{
 if (x==w[x])
  return x;
 return w[x]=get(w[x]);
}

void merge(long a,long b)
{
 if (d[a]<d[b])
  swap(a,b);
 w[b]=a;
 if (d[a]==d[b])
  d[a]++;
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i]>>c[i];
 ttl[c[i]]++;
 edges[c[i]].push_back(i);
}

for (int i=1;i<=m;i++)
{
 if (ttl[i]>MAG)
 {
  heavy.push_back(i);
  continue;
 }   
 else
 {
  light.push_back(i);
 }
}

cin>>q;
for (int i=1;i<=q;i++)
{
 cin>>v1[i]>>v2[i];
 if (have_quer.find(make_pair(v1[i],v2[i]))!=have_quer.end())
 {
  done[i]=1;
  mapp[i]=quer_map[make_pair(v1[i],v2[i])];
  continue;
 }
 
 have_quer.insert(make_pair(v1[i],v2[i]));
 have_quer.insert(make_pair(v2[i],v1[i]));
 quer_map[make_pair(v1[i],v2[i])]=quer_map[make_pair(v2[i],v1[i])]=i;
}

// heavy

for (int qq=0;qq<heavy.size();qq++)
{
 cur=heavy[qq];
 for (int i=1;i<=n;i++)
  w[i]=i,
  d[i]=1;
  
 for (int i=0;i<edges[cur].size();i++)
 {
  long id=edges[cur][i];
  qv1=a[id];
  qv2=b[id];
  qv1=get(qv1);
  qv2=get(qv2);
  if (qv1==qv2)
   continue;
  merge(qv1,qv2);
 }
 
 for (int i=1;i<=q;i++)
 {
  qv1=get(v1[i]);
  qv2=get(v2[i]);
//  cout<<qv1<<"   "<<qv2<<"  "<<i<<endl;
  if (qv1==qv2)
   ans[i]++;
 }
}

// light
for (int qq=0;qq<light.size();qq++)
{
 affected.clear();
 cur=light[qq];
 for (int i=0;i<edges[cur].size();i++)
 {
  long id=edges[cur][i];
  affected.push_back(a[id]);
  affected.push_back(b[id]);
 }
 for (int  i=0;i<affected.size();i++)
 {
  long id=affected[i];
  w[id]=id;
  d[id]=1;
 }
 for (int i=0;i<edges[cur].size();i++)
 {
  long id=edges[cur][i];
  qv1=a[id];
  qv2=b[id];
  qv1=get(qv1);
  qv2=get(qv2);
  if (qv1==qv2)continue;
  merge(qv1,qv2);
 }
 to_check.clear();
 sort(affected.begin(),affected.end());
 for (int i=0;i<affected.size();i++)
 {
  if (i>0&&affected[i]==affected[i-1])continue;
  qv1=affected[i];
  qv2=get(qv1);
  to_check.push_back(make_pair(qv2,qv1));
 }
 sort(to_check.begin(),to_check.end());
 for (int i=0;i<to_check.size();i++)
 {
     for (int j=i+1;j<to_check.size()&&to_check[j].first==to_check[i].first;j++)
     {
      qv1=to_check[i].second;
      qv2=to_check[j].second;
      tp=make_pair(qv1,qv2);
      if (have_quer.find(tp)==have_quer.end())continue;
      int qu_id=quer_map[tp];
      ans[qu_id]++;
     }
 }
}

for (int i=1;i<=q;i++)
{
 if (done[i]==0)
  cout<<ans[i]<<endl;
  else
  cout<<ans[mapp[i]]<<endl;
}

cin.get();cin.get();
return 0;}