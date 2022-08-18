/*
Sent from home overseas
and into the unknown
barely landed in the jungle
sent on first patrol

Sundown darkness falls
dig in for the night
ambushed in the dawn they came
the jungle's alive

I feel my fire starts to burn
the heat controlling my mind
berserk a savage running wild
within me the beast starts to roar

Now I'm ready to strike
a creature of the night
Into the fire
a flame of napalm strike

Sarge's down I'm in charge
VC's everywhere
overrun yet order airstrike
condemned us all to burn,

Napalm from above
burning friend and foe
chaos on the battlefield
the jungle's on fire

This place it's driving me insane
napalm it's burning us all
this fight no man will live to tell
within me my blood starts to boil

From above the airstrike came
and it burned the world below
napalm falling from the sky
and it leaves no man alive

I feel my fire starts to burn
the heat controlling my mind
napalm it's burning us alive
within me the beasts final roar
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
#define MAG 10000

using namespace std;

long n,k,ar[1<<20],s[1<<20];
long dp[55][444][444];
vector<pair<long, pair<long, long> > > segs;
long N;
long t1[1<<20],t2[1<<20];
long ts,ps;
long val1;
long val2;

long bsearch(long val)
{
  if (segs[0].first>val)
   return -1;
  long l,r;
  l=0;
  r=N-1;
  while (l<r)
  {
   long mid=l+r+1;
   mid/=2;
   if (segs[mid].first<=val)
    l=mid;
    else r=mid-1;
  }
  return l;
}

void build1(long v,long l,long r)
{
 if (l==r)
 {
  t1[v]=-1e9;
  return;
 }
 long mid=l+r;
 mid/=2;
 build1(v*2,l,mid);
 build1(v*2+1,mid+1,r);
 t1[v]=-1e9;
}

void build2(long v,long l,long r)
{
 if (l==r)
 {
  t2[v]=-1e9;
  return;
 }
 long mid=l+r;
 mid/=2;
 build2(v*2,l,mid);
 build2(v*2+1,mid+1,r);
 t2[v]=-1e9;
}

inline long get1(long v,long tl,long tr,long l,long r)
{
 //cout<<v<<"   "<<tl<<" "<<tr<<"  "<<l<<"   "<<r<<" "<<t1[v]<<endl;
 if (l>r)
  return -1e9;
 if (tl==l&&tr==r)
 return t1[v];
 long tm=tl+tr;
 tm/=2;
 long val1,val2;
 val1=get1(v*2,tl,tm,l,min(r,tm));
 val2=get1(v*2+1,tm+1,tr,max(tm+1,l),r);
// cout<<val1<<"  "<<val2<<endl;
 return max(val1,val2);
}

inline long get2(long v,long tl,long tr,long l,long r)
{
 if (l>r)
  return -1e9;
 if (tl==l&&tr==r)
 return t2[v];
 long tm=tl+tr;
 tm/=2;
 long val1,val2;
 val1=get2(v*2,tl,tm,l,min(r,tm));
 val2=get2(v*2+1,tm+1,tr,max(tm+1,l),r);
 return max(val1,val2);
}

inline void update1(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t1[v]=val;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)
 update1(v*2,tl,tm,ps,val);
 else update1(v*2+1,tm+1,tr,ps,val);
 t1[v]=max(t1[v*2],t1[v*2+1]);
}

inline void update2(long v,long tl,long tr,long ps,long val)
{
 if (tl==tr)
 {
  t2[v]=val;
  return;
 }
 long tm=tl+tr;
 tm/=2;
 if (ps<=tm)
 update2(v*2,tl,tm,ps,val);
 else update2(v*2+1,tm+1,tr,ps,val);
 t2[v]=max(t2[v*2],t2[v*2+1]);
}

long mapp[500][500];
long ans;

int main(){
//freopen("hiking.in","r",stdin);
//freopen("hiking.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 //ar[i]=rand();
 s[i]=s[i-1]+ar[i];   
}

for (int l=1;l<=n;l++)
{
 for (int r=l;r<=n;r++)
 {
  segs.push_back(make_pair(s[r]-s[l-1],make_pair(l,r)));
 }
}

sort(segs.begin(),segs.end());

for (int i=0;i<segs.size();i++)
mapp[segs[i].second.first][segs[i].second.second]=i;

N=segs.size();
build1(1,0,N-1);
build2(1,0,N-1);

for (int i=0;i<=k;i++)
 for (int l=1;l<=n;l++)
  for (int r=1;r<=n;r++)
  {
      dp[i][l][r]=-1e9;
  }

for (int i=1;i<=n;i++)
 for (int j=i;j<=n;j++)
  dp[1][i][j]=0;
  
for (int iter=2;iter<=k;iter++)
{

build1(1,0,N-1);
build2(1,0,N-1);

for (int l=1;l<=n;l++)
{
 if (l>=iter)
 for (int r=l;r<=n;r++)
 {
  ts=s[r]-s[l-1];
  ps=mapp[l][r];
 //cout<<ps<<"%"<<N<<endl;
  val1=get1(1,0,N-1,0,ps);
 // cout<<get1(1,0,N-1,0,0)<<endl;
  val2=get2(1,0,N-1,ps+1,N-1);
//  cout<<"^^"<<val1<<" "<<val2<<endl;
  val1=max(val1+ts,val2-ts);
  dp[iter][l][r]=val1;
 }
 for(int old=1;old<=l;old++)
 {
  val1=dp[iter-1][old][l];
  val1-=s[l]-s[old-1];
  ps=mapp[old][l];
 // cout<<"U1 "<<ps<<" "<<val1<<"   "<<ps<<" "<<iter<<endl;
  update1(1,0,N-1,ps,val1);
  val1=dp[iter-1][old][l];
  val1+=s[l]-s[old-1];
  ps=mapp[old][l];
//  cout<<"U2 "<<ps<<" "<<val1<<" "<<ps<<" "<<iter<<endl;
  update2(1,0,N-1,ps,val1);
 }
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=i;j<=n;j++)
 {
  cout<<dp[iter][i][j]<<" ";
 }
 cout<<endl;
}
cout<<endl;*/
}

ans=-1e9;
for (int l=1;l<=n;l++)
 for (int r=l;r<=n;r++)
  ans=max(ans,dp[k][l][r]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}