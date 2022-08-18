/*
The gasoline hits the streets igniting greedy eyes
Marching blind through the heat
Collapsing sites of decay mark the end of time
A planetary grave

Slashing and burning, crushing and drilling
Extinction is coming, the oil keeps spilling
Business as usual while toxins are killing
Destroying the land that our waste keeps on filling

Scenes of despair rising up through the noxious air
Cities abandoned left to decay
A world forgotten, pushed aside, left in disarray

The crunch of steel splitting rocks releases bloody soil
Logic is what we mock
The population booms and we must kill to live
The end of our reign is coming soon

Slashing and burning, crushing and drilling
Extinction is coming, the oil keeps spilling
Business as usual while toxins are killing
Destroying the land that our waste keeps on filling

Scenes of despair rising up through the noxious air
Cities abandoned left to decay
A world forgotten, as we live only to rot away

Theres photo-enforcement in our streets
The populous walks in defeat
Toxic gases fill our lungs
The bells of chaos have been rung

Welcome to the dying world
Humanity has lost control

Propaganda shapes our minds
Day to day we cross the line
The seeds of hate lie in the soil
Intoxicated by our spoils

Welcome to the dying world
Humanity has lost control

Strange beast kills more than it can feast on
Boundless need to push what it can reach for
Plastic lifestyle, surgical disaster
Sculpting the Earth
Out of control, it starts moving faster

A self destructive way of life
We continue forth with the end in sight
The blood of the beast is green
The oil of this death machine

Welcome to the dying world
Humanity has lost control
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,cost[300000],a,b;
vector<long> g[300000];
long arp[300000];
long lvl[300000];
long l1[300000],l2[300000];
long timer,tp,vert,ans;
long val;
long t1[2000000],t2[2000000],ad1[2000000],ad2[2000000];

void dfs(long v)
{
 ++timer;
 l1[v]=timer;
 arp[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (arp[q]==0){lvl[q]=lvl[v]+1;dfs(q);}
 }
 l2[v]=timer;
}

void update1 (int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    
    if (ad1[v]!=0){t1[v]+=ad1[v];ad1[v*2]+=ad1[v];ad1[v*2+1]+=ad1[v];ad1[v]=0;}
    
    if (l == tl && tr == r)
        ad1[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update1 (v*2, tl, tm, l, min(r,tm), add);
        update1 (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}
 
int get1 (int v, int tl, int tr, int pos) {
    
    if (ad1[v]!=0){t1[v]+=ad1[v];ad1[v*2]+=ad1[v];ad1[v*2+1]+=ad1[v];ad1[v]=0;}
    
    if (tl == tr)
        return t1[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
     return get1 (v*2, tl, tm, pos);
    else
     return get1 (v*2+1, tm+1, tr, pos);
}

void update2 (int v, int tl, int tr, int l, int r, int add) {
    if (l > r)
        return;
    
    if (ad2[v]!=0){t2[v]+=ad2[v];ad2[v*2]+=ad2[v];ad2[v*2+1]+=ad2[v];ad2[v]=0;}
    
    if (l == tl && tr == r)
        ad2[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update2 (v*2, tl, tm, l, min(r,tm), add);
        update2 (v*2+1, tm+1, tr, max(l,tm+1), r, add);
    }
}
 
int get2 (int v, int tl, int tr, int pos) {
    
    if (ad2[v]!=0){t2[v]+=ad2[v];ad2[v*2]+=ad2[v];ad2[v*2+1]+=ad2[v];ad2[v]=0;}
    
    if (tl == tr)
        return t2[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return get2 (v*2, tl, tm, pos);
    else
        return get2 (v*2+1, tm+1, tr, pos);
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
cin>>cost[i];
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
dfs(1);
/*
for (int i=1;i<=n;i++)
cout<<lvl[i]<<" "<<i<<" "<<l1[i]<<" "<<l2[i]<<endl;

*/
for (int i=1;i<=m;i++)
{
 cin>>tp;
 if (tp==2)
 {
  cin>>vert;
//  ans=cost[vert];
  ans=0;
  if (lvl[vert]%2==0)ans+=get1(1,1,n,l1[vert]);else ans-=get1(1,1,n,l1[vert]);
  if (lvl[vert]%2==1)ans+=get2(1,1,n,l1[vert]);else ans-=get2(1,1,n,l1[vert]);
//  cout<<ans<<endl;
 //ans/=2;
 ans+=cost[vert];
  cout<<ans<<endl;
 }
 else
 {
  cin>>vert;
  cin>>val;
  if (lvl[vert]%2==0)
  update1(1,1,n,l1[vert],l2[vert],val);
  else 
  update2(1,1,n,l1[vert],l2[vert],val);
  
/*  if (lvl[vert]%2==1)
  update2(1,1,n,l1[vert],l2[vert],val);
  else update2(1,1,n,l1[vert],l2[vert],-val);*/
 }
}

cin.get();cin.get();
return 0;}