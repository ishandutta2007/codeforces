#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m,f[3][505];
vector<int> g[505];
int X[250005],Y[250005],Z[250005];
long long ans;

void solve()
{
	scanf("%d%d",&n,&m);
	rep(i,n) g[i].clear(),f[0][i]=f[1][i]=f[2][i]=1e9;
	rep(i,m)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		g[X[i]].push_back(Y[i]);
		g[Y[i]].push_back(X[i]);
	}

	queue<int> q;
	f[0][1]=0;q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int u:g[x]) if(f[0][u]>f[0][x]+1)
		{
			f[0][u]=f[0][x]+1;
			q.push(u);
		}
	}
	f[1][n]=0;q.push(n);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int u:g[x]) if(f[1][u]>f[1][x]+1)
		{
			f[1][u]=f[1][x]+1;
			q.push(u);
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	rep(i,n)
	{
		f[2][i]=f[0][i]+f[1][i]+1;
		pq.push(make_pair(f[2][i],i));
	}
	while(!pq.empty())
	{
		int x=pq.top().second,d=pq.top().first;pq.pop();
		if(f[2][x]!=d) continue;
		for(int u:g[x]) if(f[2][u]>f[2][x]+1)
		{
			f[2][u]=f[2][x]+1;
			pq.push(make_pair(f[2][u],u));
		}
	}

	ans=1e18;
	rep(i,m)
	{
		int coef=min(f[0][X[i]]+f[1][Y[i]],f[0][Y[i]]+f[1][X[i]]);
		coef=min(coef,f[2][X[i]]);
		coef=min(coef,f[2][Y[i]]);
		ans=min(ans,1ll*(1+coef)*Z[i]);
	}
	printf("%lld\n",ans);
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