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
#define N 600005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
set<pa>S[N][3];
int Ers[N];
int lson[N],rson[N],E[N],E1[N],ans[N],c[N];
int Fa[N];
int vis[N];
int V[N];
int cnt;
int n,m;
bool cmp(int x,int y)
{
	return (S[x][1].size()+S[x][2].size())<(S[y][1].size()+S[y][2].size());
}
void solve(int u)
{
	for (int w=1;w<=2;w++)
	{
		set<pa>nows;
		nows.swap(S[u][w]);
		for (auto v:nows)
		{
			if (!Ers[v.fi]) S[u][w].insert(v);
		}
		while (S[u][w].size()>=2)
		{
			int x=(*S[u][w].begin()).se,id=(*S[u][w].begin()).fi;
			S[u][w].erase(S[u][w].begin());
			int y=(*S[u][w].begin()).se,id1=(*S[u][w].begin()).fi;
			S[u][w].erase(S[u][w].begin());
			Ers[id]=Ers[id1]=1;
			if (x==y)
			{
				ans[id]=x;
				ans[id1]=u;
				continue;
			}
			++cnt;
			Fa[id]=Fa[id1]=cnt;
			S[x][w].insert({cnt,y});
			S[y][w].insert({cnt,x});
			E[cnt]=x;
			E1[cnt]=y;
			lson[cnt]=id;
			rson[cnt]=id1;
		}
	}
}
void dfs(int k)
{
	for (auto U:S[k][2])
	{
		int u=U.se,id=U.fi;
		if (ans[id]) continue;
		ans[id]=k;
		dfs(u);
		return;
	}
	for (auto U:S[k][1])
	{
		int u=U.se,id=U.fi;
		if (ans[id]) continue;
		ans[id]=k;
		dfs(u);
		return;
	}
}
void dfs1(int k)
{
	if (vis[k]) return;
	vis[k]=1;
	if (k<=m) return;
	if (E[lson[k]]!=ans[k]&&E1[lson[k]]!=ans[k]) swap(lson[k],rson[k]);
	ans[lson[k]]=ans[k];
	ans[rson[k]]=E[lson[k]]^ans[k]^E1[lson[k]];
	dfs1(lson[k]);
	dfs1(rson[k]);
}
void LYC_music()
{
	n=read(),m=read();
	cnt=m;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		S[u][w].insert({i,v});
		S[v][w].insert({i,u});
		E[i]=u;
		E1[i]=v;
		V[u]+=w;
		V[v]+=w;
	}
	int Ans=0;
	for (int i=1;i<=n;i++)
		if (V[i]&1) Ans++;
	writeln(Ans);
	for (int i=n;i>=1;i--) solve(i);
	for (int i=n;i>=1;i--) solve(i);
	for (int i=1;i<=n;i++)
		c[i]=i;
	sort(c+1,c+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int x=c[i];
		dfs(c[i]);
	}
	for (int i=cnt;i>=1;i--)
		dfs1(i);
	for (int i=1;i<=m;i++)
	{
		if (!ans[i])
		{
			cout<<"???"<<E[i]<<" "<<E1[i]<<" "<<i<<" "<<Ers[i]<<" "<<Fa[i]<<endl;
			return;
		}
		write((ans[i]!=E[i])+1);
	}
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
5 5
4 2 2
1 5 1
5 1 2
3 2 1
5 2 2
21211
*/