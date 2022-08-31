//#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-8
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
//#define szz 400
//#define pb push_back
using namespace std;
long arp[200000],arp1[200000],c[200000];
vector <long> v1[120000],v[120000];
long n,m,a,b;
void dfs(long a)
{
     arp[a]=1;
//     if (c[a]==2)return;
     long q;
     for (int i=0;i<v[a].size();i++)
     {
      q=v[a][i];
      if (arp[q]==0)dfs(q);
     }
}

void dfs1(long a)
{
     arp1[a]=1;
     if (c[a]==1)return;
     long q;
     for (int i=0;i<v1[a].size();i++)
     {
         q=v1[a][i];
         if (arp1[q]==0)dfs1(q);
     }
}

int main(){
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{
    cin>>c[i];
}


for (int i=1;i<=m;i++)
{
cin>>a>>b;v[a].push_back(b);
v1[b].push_back(a);
}

for (int i=1;i<=n;i++)
if (c[i]==1)
{dfs(i);
}
for (int i=1;i<=n;i++)
if (c[i]==2)
dfs1(i);

for (int i=1;i<=n;i++)
{
    if (arp[i]&&arp1[i])cout<<1<<endl;
    else cout<<0<<endl;
}

cin.get();cin.get();
return 0;}