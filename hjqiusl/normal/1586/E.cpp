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
#define N 600005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int dep[N],st[N][2];
int dis[N];
int ans;
int fa[N];
int q;
int n,m;
vector<int>G[N],E1[N];
int cnt;
pa E[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void work(int x,int y)
{
	vector<int>g,g1;
	while (dep[x]!=dep[y]) 
	{
		if (dep[x]>dep[y]) g.push_back(x),x=st[x][0];
		else g1.push_back(y),y=st[y][0];
	}
	while (x!=y)
	{
		g1.push_back(y);
		g.push_back(x);
		x=st[x][0],y=st[y][0];
	}
	g.push_back(x);
	reverse(g1.begin(),g1.end());
	writeln(g.size()+g1.size());
	for (auto u:g) writesp(u);
	for (auto u:g1) writesp(u);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	st[k][0]=fa;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		if (dep[u]) continue;
		dfs(u,k);
		E1[k].push_back(u);
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if (gf(x)!=gf(y))
		{
			ad(x,y);
			ad(y,x);
			fa[gf(x)]=gf(y);
		}
	}
	dfs(1,0);
	q=read();
	while (q--)
	{
		int x=read(),y=read();
		dis[x]^=1,dis[y]^=1;
		E[++cnt]={x,y};
	}
	for (int i=1;i<=n;i++) ans+=dis[i];
	if (!ans)
	{
		puts("YES");
		for (int i=1;i<=cnt;i++) work(E[i].fi,E[i].se),puts("");
	} else 
	{
		puts("NO");
		writeln(ans/2);
	}
			
}
/*

*/