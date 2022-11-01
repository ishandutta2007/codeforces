#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m;
int p[200005];
int val[200005];

vector<int> g[200005];
map<int,long long> dp[200005];

long long dfs(int x,int k)
{
	if(!k) return 0;
	if(dp[x].count(k)) return dp[x][k];

	long long ans=1ll*k*val[x];

	if(g[x].size())
	{
		vector<long long> v;
		for(int u:g[x])
		{
			ans+=dfs(u,k/g[x].size());
			if(k%g[x].size()!=0) v.push_back(dfs(u,k/g[x].size()+1)-dfs(u,k/g[x].size()));
		}
		if(k%g[x].size()!=0)
		{
			sort(v.begin(),v.end());
			rep(i,k%g[x].size()) ans+=v.back(),v.pop_back();
		}
	}

	return dp[x][k]=ans;
}

void solve()
{
	scanf("%d%d",&n,&m);

	rep(i,n)
	{
		g[i].clear();
		dp[i].clear();
	}

	for(int i=2;i<=n;i++)
	{
		scanf("%d",&p[i]);
		g[p[i]].push_back(i);
	}

	rep(i,n) scanf("%d",&val[i]);
	
	printf("%lld\n",dfs(1,m));
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}