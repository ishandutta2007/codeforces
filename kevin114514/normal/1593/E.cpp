#include<bits/stdc++.h>
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
using namespace std;
vector<int> G[400004];
int deg[400004];
int dp[400004];
vector<int> ans[400004];
bool kill[400004];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			deg[i]=dp[i]=0;
			G[i].clear();
			ans[i].clear();
			ans[i].pb(1);
			kill[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].pb(v);
			G[v].pb(u);
			deg[u]++;
			deg[v]++;
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
			if(deg[i]<=1)
			{
				dp[i]=1;
				q.push(i);
				ans[i].pb(1);
			}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			rsrt(ans[x]);
			kill[x]=1;
			int dist=ans[x][0];
			for(auto v:G[x]) if(!kill[v])
			{
				deg[v]--;
				if(deg[v])
					ans[v].pb(dist+1);
				if(deg[v]==1)
					q.push(v);
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
			if(ans[i][0]>k)
				cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}