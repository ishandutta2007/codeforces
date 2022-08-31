/*
See my sorrow
My tears when they fall
Feel my anguish
Where's my shelter when I am cold?

My eyes seek something
But finds nothing at all
My souls screams for mercy
Where's my guidance when I'm lost?

The will I had ain't strong enough
The strength I seek ain't there
And my world is dead, my future's broken
'Cause it all stays the same

They're coming, they're coming
They're coming, they're coming
They're coming, they're coming
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

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

long n,m,l1[300000],l2[300000],x1[300000],y1[300000],x2[300000],y2[300000];
long l,r,mid;
map<long, long> mapp;
vector<long> ys,uy;
vector<pair<pair<long,long>, pair<long, long> > > evs;

class Fenwick
{
 long long *m,*mt,N;
 public:
 Fenwick(long n);
 Fenwick(long long a[],long n);
 void add_range(long l,long long d);
 void add_range(long l,long r,long long d);
 long long sum(long r);
 long long sum(long l,long r);
};

Fenwick::Fenwick(long n)
{
 N=n;
 m=new long long[N];
 mt=new long long[N];
 for (int i=0;i<n;i++)
 m[i]=mt[i]=0;
}

void Fenwick::add_range(long r,long long d)
{
 if (r<0)return;
 for (int i=r;i>=0;i=(i&(i+1))-1)mt[i]+=d;
 for (int i=r|(r+1);i<N;i|=i+1)m[i]+=d*(r-(i&(i+1))+1);
}

void Fenwick::add_range(long l,long r,long long d)
{
 add_range(r,d);
 add_range(l-1,-d);
}

long long Fenwick::sum(long r)
{
 if (r<0)return 0;
 long long res=0;
 for (int i=r;i>=0;i=(i&(i+1))-1)res+=m[i]+mt[i]*(i-(i&(i+1))+1);
 for (int i=r|(r+1);i<N;i|=i+1)res+=mt[i]*(r-(i&(i+1))+1);
 return res;
}

long long Fenwick::sum(long l,long r)
{
 return sum(r)-sum(l-1);
}

bool solve(long val)
{
 Fenwick f(300000);
 vector<long> ys;
 for (int i=1;i<=n;i++)
 {
  if (l1[i]>=val*2)
  {
   ys.push_back(y1[i]+val);
   ys.push_back(y1[i]+l1[i]-val);
  }
 }
 for (int i=1;i<=m;i++)
 {
  if (l2[i]>=val*2)
   ys.push_back(y2[i]);
 }
 mapp.clear();
 sort(ys.begin(),ys.end());
 uy.clear();
 
 for (int i=0;i<ys.size();i++)
 {
  if (i==0||ys[i]!=ys[i-1])
  {
   uy.push_back(ys[i]);
   mapp[ys[i]]=uy.size();
  }
 }
 
 evs.clear();
 
 for (int i=1;i<=n;i++)
 {
  if (l1[i]>=val*2)
  {
   evs.push_back(make_pair(make_pair(x1[i],1),make_pair(mapp[y1[i]+val],mapp[y1[i]+l1[i]-val])));
  }
 }
 for (int i=1;i<=m;i++)
 {
  if (l2[i]>=val*2)
  {
   evs.push_back(make_pair(make_pair(x2[i]+val,0),make_pair(mapp[y2[i]],mapp[y2[i]])));
   evs.push_back(make_pair(make_pair(x2[i]+l2[i]-val,2),make_pair(mapp[y2[i]],mapp[y2[i]])));
  }
 }
 sort(evs.begin(),evs.end());
 
 for (int i=0;i<evs.size();i++)
 {
  if (evs[i].first.second!=1)
  {
   f.add_range(evs[i].second.first,evs[i].second.second,1-evs[i].first.second);
  }
  else
  {
   long t=f.sum(evs[i].second.first,evs[i].second.second);
   if (t>0)return true;
  }
 }
 return false;
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>x1[i]>>y1[i]>>l1[i];
}
for (int i=1;i<=m;i++)
{
 cin>>x2[i]>>y2[i]>>l2[i];
}

l=0;
r=2e9;
while (l<r)
{
long mid=l+r+1;
mid/=2;
if(solve(mid))
l=mid;
else r=mid-1;
}
cout<<l<<endl;

cin.get();cin.get();
return 0;}