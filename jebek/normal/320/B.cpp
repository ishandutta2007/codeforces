#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

bool vis[200];
int t[200],x[200],y[200],n,f[200],p;
vector<int>G[200];

void check(int i,int j)
{
  if(t[j]==2)
    return;
  if((x[j]<x[i] && x[i]<y[j]) || (x[j]<y[i] && y[i]<y[j])){
      G[i].push_back(j);
      // cout<<i<<" "<<j<<endl;
}
  if((x[i]<x[j] && x[j]<y[i]) || (x[i]<y[j] && y[j]<y[i])){
    G[j].push_back(i);
    //  cout<<j<<" "<<i<<endl;
  }
}

void dfs(int v)
{
  vis[v]=true;
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(!vis[u])
	dfs(u);
    }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
    {
      cin>>t[i]>>x[i]>>y[i];
      if(t[i]==1)
	{
	  p++;
	  f[p]=i;
	}
      if(t[i]==1)
	for(int j=1;j<i;j++)
	  check(i,j);
      else
	{
	  memset(vis,false,sizeof vis);
	  dfs(f[x[i]]);
	  if(vis[f[y[i]]])
	    cout<<"YES"<<endl;
	  else
	    cout<<"NO"<<endl;
	}
    }
}