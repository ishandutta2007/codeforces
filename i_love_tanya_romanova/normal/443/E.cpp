/*
Yea ho
Yea ho

The faint blaze of the candle of my life
Slowly dying like a fire in a pouring rain
No sparks of hope inside
No shooting stars on my sky
On broken wings, no flying high

Another night, another demise
Cadaverous wind blowing cold as ice
You'll let the wind blow out the light
'Cause it gets more painful everytime I die

Out of strength to fight
I cannot take another night
I cannot take it no more
Lust of light slips through my fingers
Like blood on my arms
Black candle wax has buried me

Another night, another demise
Cadaverous wind blowing cold as ice
You'll let the wind blow out the light
'Cause it gets more painful everytime I die 
*/

#pragma comment(linker, "/STACK:16777216")
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

long n,ar[600000];
set<pair<long, long> > s;
long c[600000];
long long ans;
vector<long> vv;
long bst,used[2000],tans,p1,p2;
set<pair<long, long> >::iterator it;
long v;
long l[600000],r[600000];
long cur;
long b;
set<long> nice;
set<long>::iterator it1;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
long q;
//cin>>q;
srand(q);
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
//ar[i]=rand()%10;
}

for (int i=1;i<=n;i++)
 l[i]=i-1,r[i]=i+1;

for (int i=1;i<=n;i++)
 c[i]=min(ar[l[i]],ar[r[i]]);

for (int i=1;i<=n;i++)
 s.insert(make_pair(c[i],i));

for (int i=1;i<=n;i++)
 if (ar[i]<=ar[i-1]&&ar[i]<=ar[i+1]) 
  nice.insert(i);
  

while (s.size()>0)
{
 if (nice.size()>0)
 {
 it1=nice.begin();
 ans+=c[*it1];
 v=(*it1);
 nice.erase(it1);
 s.erase(make_pair(c[v],v));
 if (l[v]>0){if (nice.find(l[v])!=nice.end())nice.erase(l[v]);s.erase(make_pair(c[l[v]],l[v]));}
 if (r[v]<=n){if (nice.find(r[v])!=nice.end())nice.erase(r[v]);s.erase(make_pair(c[r[v]],r[v]));}
 if (l[v]>0)
 {
  cur=l[v];
  r[cur]=r[v];
  c[cur]=min(ar[l[cur]],ar[r[cur]]);
  s.insert(make_pair(c[cur],cur));
  if (ar[l[cur]]>=ar[cur]&&ar[r[cur]]>=ar[cur])nice.insert(cur);
 }
 if (r[v]<=n)
 {
  cur=r[v];
  l[cur]=l[v];
  c[cur]=min(ar[l[cur]],ar[r[cur]]);
  s.insert(make_pair(c[cur],cur));
  if (ar[l[cur]]>=ar[cur]&&ar[r[cur]]>=ar[cur])nice.insert(cur);
 }
 continue;
 }
 
 it=s.end();
 --it;
 ans+=(*it).first;
 v=(*it).second;
 /*i<=5;i++)
 cout<<l[i]<<" "<<r[i]<<endl;
 cout<<endl;
 */
 s.erase(it);
 if (l[v]>0){if (nice.find(l[v])!=nice.end())nice.erase(l[v]);s.erase(make_pair(c[l[v]],l[v]));}
 if (r[v]<=n){if (nice.find(r[v])!=nice.end())nice.erase(r[v]);s.erase(make_pair(c[r[v]],r[v]));}
 if (l[v]>0)
 {
  cur=l[v];
  r[cur]=r[v];
  c[cur]=min(ar[l[cur]],ar[r[cur]]);
  s.insert(make_pair(c[cur],cur));
  if (ar[l[cur]]>=ar[cur]&&ar[r[cur]]>=ar[cur])nice.insert(cur);
 }
 if (r[v]<=n)
 {
  cur=r[v];
  l[cur]=l[v];
  c[cur]=min(ar[l[cur]],ar[r[cur]]);
  s.insert(make_pair(c[cur],cur));
  if (ar[l[cur]]>=ar[cur]&&ar[r[cur]]>=ar[cur])nice.insert(cur);
 }
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}