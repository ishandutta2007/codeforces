#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

const int mod=998244353;
int inv(int x)
{
	int z=1,y=mod-2;
	while(y){if(y&1)z=1ll*z*x%mod;x=1ll*x*x%mod;y/=2;}
	return z;
}

int n,m;
int p,q;

char mp[300005];

int id(int x,int y){return x*m-m+y;}

long long ans=0x3fffffffffffffffll;

long long dis[300005];
int vis[300005];
vector<pair<int,int>> g[300005];

void link(int x,int y,int z)
{
//	cerr<<x<<' '<<y<<' '<<z<<endl;
	g[x].push_back(make_pair(y,z));
}

void dijkstra()
{
	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
	rep(i,n*m)
	{
		dis[i]=0x3fffffffffffffffll;
		if(mp[i]=='.') dis[i]=0,pq.push(make_pair(0,i));
	}

	while(!pq.empty())
	{
		int x=pq.top().second;pq.pop();if(vis[x])continue;vis[x]=1;
		for(auto u:g[x])
		{
			if(dis[u.first]>dis[x]+u.second) dis[u.first]=dis[x]+u.second,pq.push(make_pair(dis[u.first],u.first));
		}
	}
}

void solve()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d",&p,&q);

	rep(i,n)
	{
		rep(j,m)
		{
			scanf(" %c",&mp[id(i,j)]);
		}
	}

	rep(i,n)
	{
		rep(j,m)
		{
			int x=id(i,j),y=0,z,d;
			if(mp[x]=='L') y=id(i,j+1),d=1;
			if(mp[x]=='R') y=id(i,j-1),d=1;
			if(mp[x]=='U') y=id(i+1,j),d=2;
			if(mp[x]=='D') y=id(i-1,j),d=2;
			if(y)
			{
				if(i!=1)
				{
					z=id(i-1,j);if(mp[z]!='#'&&z!=y) link(z,y,d==1?p:q);
				}
				if(i!=n)
				{
					z=id(i+1,j);if(mp[z]!='#'&&z!=y) link(z,y,d==1?p:q);
				}
				if(j!=1)
				{
					z=id(i,j-1);if(mp[z]!='#'&&z!=y) link(z,y,d==2?p:q);
				}
				if(j!=m)
				{
					z=id(i,j+1);if(mp[z]!='#'&&z!=y) link(z,y,d==2?p:q);
				}
			}
		}
	}

	dijkstra();

	rep(i,n)rep(j,m)
	{
		if(j<m&&mp[id(i,j)]!='#'&&mp[id(i,j+1)]!='#') ans=min(ans,dis[id(i,j)]+dis[id(i,j+1)]);
		if(i<n&&mp[id(i,j)]!='#'&&mp[id(i+1,j)]!='#') ans=min(ans,dis[id(i,j)]+dis[id(i+1,j)]);
	}

	if(ans>=0x3fffffffffffffffll) puts("-1"); else printf("%lld\n",ans);
}



int main()
{
	int t=1;
//	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}