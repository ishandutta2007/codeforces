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
#define eps 1e-11
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define free asdfasdfsdadsg
//#define szz 400
//#define pb push_back
#define MAXN 100000
#define free afdshjioey
//#define SIZE 60
using namespace std;  

long n,m,k,t,kn[200][200];
vector<long> g[1000];
long arp[1000];
long usd[1000];
long fll,ans;

void dfs(long v)
{
     arp[v]=1;
     for (int q=0;q<g[v].size();q++)
     {
         long tt=g[v][q];
         if (arp[tt]==0)
         dfs(tt);
     }
}

int main(){
//freopen("length.in","r",stdin);
//freopen("length.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;

for (int i=1;i<=n;i++)
{
 cin>>k;
 for (int j=1;j<=k;j++)
 {
     cin>>t;fll=1;
     kn[i][t]=1;
 }   
}

for (int i=1;i<=n;i++)
for (int j=1;j<=n;j++)
for (int p=1;p<=m;p++)
if (kn[i][p]*kn[j][p])
{
                      g[i].push_back(j);
                      g[j].push_back(i);
}

for(int i=1;i<=n;i++)
if (arp[i]==0)
{
              dfs(i);++ans;
              }

if (fll==0)
++ans;

cout<<ans-1<<endl;
              
cin.get();cin.get();
return 0;}