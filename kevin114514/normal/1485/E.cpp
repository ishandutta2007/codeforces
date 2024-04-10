#include<bits/stdc++.h>
#define int long long
using namespace std;
int depth[200200];
int father[200200];
int num[200200];
vector<int> basket[200200];
int mx[200200],mn[200200];
int dp[200200];
int dpmx1[200200],dpmx2[200200];
vector<int> G[200200];
void dfs(int x,int fa,int dep)
{
	father[x]=fa;
	depth[x]=dep;
	basket[dep].push_back(x);
	mx[dep]=max(mx[dep],num[x]);
	mn[dep]=min(mn[dep],num[x]);
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa)
			dfs(G[x][i],x,dep+1);
}
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n+20;i++)
		{
			mx[i]=-1e9;
			mn[i]=1e9;
			dp[i]=0;
			basket[i].clear();
			G[i].clear();
			dpmx1[i]=-1e9;
			dpmx2[i]=-1e9;
		}
		for(int i=1;i<n;i++)
		{
			int x;
			cin>>x;
			x--;
			G[i].push_back(x);
			G[x].push_back(i);
		}
		for(int i=1;i<n;i++)
			cin>>num[i];
		dfs(0,-1,0);
		int d=*max_element(depth,depth+n);
		dp[0]=0;
//		dpmx[0]=0;
		for(int i=1;i<=d;i++)
		{
			for(int j=0;j<(int)(basket[i].size());j++)
			{
				int v=basket[i][j];
				int u=father[v];
				dpmx1[i]=max(dpmx1[i],dp[u]+num[v]);
				dpmx2[i]=max(dpmx2[i],dp[u]-num[v]);
			}
//			cout<<dpmx1[i]<<" "<<dpmx2[i]<<endl;
			for(int j=0;j<(int)(basket[i].size());j++)
			{
				//u,x=>v,y
				int v=basket[i][j];
				int u=father[v];
				dp[v]=max(dp[v],dp[u]+max(abs(num[v]-mn[i]),abs(num[v]-mx[i])));
//				dpmx[i]=max(dpmx[i],dp[v]);
				//x,u=>v,y
				dp[v]=max(dp[v],dpmx1[i]-num[v]);
				dp[v]=max(dp[v],dpmx2[i]+num[v]);
//				cout<<i<<" "<<v<<" "<<dp[v]<<endl;
			}
		}
		int ret=0;
		for(int i=0;i<(int)(basket[d].size());i++)
		{
			int u=basket[d][i];
			ret=max(ret,dp[u]);
		}
		cout<<ret<<endl;
	}
	return 0;
}