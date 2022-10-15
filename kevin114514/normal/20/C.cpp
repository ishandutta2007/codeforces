#include<bits/stdc++.h>
using namespace std;
long long dist[100100];
int pre[100100];
vector<pair<int,int> > G[100100];
int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--;
		v--;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1;i<n;i++)
	{
		pre[i]=-1;
		dist[i]=1e15;
	}
	pre[0]=-2;
	set<pair<int,int> > S;
	S.insert(make_pair(0,0));
	while(!S.empty())
	{
		pair<int,int> vert=*S.begin();
		S.erase(S.begin());
		int u=vert.second;
		int now=vert.first;
		if(now>dist[u])
			continue;
		for(int i=0;i<(int)(G[u].size());i++)
		{
			int v=G[u][i].first;
			int len=G[u][i].second;
			if(dist[v]>dist[u]+len)
			{
				dist[v]=dist[u]+len;
				pre[v]=u;
				S.insert(make_pair(dist[v],v));
			}
		}
	}
	vector<int> route;
	int u=n-1;
	if(pre[u]==-1)
		puts("-1");
	else
	{
		while(u!=-2)
		{
			route.push_back(u);
			u=pre[u];
		}
		reverse(route.begin(),route.end());
		for(int i=0;i<(int)(route.size());i++)
			cout<<route[i]+1<<" ";
		puts("");
	}
	return 0;
}