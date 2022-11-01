#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=300000;
bool mark[MAXN],mark1[MAXN],mark2[MAXN];
int h[MAXN],par[MAXN][25],n,m,q,f[MAXN],t1[MAXN],t2[MAXN],c[MAXN],cnt;
vector<int>G[MAXN];
string ans;

int findpar(int v,int u)
{
  if(h[v]<h[u])
    swap(v,u);
  for(int i=20;i>-1;i--)
    if(h[par[v][i]]>=h[u])
      v=par[v][i];
  for(int i=20;i>-1;i--)
    if(par[v][i]!=par[u][i])
      v=par[v][i],u=par[u][i];
  if(v!=u)
    v=par[v][0];
  return v;
}

void dfs(int v)
{
  c[v]=cnt;
  f[v]=h[v];
  mark[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u])
	{
	  h[u]=h[v]+1;
	  par[u][0]=v;
	  for(int j=1;j<=20;j++)
	    par[u][j]=par[par[u][j-1]][j-1];
	  dfs(u);
	  if(f[u]>h[v])
	      mark2[u]=true;
	  f[v]=min(f[v],f[u]);
	}
      else if(h[u]<h[v])
	{
	  if(h[u]+1==h[v] && !mark1[v])
	    mark1[v]=true;
	  else
	    f[v]=min(f[v],h[u]);
	}
    }
}

void dfs1(int v)
{
  mark[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u])
	{
	  dfs1(u);
	  t1[v]+=t1[u];
	  t2[v]+=t2[u];
	}
    }
  if(mark2[v] && t1[v] && t2[v])
    ans="No";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>n>>m>>q;
  ans="Yes";
  for(int i=0;i<m;i++)
    {
      int v,u;
      cin>>v>>u;
      G[v].push_back(u);
      G[u].push_back(v);
    }
  for(int i=1;i<=n;i++)
    if(!mark[i])
      {
	cnt++;
	h[i]=1;
	dfs(i);
      }
  for(int i=0;i<q;i++)
    {
      int v,u;
      cin>>v>>u;
      if(c[v]!=c[u])
	{
	  ans="No";
	  continue;
	}
      int w=findpar(v,u);
      t1[v]++,t1[w]--;
      t2[u]++,t2[w]--;
    }
  memset(mark,false,sizeof mark);
  for(int i=1;i<=n;i++)
    if(!mark[i])
	dfs1(i);
  cout<<ans<<endl;
}