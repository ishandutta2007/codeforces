/*  
Fire
Alight the new beginning
Desire
Make this life worth living
Hands are shaking
Heart is breaking
It's for the taking
Every single thing
Don't lose focus
Because we are halfway there
Inception of the end
Sacrifice all your fear
Fire
Cleanse the world that would hold me back
Desire
By throat I release you
Goodbye
Hands are shaking
Heart is breaking
It's for the taking
Every single thing
Don't lose focus
Because we are halfway there
Inception of the end
Sacrifice all your fear
Don't lose focus
Because we are halfway there
Inception of the end
Sacrifice all your fear
Sacrifice all your fear
Sacrifice all your fear
Sacrifice all your fear
We start this fire
We start this fire
The way we always do
We start this fire
The way we always do
Let the flames consume
The way we always do
Let the flames consume
Don't lose focus
Because we are halfway there
Inception of the end
Sacrifice all your fear
Don't lose focus
Because we are halfway there
Inception of the end
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
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-9
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 3
#define clone agsdahfaassdg
using namespace std;

long n,m,arp[200000],a,b;
vector<long> g[200000],gr[200000],
og[200000];
set<pair<long, long> > usd;
long q,fl;
void dfs(long v,long par)
{
     if (arp[v])return;
     arp[v]=1;
     for(int i=0;i<og[v].size();i++)
     {
      long q=og[v][i];
      if (q==par)continue;
      pair<long, long> temp=make_pair(min(v,q),max(v,q));
      if (usd.find(temp)==usd.end())
      {
       usd.insert(temp);
      g[v].push_back(q);
      dfs(q,v);}
     }
}

int main(){
//freopen("palindrome.in","r",stdin);
//freopen("palindrome.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    og[a].push_back(b);
    og[b].push_back(a);
}
usd.clear();
dfs(1,-1);
usd.clear();
for (int i=1;i<=n;i++)
for (int j=0;j<g[i].size();j++)
{
    q=g[i][j];
    gr[q].push_back(i);
}
for (int i=1;i<=n;i++)
arp[i]=0;
for (int i=1;i<=n;i++)
og[i]=gr[i];
dfs(1,-1);
for (int i=1;i<=n;i++)
if (arp[i]==0)
fl=1;
if (fl)cout<<0<<endl;
else
{
 for (int i=1;i<=n;i++)
 for (int j=0;j<og[i].size();j++)
 cout<<og[i][j]<<" "<<i<<endl;   
}

cin.get();cin.get();
return 0;}