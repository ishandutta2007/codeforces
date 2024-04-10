/*
Need more and more
Tainted misery
Bleed, battle scars
Chemical affinity

Reign, legacy
Innocence corrode
Stain or rot away
Catatonic overload

Choke, asphyxia
Snuff reality
Scorch, kill the light
Incinerate celebrity

Reaper, butchery
Karma amputee
Bloodline, redefine
Death contagious deity
Oh yeah

Hooked into this deceiver
Need more and more
Into the endless fever
Need more and more

New consequence machine
You burn through all your gasoline
Asylum overtime, never mind
You've reached the end of the line

Time, choke the clock
Steal another day
Die, faithfully
Narcissistic fade away

Twisted, jump the rail
Shatter the crowd below
Breaker, chase the ghost
From latest high to all time low

Hooked into this deceiver
Need more and more
Into the endless fever
Need more and more

New consequence machine
You burn through all your gasoline
Asylum overtime, never mind
You've reached the end of the line

Drop the hourglass of time
Spilling sand, we will not find
As we gather here today
We bid farewell

The slave becomes the master
The slave becomes the master
The slave becomes the master, yeah

The slave becomes the master
Need more and more
Right now and ever after
Need more and more

New consequence machine
You burn through all your gasoline
Asylum overtime, never mind

Dead hourglass of time
Sand, we will not ever find
We gather here today, say goodbye
'Cause you've reached the end of the line

The end of the line
The end of the line
The end of the line
You've reached the end of the line
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
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg

using namespace std;

long n,m,a[1<<20],b[1<<20],c[1<<20],dist[1<<20],bad[1<<20];
vector<long> g[1<<20];
queue<long> qu;
long temp,cost,par[1<<20];
long cur,par1[1<<20],used[1<<20];
vector<long> ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=0;i<m;i++)
{
 cin>>a[i]>>b[i]>>c[i];
 g[a[i]].push_back(i);
 g[b[i]].push_back(i);
}

for (int i=1;i<=n;i++)
 dist[i]=1e9;

qu.push(1);
dist[1]=0;
bad[1]=0;

while (qu.size())
{
 temp=qu.front();
 qu.pop();
 for (int i=0;i<g[temp].size();i++)
 {
  long id=g[temp][i];
  long bb;
  if (a[id]==temp)
   bb=b[id];
  else
   bb=a[id];
  cost=1-c[id]+bad[temp];
  if (dist[bb]>dist[temp]+1||(dist[bb]==dist[temp]+1&&bad[bb]>cost))
  {
   if (dist[bb]>dist[temp]+1)
   {
    qu.push(bb);
   }
   dist[bb]=dist[temp]+1;
   bad[bb]=cost;
   par[bb]=temp;
   par1[bb]=id;
  } 
 }
}

//cout<<dist[n]<<" "<<bad[n]<<endl;

cur=n;
while (cur!=1)
{
 used[par1[cur]]=1;
 cur=par[cur];
}

for (int i=0;i<m;i++)
{
 if (used[i]!=c[i])
  ans.push_back(i);
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
{
 long id=ans[i];
 cout<<a[id]<<" "<<b[id]<<" "<<1-c[id]<<endl;
}
cin.get();cin.get();
return 0;}