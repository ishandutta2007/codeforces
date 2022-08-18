//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
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

#define  INF 100000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
using namespace std;

long n,m,k,ans,sz[200000],arp[200000],calc,bd[200000];
long q,a,b;
vector<long> g[200000];

void dfs(long v)
{
     arp[v]=calc;
     sz[calc]++;
     for (int i=1;i<=g[v].size();i++)
     {
         long q=g[v][i-1];
         if (arp[q]==0)dfs(q);
     }
}

int main(){
//freopen("max.in","r",stdin);
//freopen("max.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);   
}

for (int i=1;i<=n;i++)
{
 if (arp[i]==0)
 {
               ++calc;
               dfs(i);
 }   
}

cin>>k;
for (int i=1;i<=k;i++)
{
    cin>>a>>b;
    if (arp[a]==arp[b])
    bd[arp[a]]=1;
}

for (int i=1;i<=calc;i++)
if (sz[i]>ans&&bd[i]==0)
ans=sz[i];

cout<<ans<<endl;

cin.get();cin.get();
return 0;}