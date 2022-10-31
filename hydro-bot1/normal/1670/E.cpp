#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T,n,p;
	cin>>T;
	while(T--)
	{
		cin>>p;
		n=1<<p;
		vector<vector<pair<int,int>>> G(n+1);
		vector<int> ansv(n+1),anse(n+1),rec(n+1);
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].emplace_back(v,i);
			G[v].emplace_back(u,i);
		}
		ansv[1]=n;
		rec[1]=n;
		int cur=1;
		function<void(int,int)> dfs=[&](int u,int pa)
		{
			for(auto [v,id]:G[u])
			{
				if(v==pa)continue;
				if(rec[u]==0)
				{
					anse[id]=cur;
					ansv[v]=cur^n;
					cur++;
					rec[v]=rec[u]^n;
				}
				else
				{
					anse[id]=cur^n;
					ansv[v]=cur;
					cur++;
					rec[v]=rec[u]^n;
				}
				dfs(v,u);
			}
		};
		dfs(1,0);
		cout<<1<<"\n";
		for(int i=1;i<=n;i++)cout<<ansv[i]<<" \n"[i==n];
		for(int i=1;i<n;i++)cout<<anse[i]<<" \n"[i==n-1];
	}
	
	return 0;
}