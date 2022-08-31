/*
A fugitive from unreality
No sign of my god damned serenity
Lost in these barren lands
That have nothing I demand
Had to look for something new
And that day I found you
I found you
I found you

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

A quasar from reality
With damaged mentality
I'll start editing your life
Replace the captain of your brain ship
Before we set sail for the fail

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

My destiny outruns me
And I can't find that key
To lock up everything that's bad inside of me
Don't you disagree
That your life would be so much better
Without me, that isn't hard to see
hard to see

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about

Living in a house of cards
Waiting for it all to fall
Hope for the best plan for the worst
That's what my life is all about
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

using namespace std;

long n,x[1<<20],y[1<<20];
vector<long> v;
string st[1<<20];
map<long, long> mapp;
long cnt;
map<long, long> rmap;
long tests,ps;
pair<long, long> tp;
set<long> sett[1<<19];
long maxy[1<<20];

pair<long, long> solve(long v,long tl,long tr,long l,long r,long li)
{
 if (l>r)return make_pair(-1,-1);
 if (r<tl)return make_pair(-1,-1);
 
 if (maxy[v]<li)return make_pair(-1,-1);
  
 if (tl==tr)
 {
  set<long >::iterator it;
  it=sett[v].lower_bound(li);
  return make_pair(tl,(*it));
 }
 long tm;
 tm=tl+tr;
 tm/=2;
 pair<long, long> p1;
 p1=solve(v*2,tl,tm,l,min(r,tm),li);
 if (p1.first!=-1)
  return p1;
 p1=solve(v*2+1,tm+1,tr,max(tm+1,l),r,li);
 return p1;
}

void update1(long v,long l,long r,long x,long y)
{
 if (l==r){sett[v].insert(y);set<long>::iterator it;
 it=sett[v].end();--it;maxy[v]=(*it);return;}
 long m=l+r;
 m/=2;
 if (x<=m)
  update1(v*2,l,m,x,y);
  else
  update1(v*2+1,m+1,r,x,y);
  maxy[v]=max(maxy[v*2],maxy[v*2+1]);
  
}

void update2(long v,long l,long r,long x,long y)
{
 if (l==r){
 sett[v].erase(y);set<long>::iterator it;
 it=sett[v].end();if (it==sett[v].begin())maxy[v]=-1;else {--it;maxy[v]=(*it);}return;}
 long m=l+r;
 m/=2;
 if (x<=m)
  update2(v*2,l,m,x,y);
  else
  update2(v*2+1,m+1,r,x,y);
 maxy[v]=max(maxy[v*2],maxy[v*2+1]);
}

void build(long v,long l,long r)
{
 maxy[v]=-1;
 if (l==r)return;
 long m=l+r;
 m/=2;
 build(v*2,l,m);
 build(v*2+1,m+1,r);
}

int main(){
//freopen("alter.in","r",stdin);
//freopen("alter.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>st[i]>>x[i]>>y[i];
 v.push_back(x[i]);
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 if (i>0&&v[i]==v[i-1])continue;
 mapp[v[i]]=cnt+1;
 ++cnt;
 rmap[cnt]=v[i];
}

tests=n;
n=cnt;
build(1,1,n);

for (int i=1;i<=tests;i++)
{
 if (st[i]=="add")
 {
  ps=mapp[x[i]];
  update1(1,1,n,ps,y[i]);
 }
 if (st[i]=="remove")
 {
  ps=mapp[x[i]];
  update2(1,1,n,ps,y[i]);
 }
 if (st[i]=="find")
 {
  ps=mapp[x[i]];
  tp=solve(1,1,n,ps+1,n,y[i]+1);
  if (tp.first!=-1){tp.first=rmap[tp.first];
  cout<<tp.first<<" "<<tp.second<<"\n";}
  else cout<<-1<<"\n";
 }
}
cin.get();cin.get();
return 0;}