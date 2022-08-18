/*
Sweet little words made for silence not talk
Young heart for love not heartache
Dark hair for catching the wind
Not to veil the sight of a cold world
Kiss while your lips are still red
While he's still silent
Rest while bosom is still untouched, unveiled
Hold another hand while the hand's still without a tool
Drown into eyes while they're still blind
Love while the night still hides the withering dawn
First day of love never comes back
A passionate hour's never a wasted one
The violin, the poet's hand
Every thawing heart plays your theme with care
Kiss while your lips are still red
While he's still silent
Rest while bosom is still untouched, unveiled
Hold another hand while the hand's still without a tool
Drown into eyes while they're still blind
Love while the night still hides the withering dawn

Kiss while your lips are still red
While he's still silent
Rest while bosom is still untouched, unveiled
Hold another hand while the hand's still without a tool
Drown into eyes while they're still blind
Love while the night still hides the withering dawn
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

long n,p[1<<20],le[1<<20];

pair<long, long> mov[1<<20];
pair<long,long> t[1<<20];
pair<long, long> jump[1<<18][21];
long cost[1<<18][21];
long tests;

pair<long, long> get(long v,long tl,long tr,long l,long r)
{
 if (l>r)return make_pair(0,0);
 if (tl==l&&tr==r)
  return t[v];
 long tm=tl+tr;
 tm/=2;
 pair<long, long> p1,p2;
 p1=get(v*2,tl,tm,l,min(r,tm));
 p2=get(v*2+1,tm+1,tr,max(l,tm+1),r);
 p1.first=max(p1.first,p2.first);
 p1.second=max(p1.second,p2.second);
 return p1;
}

void update(long v,long tl,long tr,long ps,pair<long, long> p)
{
 if (tl==tr)
 {
  t[v]=p;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)
  update(v*2,tl,tm,ps,p);
  else update(v*2+1,tm+1,tr,ps,p);
 t[v].first=max(t[v*2].first,t[v*2+1].first);
 t[v].second=max(t[v*2].second,t[v*2+1].second);
 return;
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
 cin>>p[i]>>le[i];

p[n+1]=p[n]+1;
le[n+1]=1;

for (int i=n;i;--i)
{
    long l,r,mid;
    
    l=i;
    r=n;
    while (l<r)
    {
     mid=l+r+1;
     mid/=2;
     if (p[mid]<=p[i]+le[i])
      l=mid;
     else
      r=mid-1;
    }
    pair<long, long> t;
    if (l==i)
    {
             t=make_pair(i,p[i]+le[i]);
    }
    else
    t=get(1,1,n,i+1,l);
    //!!!
    if (t.second<p[i]+le[i])
     t.second=p[i]+le[i];
    //------- 
    mov[i]=t;
    update(1,1,n,i,t);
}
/*
for (int i=1;i<=n;i++)
 {
  cout<<i<<" "<<mov[i].first<<" "<<mov[i].second<<endl;
 }
*/

for (int i=1;i<=n;i++)
{
 jump[i][0]=mov[i];
}

for (int lev=1;lev<=20;lev++)
{
 for (int i=1;i<=n;i++)
 {
  pair<long, long> pp=jump[i][lev-1];
  if (pp.first!=n)
  {
   long x1=pp.second;
   long nxt=pp.first+1;
   long x2=p[nxt];
   long ac=0;
   if (x2>x1)
    ac+=x2-x1;
    pair<long, long> tps=jump[nxt][lev-1];
    if (tps.second<x1)
     tps.second=x1;
    ac+=cost[nxt][lev-1]+cost[i][lev-1];
   jump[i][lev]=tps;
   cost[i][lev]=ac;
  }
  else
  {
   jump[i][lev]=jump[i][lev-1];
   cost[i][lev]=cost[i][lev-1];
  }
 }
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=0;j<=20;j++)
 {
  cout<<jump[i][j].first<<" "<<jump[i][j].second<<" "<<cost[i][j]<<"   ";
 }
 cout<<endl;
}*/

cin>>tests;
long ps1,ps2,ans;

for (;tests;--tests)
{
 cin>>ps1>>ps2;
 ans=0;
 for (int i=20;i>=0;--i)
 {
  if (jump[ps1][i].first<ps2)
  {
   ans+=cost[ps1][i];
   pair<long, long> tp=jump[ps1][i];
   long tx=tp.second;
   long nx=p[tp.first+1];
   if (nx>tx)ans+=nx-tx;
   ps1=tp.first+1;
  }
 }
 cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}