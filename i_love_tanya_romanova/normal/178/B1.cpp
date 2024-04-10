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
#include <list>
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define  INF 1000000000
#define eps 1e-10
#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 201004
//#define szz 400
//#define pb push_back
using namespace std;

long n,m,a,b,k,ans,pp,bd[3000],arp[20000];
pair <long, long> p;
vector <pair <long, long> > v[3000];
void dfs(long a)
{
     arp[a]=1;
     for (int i=0;i<v[a].size();i++)
     if (v[a][i].first!=pp&&arp[v[a][i].second]==0)
     dfs(v[a][i].second);
}
 
 bool dfs1(long a)
{
      arp[a]=1;long fl=0;
      for (int i=0;i<v[a].size();i++)
      {
          if (arp[v[a][i].second]==0)
          {if (dfs1(v[a][i].second)){fl=1;ans+=bd[v[a][i].first];}
          }
      }
      if (a==b)return true; if (fl)return true; return false;     
} 
int main(){
//freopen("input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=0;i<m;i++)
{cin>>a>>b;p=make_pair(i,b);v[a].push_back(p);p=make_pair(i,a);v[b].push_back(p);
 ;}

for (int q=0;q<m;q++)
{
    for (int j=1;j<=n;j++)arp[j]=0;
    pp=q;dfs(1);
    for (int j=1;j<=n;j++)if (arp[j]==0)
    {
        bd[q]=1;
    }
}

cin>>k;
for (int ee=0;ee<k;ee++)
{
    cin>>a>>b;ans=0;
    for (int i=1;i<=n;i++)
    arp[i]=0;
    
    a=dfs1(a);
    cout<<ans<<endl;
}

cin.get();cin.get();
return 0;}