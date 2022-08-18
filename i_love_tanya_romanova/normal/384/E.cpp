/*
Baby, innocent
Is one day gonna be decadent
Prom Queen, Miss America
In the backseat in a pair of cuffs
Sixteen, little runaway
From the Five-O and you got away
From a small town with no scene
Looking for a shot on the big screen

Expectations
Go to hell
Expectations
Go to hell

Not so innocent
On the street hustling
Never be Miss America
In the backseat of a Celica
Crashing with a deadbeat
Living large on a love seat
In a small town, no scene
Turns out it was nothing but a pipe dream

Expectations
Go to hell
Expectations
Go to hell

Rich girl, wannabe
Bought a quick pick for the lottery
Watching TV with her boyfriend
Fell asleep, left the ticket on the nightstand
He stayed awake to see the ball drop
Turned it way down, and she never woke up
Grabbed the keys to her car in the back lot
Through a shot of Jack back, left with the jackpot

Expectations
Go to hell
Prom Queen, Miss America
In the backseat in a pair of cuffs

Expectations
Go to hell
Never be Miss America
In the backseat in a pair of cuffs
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