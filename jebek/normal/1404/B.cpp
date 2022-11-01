#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
typedef long long ll;

const int maxn=2e5+100;
int n,a,b,da,db,dis[maxn];
vector<int>G[maxn];

void dfs(int v)
{
  for(int i=0;i<G[v].size();i++)
    {
      int u=G[v][i];
      if(dis[u]==-1)
	{
	  dis[u]=dis[v]+1;
	  dfs(u);
	}
    }
}

int find_distance()
{
  for(int i=1;i<=n;i++)
    dis[i]=-1;
  dis[a]=0;
  dfs(a);
  return dis[b];
}

int find_diameter()
{
  for(int i=1;i<=n;i++)
    dis[i]=-1;
  dis[1]=0;
  dfs(1);
  int MAX=0,ind=1;
  for(int i=1;i<=n;i++)
    {
      if(dis[i]>MAX)
	{
	  MAX=dis[i];
	  ind=i;
	}
      dis[i]=-1;
    }
  dis[ind]=0;
  dfs(ind);
  for(int i=1;i<=n;i++)
    MAX=max(MAX,dis[i]);
  return MAX;
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n>>a>>b>>da>>db;
      for(int i=1;i<=n;i++)
	G[i].clear();
      for(int i=1;i<n;i++)
	{
	  int v,u;
	  cin>>v>>u;
	  G[v].push_back(u);
	  G[u].push_back(v);
	}
      int dim = find_diameter();
      int DIS = find_distance();
      if(DIS <= da || db <= da*2 || dim <= da*2)
	cout<<"Alice\n";
      else
	cout<<"Bob\n";
    }
}