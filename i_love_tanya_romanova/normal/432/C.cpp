/*
  ,
  ,
     ...

:
     ',
    ,
  ,
    ,
     .

  
  .
      ...



  ,
  ,
  ,  ...


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

long n,ar[200000],pr[200000];
vector<long> pv;
set<long> primes;
set<long> ::iterator it;
vector<pair<long,long> > ans;
long ps[200000];
long dist,val;

void doswap(long a,long b)
{
 swap(ar[a],ar[b]);
 swap(ps[ar[a]],ps[ar[b]]);
 ans.push_back(make_pair(a,b));
}

long solve(long x)
{
 if (x==1)return 2;
 if (x==0)return 0;
 long q=0;
 while (q+1<pv.size()&&pv[q+1]<=x)++q;
 return solve(x-pv[q])+1;
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 ps[ar[i]]=i;
}

pr[1]=1;
for (int i=2;i<=100000;i++)
 if (pr[i]==0)
  for (int j=i*2;j<=100000;j+=i)
   pr[j]=1;

for (int i=1;i<=100000;i++)
 if (pr[i]==0) {pv.push_back(i);primes.insert(i);}

/*
for (int num=1;num<=100000;num++)
{
long q=solve(num); 
 if (q>4)cout<<num<<" "<<q<<endl;
}*/

for (int i=1;i<=n;i++)
{
 while (true)
 {
  if (ar[i]==i)break;
  dist=ps[i]-i+1;
  it=primes.upper_bound(dist);
  --it;
  val=(*it);
  doswap(ps[i]-val+1,ps[i]);
 }
}

cout<<ans.size()<<endl;
for (int i=0;i<ans.size();i++)
cout<<ans[i].first<<" "<<ans[i].second<<endl;

cin.get();cin.get();
return 0;}