#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5;
int n,m,a[maxn],col[maxn],cnt;
bool mark[maxn];
vector<int>topo,vec[maxn],G[maxn],G1[maxn];

int f(int tmp)
{
  return 2*m+1-tmp;
}

void addedge(int v,int u)
{
  G[v].push_back(u);
  G1[u].push_back(v);
}

void add(int v,int u)
{
  addedge(f(v),u);
  addedge(f(u),v);
}

void dfs1(int v)
{
  mark[v]=true;
  col[v]=cnt;
  for(int i=0;i<G1[v].size();i++)
    {
      int u=G1[v][i];
      if(!mark[u])
	dfs1(u);
    }
}

void dfs(int v)
{
  mark[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u])
	dfs(u);
    }
  topo.push_back(v);
}

int main()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  for(int i=1;i<=m;i++)
    {
      int tmp;
      cin>>tmp;
      for(int j=0;j<tmp;j++)
	{
	  int tmp1;
	  cin>>tmp1;
	  vec[tmp1].push_back(i);
	}
    }
  for(int i=1;i<=n;i++)
    {
      if(a[i]==0)
	{
	  add(vec[i][0],vec[i][1]);
	  add(f(vec[i][0]),f(vec[i][1]));
	}
      else
	{
	  add(vec[i][0],f(vec[i][1]));
	  add(f(vec[i][0]),vec[i][1]);
	}
    }
  for(int i=1;i<=2*m;i++)
    if(!mark[i]) dfs(i);
  memset(mark,false,sizeof mark);
  for(int i=topo.size()-1;i>-1;i--)
    if(!mark[topo[i]])
      {
	cnt++;
	dfs1(topo[i]);
      }
  for(int i=1;i<=m;i++)
    if(col[i]==col[f(i)])
      {
	cout<<"NO\n";
	return 0;
      }
  cout<<"YES\n";
}