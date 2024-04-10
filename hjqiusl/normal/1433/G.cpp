//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,q,dis[N][N];
vector<pa>G[N];
pa E[N];
int a[N],b[N];
int ans;
void LYC_music()
{
	n=read();m=read(),q=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		E[i]={u,v};
	}
	for (int i=1;i<=q;i++)
	{
		a[i]=read(),b[i]=read();
	}
	for (int i=1;i<=n;i++)
	{
		priority_queue<pa>q;
		for (int j=1;j<=n;j++) dis[i][j]=inf;
		dis[i][i]=0;
		q.push({0,i});
		while (!q.empty())
		{
			int u=q.top().se,ds=q.top().fi;
			q.pop();
			if (-ds!=dis[i][u]) continue;
//			cout<<"?"<<u<<endl;
			for (auto U:G[u])
			{
				int v=U.fi,w=U.se;
				if (dis[i][v]>dis[i][u]+w)
				{
					dis[i][v]=dis[i][u]+w;
					q.push({-dis[i][v],v});
				}
			}
		}
//		for (int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
	}
	ans=inf;
	for (int i=1;i<=m;i++)
	{
		int now=0;
		for (int j=1;j<=q;j++)
			now+=min(dis[a[j]][b[j]],min(dis[a[j]][E[i].fi]+dis[b[j]][E[i].se],dis[a[j]][E[i].se]+dis[b[j]][E[i].fi]));
		ans=min(ans,now);
	}
	writeln(ans);
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/