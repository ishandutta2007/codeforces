/*
I shall redeem myself from
The clutches that grasp at my inner self
No tomorrow will ease my oppression
My streak of hate leads my way

Look at me, my feelings turn
Stronger than hate
I can't decide on which way to turn
My choices are few and far between

Look at me, my feelings turn
Stronger than hate
I can't decide on which way to turn
My choices are few and far between

A lifetime of remorse
There's no place that I've ever been

I stand above their remains
My vengeance I have regained
I don't know what lies on the floor
I won't be locked up anymore

Standing here, I've lost all faith
I have no social equality
To live again would be a lie
My life is not worth the pain
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

set<pair<long, long> > arp;
long dist[1200][1200];
queue<pair<long, long> > qu;
vector<pair<long, long> > vv;
pair<long, long> tp;
long tx,ty;
long d;
set<pair<long, long> > beat[200000];
long n,m;
char ar[1200][1200];
set<pair<long,long> > ::iterator it;

vector<pair<long, long> > v;
long tocheck[1200][1200];
map<pair<long ,long> ,long> mapp;
long er,ans1,ans2;

void qcheck(long x,long y)
{
 if (ar[x][y]=='X')return;
 if (arp.find(make_pair(x,y))!=arp.end())return;
 arp.insert(make_pair(x,y));
 qu.push(make_pair(x,y));
 dist[x][y]=dist[tx][ty]+1;
}

void check(long x,long y)
{
 arp.clear();
 vv.push_back(make_pair(x,y));
 arp.insert(make_pair(x,y));
 dist[x][y]=0;
 qu.push(make_pair(x,y));
 while (qu.size())
 {
  tp=qu.front();
  tx=tp.first;
  ty=tp.second;
  qu.pop();
  if (dist[tx][ty]==d)continue;
  qcheck(tx-1,ty);qcheck(tx+1,ty);
  qcheck(tx,ty-1);qcheck(tx,ty+1);
 }
/* for (it=arp.begin();it!=arp.end();++it)
 {
  cout<<(*it).first<<" "<<(*it).second<<endl;
 }
 cout<<endl;
*/
 beat[vv.size()-1]=arp;
}

void solve1(long ps1,long ps2)
{
 if (ps1==ps2)return;
 long er=-1;
 for (int i=0;i<v.size();i++)
  if (beat[ps1].find(v[i])==beat[ps1].end()&&
  beat[ps2].find(v[i])==beat[ps2].end())
  er=i;
 if (er==-1)
 {
  ans1=ps1;
  ans2=ps2;
 }
}

void solve(long ps)
{
 er=-1;
 for (int i=0;i<v.size();i++)
  if (beat[ps].find(v[i])==beat[ps].end())er=i;
 if (er==-1)
 {
  for (int i=0;i<v.size();i++)
   if (beat[i].size()>1||i!=ps)er=i;
 }
 long tx,ty;
 tx=v[er].first;
 ty=v[er].second;
 for (int x=tx-d;x<=tx+d;x++)
  for (int y=ty-d;y<=ty+d;y++)
   if (x>=1&&x<=n&&y>=1&&y<=m&&ar[x][y]!='X')
   {
    solve1(ps,mapp[make_pair(x,y)]);
   }
}

int main(){
//freopen("dagger.in","r",stdin);
//freopen("dagger.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>d;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  cin>>ar[i][j];
  if (ar[i][j]=='R')v.push_back(make_pair(i,j));
 }

if (v.size()>400)
{
 cout<<-1<<endl;
 return 0;
}

for (int i=0;i<v.size();i++)
{
 for (int ti=v[i].first-8;ti<=v[i].first+8;ti++)
  for (int tj=v[i].second-8;tj<=v[i].second+8;tj++)
   if (ti>=1&&ti<=n&&tj>=1&&tj<=m)
   {
    if (abs(ti-v[i].first)+abs(tj-v[i].second)<=d&&ar[ti][tj]!='X')
     tocheck[ti][tj]=1;
   }
}

ans1=ans2=-1;

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (tocheck[i][j]){mapp[make_pair(i,j)]=vv.size();check(i,j);}

for (int i=0;i<vv.size();i++)
  if (ans1==-1)solve(i);

if (ans1==-1)
cout<<ans1<<endl;
else cout<<vv[ans1].first<<" "<<vv[ans1].second<<" "<<vv[ans2].first<<" "<<vv[ans2].second;

//cout<<ans1<<" "<<ans2<<endl;

cin.get();cin.get();
return 0;}