#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

queue<int>q;
int dis[3100][3100],ans,a,b,c,x,y,z,n,m;
vector<int>G[3100];

void BFS(int v1)
{
  dis[v1][v1]=0;
  q.push(v1);
  while(q.size())
    {
      int v=q.front();
      q.pop();
      for(int i=0;i<G[v].size();i++)
	{
	  int u=G[v][i];
	  if(dis[v1][v]+1<dis[v1][u])
	    {
	      dis[v1][u]=dis[v1][v]+1;
	      q.push(u);
	    }
	}
    }
}

int main()
{
  cin>>n>>m;
  memset(dis,63,sizeof dis);
  for(int i=0;i<m;i++)
    {
      int v,u;
      cin>>v>>u;
      G[v].push_back(u);
      G[u].push_back(v);
    }
  for(int i=1;i<=n;i++)
    BFS(i);
  cin>>a>>b>>c>>x>>y>>z;
  if(dis[a][b]>c || dis[x][y]>z)
    {
      cout<<-1<<endl;
      return 0;
    }
  ans=dis[a][b]+dis[x][y];
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(dis[a][i]+dis[i][j]+dis[j][b]<=c && dis[x][i]+dis[i][j]+dis[j][y]<=z)
	ans=min(ans,dis[a][i]+dis[x][i]+dis[i][j]+dis[j][b]+dis[j][y]);
  swap(a,b);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if(dis[a][i]+dis[i][j]+dis[j][b]<=c && dis[x][i]+dis[i][j]+dis[j][y]<=z)
	ans=min(ans,dis[a][i]+dis[x][i]+dis[i][j]+dis[j][b]+dis[j][y]);
  cout<<m-ans<<endl;
}