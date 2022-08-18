/*
Outsmart the fever
And take us farther from
The killing life in capsules
A life that can't belong

So if I wake up dead to the world
With the helm at my command
The reaching out of this
Faced tomorrow in the eleventh hour
Beckoned closer
Now as nightfall sends it's grace
Cue to enter the insatiable ideal
Slam it shut but the portal pounding lingers
What it is, is time undone
Cannot falter in the security of labour
Was I supposed to believe?

Where did I sign?
Did I miss the auction?
Where went my life?
Where did I sign?
Did I miss the auction?

Went the half mile
Wondered when the resolution would come
Life became too solid
Diluted by the essence of denial
Caught in fire's eye
The self and filter that is I
My lip was venom
Words formed in my mouth
Hid beneath the tongue
Never to be seen

Where did I sign?
Did I miss the auction?
Where went my life?
Where did I sign?
Did I miss the auction?
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

long n,ar[20000];
vector<pair<long, long> > v[1000];
pair<long, long> par[500][500];
long need;
long a,b,val;
long m,ttl,s,rem;
long dp[500][500];
long ans,apos;
pair<long, long> tp;
vector<long> avec[500];

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>need;
for (int i=1;i<=n;i++)
 cin>>ar[i];

cin>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>val;
 for (int j=a;j<=b;j++)
  v[j].push_back(make_pair(val,i));
}

for (int i=1;i<=n;i++)
 sort(v[i].begin(),v[i].end());
 
for (int i=1;i<=n;i++)
 for (int j=0;j<=400;j++)
  dp[i][j]=-1e9;

dp[1][0]=0;
for (int i=1;i<=n;i++)
 for (int pday=0;pday<=400;pday++)
 {
  ttl=pday+ar[i];
  s=0;
  for (int u=0;u<=v[i].size();u++)
  {
   if (s>ttl-need)continue;
   rem=ttl-s-need;
   if (rem>ar[i])rem=ar[i];
   if (dp[i+1][rem]<dp[i][pday]+u)
   {
    dp[i+1][rem]=dp[i][pday]+u;
    par[i+1][rem]=make_pair(u,pday);
   }
   if (u<v[i].size())s+=v[i][u].first;
  }
 }

for (int i=0;i<=400;i++)
 if (dp[n+1][i]>ans){ans=dp[n+1][i];apos=i;}

cout<<ans<<endl;//" "<<apos<<endl;

for (int i=n+1;i-1;--i)
{
 tp=par[i][apos];
 apos=tp.second;
 for (int j=0;j<tp.first;j++)
  avec[i-1].push_back(v[i-1][j].second);
} 
for (int i=1;i<=n;i++)
{
 cout<<avec[i].size();
 for (int j=0;j<avec[i].size();j++)cout<<" "<<avec[i][j];
 cout<<endl;
}
cin.get();cin.get();
return 0;}