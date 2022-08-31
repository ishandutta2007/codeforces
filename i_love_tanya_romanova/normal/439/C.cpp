/*
My waves are resonating towards the unknown,
Trapped underneath;
Soon I'll break through,

I turn to vapour and dissolve,
But not in this world, for I am gone.

I'll be silent when I leave;
When I Leave I'll go out flying.

I see them move, far beneath, heading towards the back streets.
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

long long n,k,p,ar[200000],need;
vector<long long> ans[200000];
long long s;
vector<long long> v;
long long used[200000];
long long ps;

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k>>p;
for (int i=1;i<=n;i++)
{cin>>ar[i];s+=ar[i];if (ar[i]%2)v.push_back(i);}

need=k-p;
need%=2;
if (need%2!=s%2)
{
 cout<<"NO"<<endl;
 return 0;
}

if (v.size()<k-p)
{
 cout<<"NO"<<endl;
 return 0;
}

for (int i=0;i<k-p;i++)
{
 ans[i].push_back(v[i]);
 used[v[i]]=1;
}

ps=k-p;
if (ps==k)ps=0;

for (int i=k-p;i<v.size();i+=2)
{
 ans[ps].push_back(v[i]);
 used[v[i]]=1;
 ans[ps].push_back(v[i+1]);
 used[v[i+1]]=1;
 ps++;if (ps==k)ps=0;
}

ps=k-1;

for (int i=1;i<=n;i++)
 if (used[i]==0)
 {
  ans[ps].push_back(i);used[i]=1;ps--;if (ps==-1)ps=k-1;
 }

long er=0;
for (int i=0;i<k;i++)
 if (ans[i].size()==0)er=1;

if (er){cout<<"NO"<<endl; return 0;}

cout<<"YES"<<endl;
for (int i=0;i<k;i++)
{
 cout<<ans[i].size();
 for (int j=0;j<ans[i].size();j++)
 {
  cout<<" "<<ar[ans[i][j]];
 }
 cout<<endl;
}
cin.get();cin.get();
return 0;}