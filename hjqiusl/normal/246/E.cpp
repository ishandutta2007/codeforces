//~~
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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int son[N],siz[N],dep[N],ans[N];
set<int>P[N];
int val[N];
int n,q;
int fa[N];
int cnt;
vector<pa>E[N];
vector<int>G[N];
map<string,int>Mp;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	siz[k]=1;
	for (auto u:G[k])
	{
		dfs(u,k);
		siz[k]+=siz[u];
		if (siz[u]>siz[son[k]])
			son[k]=u;
	}
}
void clr(int k,int fa)
{
	P[dep[k]].clear();
	for (auto u:G[k]) clr(u,k);
}
void ins(int k,int fa)
{
	P[dep[k]].insert(val[k]);
	for (auto u:G[k]) ins(u,k);
}
void dfs1(int k,int fa)
{
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		dfs1(u,k);
		clr(u,k);
	}
	if (son[k]) dfs1(son[k],k);
	P[dep[k]].insert(val[k]);
	for (auto u:G[k])
	{
		if (u==fa||u==son[k]) continue;
		ins(u,k);
	}
	for (auto u:E[k])
	{
		ans[u.se]=P[dep[k]+u.fi].size();
	}
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string st;
		int k;
		cin>>st>>k;
		if (!Mp[st]) Mp[st]=++cnt;
		val[i]=Mp[st];
		if (k) ad(k,i),fa[i]=k;
	}
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		E[x].push_back(mp(y,i));
	}
	for (int i=1;i<=n;i++)
		if (!fa[i])
		{
			dfs(i,0);
			dfs1(i,0);
			clr(i,0);
		}
	for (int i=1;i<=q;i++) cout<<ans[i]<<endl;
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/