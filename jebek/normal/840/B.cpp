#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e5;
bool mark[maxn];
int n,m,d[maxn];
vector<int>ans,G[maxn],ind[maxn];

void dfs(int v)
{
  mark[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!mark[u])
	{
	  dfs(u);
	  if(d[u]==1)
	    {
	      ans.push_back(ind[v][i]);
	      if(d[v]!=-1)
		d[v]=1-d[v];
	    }
	}
    }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m;
  int root = 1;
  for(int i=1;i<=n;i++)
    {
      cin>>d[i];
      if(d[i]==-1)
	root=i;
    }
  for(int i=0;i<m;i++)
    {
      int v,u;
      cin>>v>>u;
      G[v].push_back(u);
      G[u].push_back(v);
      ind[v].push_back(i+1);
      ind[u].push_back(i+1);
    }
  dfs(root);
  if(d[root]==1) cout<<-1<<endl;
  else{
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<endl;
  }
}