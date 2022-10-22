//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 400005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,qq,a[N],dis[N];
map<int,int>id[N];
vector<int>G[N];
int cnt;
int inq[N];
queue<int>q;
vector<pa>g[N];
void ad(int x,int y,int w)
{
	g[x].push_back(mp(y,w));
}
void BellaKira()
{
	n=read(),m=read(),qq=read();
	for (int i=1;i<=n;i++) a[i]=read();
	G[n].push_back(m);
	id[n][m]=++cnt;
	G[1].push_back(1);
	id[1][1]=++cnt;
	for (int i=1;i<=qq;i++)
	{
		int x=read(),y=read(),c=read(),d=read(),h=read();
		if (!id[x].count(y))
		{
		G[x].push_back(y);
		id[x][y]=++cnt;
		}
		if (!id[c].count(d))
		{
		G[c].push_back(d);
		id[c][d]=++cnt;
		}
		ad(id[c][d],id[x][y],-h);
	}
	for (int i=1;i<=cnt;i++)
		dis[i]=inf,inq[i]=0;
	dis[1]=0;
	for (int i=1;i<=n;i++)
	{
		sort(G[i].begin(),G[i].end());
	}
	for (int i=n;i>=1;i--)
	{
		for (int j=0;j<G[i].size();j++)
		{
			if (j>0)
			dis[id[i][G[i][j]]]=min(dis[id[i][G[i][j]]],dis[id[i][G[i][j-1]]]+a[i]*(G[i][j]-G[i][j-1]));
		}
		for (int j=(int)G[i].size()-1;j>=0;j--)
		{
			if (j+1<G[i].size())
				dis[id[i][G[i][j]]]=min(dis[id[i][G[i][j]]],dis[id[i][G[i][j+1]]]+a[i]*(G[i][j+1]-G[i][j]));
		}
		for (int j=0;j<G[i].size();j++)
		{
			for (auto U:g[id[i][G[i][j]]])
			{
				int u=U.fi,w=U.se;
				dis[u]=min(dis[u],dis[id[i][G[i][j]]]+w);
			}
		}
	}
	if (dis[2]>=inf/10) puts("NO ESCAPE");
	else
	writeln(dis[2]);
	for (int i=1;i<=cnt;i++) g[i].clear();
	for (int i=1;i<=n;i++) G[i].clear(),id[i].clear();
	cnt=0;
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/