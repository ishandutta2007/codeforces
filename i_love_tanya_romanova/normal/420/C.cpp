/*
Erase the day escape
Forgotten future lays ahead
Doomed to stay
Trapped in a time
Unfamiliar frozen

Endless sea of despair
Storm clouds drawing in
A constant battle
Sailing on
Lost in the confusion

Drift away
Sunshine takes control
Drift away
Sunshine blinding
Sunshine disappears
Frozen

Empty words take hold
Closing in
Frozen
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

long n,m,a,b;
long deg[500000];
set<pair<long, long> > ups;
set<pair<long, long> > ::iterator it;
long p;
pair<long, long> tp;
long long ans;
vector<long> v;
map<pair<long, long> ,long> calc;

long tsolve(long x)
{ 
 if (v.size()==0)return 0;
 if (v[0]>x)return 0;
 long l,r;
 l=0;
 r=v.size()-1;
 while (l<r)
 {
  long mid=l+r+1;
  mid/=2;
  if (v[mid]<=x)l=mid;
  else r=mid-1;
 }
 return l+1;
}

long solve(long x)
{
 return v.size()-tsolve(x);
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>p;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 if (a>b)swap(a,b);
 calc[make_pair(a,b)]++;
 ups.insert(make_pair(a,b));
 deg[a]++;
 deg[b]++;
}

for (int i=1;i<=n;i++)
{
 v.push_back(deg[i]);
}
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 ans+=solve(p-v[i]-1);
 //cout<<ans<<endl;
}
//cout<<ans<<endl;
//ans/=2;

for (it=ups.begin();it!=ups.end();++it)
{
 tp=(*it);
 a=tp.first;b=tp.second;
 if (deg[a]+deg[b]>=p&&deg[a]+deg[b]-calc[make_pair(a,b)]<p)ans-=2;  
}
for (int i=1;i<=n;i++)
 if (deg[i]*2>=p)ans--;
cout<<ans/2<<endl;

cin.get();cin.get();
return 0;}