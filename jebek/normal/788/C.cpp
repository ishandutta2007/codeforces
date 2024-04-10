#include<bits/stdc++.h>
using namespace std;

const int inf=100000000;
int n,k,ans,dis[3000];
queue<int>Q;
bool mark[3000];
vector<int>G[3000];

void bfs(int w)
{
  memset(dis,127,sizeof dis);
  dis[w]=0;
  Q.push(w);
  while(Q.size())
    {
      int v=Q.front();
      Q.pop();
      for(int i=0;i<G[v].size();i++)
	{
	  int u=G[v][i];
	  if(u==w) ans=min(ans,dis[v]+1);
	  if(dis[v]+1<dis[u])
	    {
	      dis[u]=dis[v]+1;
	      Q.push(u);
	    }
	}
    }
}

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>k;
  for(int i=0;i<k;i++)
    {
      int tmp;
      cin>>tmp;
      if(!mark[tmp])
	{
	  mark[tmp]=true;
	  for(int j=0;j<=2000;j++)
	    if(j+tmp-n>-1 && j+tmp-n<=2000) G[j+tmp-n].push_back(j);
	}
    }
  ans=inf;
  bfs(1000);
  if(ans==inf) ans=-1;
  cout<<ans<<'\n';
}