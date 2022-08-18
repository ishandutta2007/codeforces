/*
I'm diggin' my way
Yes, I'm diggin' my way to somethin'
I'm diggin' my way to somethin' better

I'm pushin' to stay
Yes, I'm pushin' to stay with somethin'
I'm pushin' to stay with something better

I'm sowin' the seeds, yes
Yes, I'm sowin' the seeds I've taken
Sowin' the seeds I take for granted

This thorn in my side
Yes, this thorn in my side is from the tree
This thorn in my side is from the tree I've planted
It tears me and I bleed and I bleed

Caught under, the wheels roll
I take that leash, yeah, I'm bleeding me
Can't stop to save my soul
I take the leash that's leading me

I'm bleeding me, I can't take it
Caught under, wheels roll the bleeding of me
Yes, of me, the bleeding of me

I'm caught under, wheels roll
I take the leach, hey, I'm bleeding me
I can't stop to save my soul
I take that leash that's leading me

I'm bleeding me, I can't take it
Caught under, wheels roll
The bleeding of me
The bleeding of me

I am the beast that bleeds the feast
I am the blood, I am release
Come make me pure, bleed me a cure
I'm caught, I'm caught, I'm caught under

Caught under, wheels roll
I take that leach, hey, I'm bleeding me
I can't stop to save my soul
I take the leash that's leading me

I'm bleeding me, I can't take it
I can't take it, I can't take it
No, the bleeding of me
No, feelin' me, come on and bleed me

I'm diggin' my way
Yes, I'm diggin' my way to somethin'
I'm diggin' my way to somethin' better

I'm pushin' to stay
Yes, I'm pushin' to stay with somethin'
I'm pushin' to stay with somethin' better
With somethin' better
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
/*
for (int i=1;i<=n;i++)
{
 vv.push_back(i);
}

bst=0;
do
{
 for (int i=1;i<=n;i++)
  used[i]=0;
 tans=0;
 for(int i=0;i<vv.size();i++)
 {
  long q=vv[i];
  used[q]=1;
  p1=q-1;
  b=1e9;
  while (p1>0&&used[p1]==1)--p1;
  if (p1>0)b=ar[p1];else b=0;
  p1=q+1;
  while (p1<=n&&used[p1]==1)++p1;
  if (p1<=n)b=min(b,ar[p1]);else b=0;
  tans+=b;
 }
 bst=max(bst,tans);
} while (next_permutation(vv.begin(),vv.end()));

cout<<bst<<endl;
for (int i=1;i<=n;i++)
 cout<<ar[i]<<" ";
 cout<<endl;*/
cin.get();cin.get();
return 0;}