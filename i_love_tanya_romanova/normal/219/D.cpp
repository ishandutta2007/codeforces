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

long ans[300000],arp[300000],d[300000],inv[300000];
vector<long> g[300000];
long n,tinv,a,b;
pair<long, long> p;
map<pair<long, long> , long> mp;
void dfs(long v)
{
     arp[v]=1;
     for (int i=0;i<g[v].size();i++)
     {long q;
         q=g[v][i];
         if(arp[q])continue;
         
         pair<long, long> p=make_pair(v,q);
         if (mp[p]==-1)inv[q]=inv[v]+1; else inv[q]=inv[v];
         d[q]=d[v]+1;
         if (mp[p]==-1)tinv++;
         
         dfs(q);
     }
}

int main(){
//freopen("peacefulsets.in","r",stdin);
//freopen("peacefulsets.out","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n;
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    p=make_pair(a,b);
    mp[p]=1;
    p=make_pair(b,a);
    mp[p]=-1;
    g[a].push_back(b);
    g[b].push_back(a);
}

dfs(1);


for(int i=1;i<=n;i++)
{//cout<<d[i]<<" "<<inv[i]<<endl;
ans[i]=tinv-inv[i]+d[i]-inv[i];
}
long tans=1000000;
for (int i=1;i<=n;i++)
if (ans[i]<tans)tans=ans[i];

cout<<tans<<endl;
long fl=0;

for (int i=1;i<=n;i++)
{
 if (ans[i]==tans)
 {
                  if (fl)cout<<" ";
                  cout<<i;fl=1;
                  }   
}
cout<<endl;

cin.get();cin.get();
return 0;}