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
//#define int ll
#define N 6000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int ffa[N],dep[N],siz[N],son[N],top1[N],dfn[N],DFN;
int low[N];
int sta[N],tp;
int U[N],V[N],inq[N];
vector<int>G[N],v[N];
int cnt;
int n,m,totscc;
int scc[N];
void ad1(int x,int y)
{
	G[x].push_back(y);
	G[y^1].push_back(x^1);
	// cout<<x<<" "<<y<<endl;
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	ffa[k]=fa;
	dep[k]=dep[fa]+1;
	siz[k]=1;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]]) son[k]=u;
	}
	// cout<<k<<","<<son[k]<<endl;
}
void dfs1(int k,int fa)
{
	top1[k]=fa;
	// cout<<k<<" "<<fa<<endl;
	dfn[k]=++DFN;
	if (!son[k]) return;
	dfs1(son[k],fa);
	for (auto u:G[k])
	{
		if (u==ffa[k]||u==son[k]) continue;
		dfs1(u,u);
	}
}
void update(int k,int l,int r,int L,int R,int z)
{
	if (L<=l&&r<=R)
	{
		v[k].push_back(z);
		return;
	}
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,R,z);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,z);
}
void work(int x,int y,int z)
{
	while (top1[x]!=top1[y])
	{
		if (dep[top1[x]]<dep[top1[y]]) swap(x,y);
		update(1,1,n,dfn[top1[x]],dfn[x],z);
		x=ffa[top1[x]];
		// cout<<x<<" "<<y<<" "<<top1[x]<<endl;
	}
	if (x==y) return;
	if (dep[x]>dep[y]) swap(x,y);
	update(1,1,n,dfn[x]+1,dfn[y],z);
}
void build(int k,int l,int r,int lst)
{
	vector<int>p(v[k].size());
	for (auto &u:p)
	{
		u=++cnt;
	}
	++cnt;
	if (v[k].size()) ad1(p.back()*2,cnt<<1);
	else if (lst) ad1(lst*2,cnt<<1);
	for (int i=0;i<v[k].size();i++)
	{
		ad1(v[k][i],p[i]<<1);
		if (i>0)
		{
			ad1(p[i-1]<<1,v[k][i]^1);
			ad1(p[i-1]<<1,p[i]<<1);
		} else
		if (lst)
		{
			ad1(lst<<1,v[k][i]^1);
			ad1(lst<<1,p[i]<<1);
		}
	}
	if (v[k].size()) lst=p.back();
	if (l==r) return;
	build(k<<1,l,l+(r-l)/2,lst);
	build(k<<1|1,l+(r-l)/2+1,r,lst);
}
void tarjan(int x)
{
	dfn[x]=++DFN;
	low[x]=dfn[x];
	sta[++tp]=x;
	inq[x]=1;
	for (auto u:G[x])
	{
		if (!dfn[u])
		{
			tarjan(u);
			low[x]=min(low[u],low[x]);
		} else
			if (inq[u]) low[x]=min(low[x],dfn[u]);
	}
	if (low[x]==dfn[x])
	{
		totscc++;
		while (sta[tp+1]!=x)
		{
			scc[sta[tp]]=totscc;
			inq[sta[tp]]=0;
			tp--;
		}
	}
}
void BellaKira()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		ad(u,v);
		ad(v,u);
	}
	dfs(1,0);
	dfs1(1,1);
	m=read();
	for (int i=1;i<=m;i++)
	{
		U[i*2]=read();
		V[i*2]=read();
		work(U[i*2],V[i*2],i*2);
		U[i*2+1]=read();
		V[i*2+1]=read();
		work(U[i*2+1],V[i*2+1],i*2+1);
	}
	// return;
	for (int i=1;i<=n;i++) G[i].clear(),dfn[i]=0;
	cnt=m;
	build(1,1,n,0);
	DFN=0;
	for (int i=2;i<=cnt*2+1;i++)
		if (!dfn[i]) tarjan(i);
	for (int i=1;i<=m;i++)
		if (scc[i*2+1]==scc[i*2]) return puts("NO"),void();
	puts("YES");
	for (int i=1;i<=m;i++)
		if (scc[i*2]<scc[i*2+1]) writeln(1);
		else writeln(2);
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/