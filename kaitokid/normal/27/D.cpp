#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=400+5;
int dfsnum[N],dfslow[N],com[N],id,cm;
bool vis[N];
vector<int>ed[N];
stack <int>s;
int res[N];
void dfs(int x)
{
    dfsnum[x]=dfslow[x]=++id;
    vis[x]=true;
    s.push(x);
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(!dfsnum[u])dfs(u);
        if(vis[u])dfslow[x]=min(dfslow[x],dfslow[u]);
    }
    if(dfslow[x]==dfsnum[x])
    {
        com[x]=cm;
        res[cm]=-1;
        vis[x]=0;
        while(s.top()!=x){com[s.top()]=cm;vis[s.top()]=0;s.pop();}
        s.pop();
        cm++;
    }

}
int val(int x)
{
    return 2*x;
}
int nt(int x )
{
    return x^1;
}
void ador(int x,int y)
{
    ed[nt(x)].push_back(y);
    ed[nt(y)].push_back(x);
}
void go(int x)
{
    vis[x]=true;
    for(int i=0;i<ed[x].size();i++)
        if(!vis[ed[x][i]])go(ed[x][i]);
if(res[com[x]]!=-1)return;
res[com[x]]=1;
res[com[nt(x)]]=0;
}
int x[N],y[N];
int main()
{

//freopen("r.txt","w",stdout);
//    ios::sync_with_stdio(0);
 int n,m;
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
      cin>>x[i]>>y[i];
      if(x[i]>y[i])swap(x[i],y[i]);
  }
  for(int i=0;i<m;i++)
    for(int j=i+1;j<m;j++)
  {

    if(x[i]>x[j]&&x[i]<y[j])
    {
        if(y[i]>y[j]||y[i]<x[j]){ador(val(i),val(j));ador(nt(val(i)),nt(val(j)));}
    }

    if(x[i]<x[j]||x[i]>y[j])
    {
        if(y[i]>x[j]&&y[i]<y[j]){ador(val(i),val(j));ador(nt(val(i)),nt(val(j)));}
    }

  }
  for(int i=0;i<2*m;i++)
    if(!dfsnum[i])dfs(i);
  for(int i=0;i<2*m;i+=2)
  if(com[i]==com[i^1]){cout<<"Impossible";return 0;}
  for(int i=0;i<2*m;i++)
    if(!vis[i])go(i);
  for(int i=0;i<m;i++)
    if(res[com[val(i)]])cout<<"i";
    else cout<<"o";
    return 0;
}