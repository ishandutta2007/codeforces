#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> G(n+5);
	vector<int> deg(n+5);
//	map<pair<int,int>,int> cnt;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
//		cnt[make_pair(u,v)]++;
		deg[u]++;
		G[v].push_back(u);
	}
	/*
	for(const auto &[pr,w]:cnt)
	{
		auto [u,v]=pr;
		G[v].emplace_back(u,w);
	}
	*/
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> dis(n+5,0x3f3f3f3f),used(n+5);
	dis[n]=0;
	pq.emplace(0,n);
	while(not pq.empty())
	{
		auto [d,u]=pq.top();pq.pop();
		used[u]=1;
		if(dis[u]!=d)continue;
		for(auto v:G[u])
		{
			deg[v]--;
			if(not used[v] and dis[u]+deg[v]+1<dis[v])
			{
				dis[v]=dis[u]+deg[v]+1;
				pq.emplace(dis[v],v);
			}
		}
	}
	cout<<dis[1]<<endl;
	return 0;
}