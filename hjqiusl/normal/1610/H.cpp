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
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int c[N],st[N][25],dep[N];
int a[N],b[N];
int tr[N];
int dfn[N],rdfn[N];
int DFN;
int ans;
int n;
int m;
vector<int>G[N],g;
bool cmp(int x,int y)
{
	return dep[c[x]]>dep[c[y]];
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=(x&-x);
	}
	return res;
}
void update(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=(x&-x);
	}
}
int query(int l,int r)
{
	return query(r)-query(l-1);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	dfn[k]=++DFN;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
	{
		st[k][i]=st[st[k][i-1]][i-1];
	}
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
	rdfn[k]=DFN;
}
int gt(int x,int y)
{
	for (int i=20;i>=0;i--)
	{
		if (dep[st[x][i]]>dep[y])
		{
			x=st[x][i];
		}
	}
	return x;
}
void LYC_music()
{
	n=read();m=read();
	for (int i=2;i<=n;i++) 
		ad(read(),i);
	dfs(1,0);
	for (int i=1;i<=m;i++)
	{
		a[i]=read(),b[i]=read();
		if (dep[a[i]]>dep[b[i]]) swap(a[i],b[i]);
		if (dfn[a[i]]<=dfn[b[i]]&&rdfn[a[i]]>=dfn[b[i]])
		{
			if (dep[b[i]]-dep[a[i]]==1)
			{
				puts("-1");
				return;
			}
			c[i]=gt(b[i],a[i]);
			g.push_back(i);
		}
	}
	sort(g.begin(),g.end(),cmp);
	for (auto i:g)
	{
		if (query(dfn[c[i]],dfn[b[i]]-1)+query(rdfn[b[i]]+1,rdfn[c[i]]))
		{
			continue;
		}
		ans++;
		update(dfn[c[i]],1);
	}
	for (int i=1;i<=m;i++)
	{
		if (!c[i])
		{
			if (!(ans-query(dfn[a[i]],rdfn[a[i]])-query(dfn[b[i]],rdfn[b[i]])))
			{
				ans++;
				break;
			}
		}
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