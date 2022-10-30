#include<bits/stdc++.h>
using namespace std;
int c[333333],ok[333333],ccnt[333333];
vector<int> G[333333];
int n,tot;
void dfs1(int u,int p)
{
	ccnt[u]=c[u];
	for(auto v:G[u])
	{
		if(v==p)continue;
		dfs1(v,u);
		ccnt[u]+=ccnt[v];
		if(ok[v] and ccnt[v]>=2)ok[u]=1;
	}
}
void dfs2(int u,int p)
{
	for(auto v:G[u])
	{
		if(v==p)continue;
		if(ok[u] and tot-ccnt[v]>=2)ok[v]=1;
		dfs2(v,u);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i],tot+=c[i];
	int u,v;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i])
		{
			ok[i]=1;
			for(auto v:G[i])
				ok[v]=1;
		}
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
	{
		cout<<ok[i]<<' ';
	}
	cout<<endl;
	return 0;
}