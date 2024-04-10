#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int vis[400009];
bool tw[400009];
bool inf[400009];
vector<int>ed[400009];
int go(int x)
{
    vis[x]=1;
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(vis[u]==1){inf[u]=1;continue;}
        if(vis[u]==2){tw[u]=1;continue;}
        go(u);
    }
    vis[x]=2;
}
void dfs(int x)
{
    if(tw[x])return;
    tw[x]=true;
    for(int i=0;i<ed[x].size();i++)dfs(ed[x][i]);

}
void dfss(int x)
{
    if(inf[x])return;
    inf[x]=true;
    for(int i=0;i<ed[x].size();i++)dfss(ed[x][i]);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){ed[i].clear();vis[i]=0;tw[i]=inf[i]=false;}
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        ed[x].push_back(y);
    }
   go(1);
   for(int i=1;i<=n;i++)
   {
       if(tw[i]){tw[i]=false;dfs(i);}
       if(inf[i]){inf[i]=false;dfss(i);}
   }
  for(int i=1;i<=n;i++)
  {
      if(inf[i]){cout<<-1<<" ";continue;}
      if(tw[i]){cout<<2<<" ";continue;}
      if(vis[i]){cout<<1<<" ";continue;}
      cout<<0<<" ";
  }
  cout<<endl;
}
    return 0;
}