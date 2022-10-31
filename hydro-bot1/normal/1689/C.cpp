#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<vector<int>> G(n+5);
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> dp(n+5),sz(n+5);
		function<void(int,int)> dfs=[&](int u,int p)
		{
			sz[u]=1;
			int cnt=0;
			vector<int> g;
			for(auto v:G[u])
			{
				if(v==p)continue;
				dfs(v,u);
				g.push_back(v);
				sz[u]+=sz[v];
				cnt++;
			}
			if(cnt==0)
			{
				dp[u]=0;
			}
			else if(cnt==1)
			{
				dp[u]=sz[g[0]]-1;
			}
			else
			{
				dp[u]=max(dp[g[0]]+sz[g[1]],dp[g[1]]+sz[g[0]])-1;
			}
//			cerr<<u<<' '<<dp[u]<<' '<<sz[u]<<endl;
		};
		dfs(1,0);
		cout<<dp[1]<<endl;
	}
	
	return 0;
}