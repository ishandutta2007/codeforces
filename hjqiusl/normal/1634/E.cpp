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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int m,cnt,tot;
map<int,int>Mp;
int U[500005];
vector<pa>G[500005];
int vis[500005];
int v[500005];
int B[500005];
int ers[500005];
int tot1;
void dfs(int x)
{
	vis[x]=1;
	while (G[x].size())
	{
		int u=G[x].back().fi,w=G[x].back().se;
		G[x].pop_back();
		if (ers[u]) continue;
		ers[u]=1;
		dfs(U[u]^x);
		v[u]=w;
	}
}
void BellaKira()
{
	m=read();
	cnt=m;
	for (int i=1;i<=m;i++)
	{
		int x=read();
		B[i]=x;
		for (int j=1;j<=x;j++)
		{
			int p=read();
			if (!Mp.count(p))
			{
				Mp[p]=++cnt;
			}
			U[++tot]=Mp[p]^i;
			G[i].push_back(mp(tot,0));
			G[Mp[p]].push_back(mp(tot,1));
		}
	}
	for (int i=1;i<=cnt;i++)
		if (G[i].size()%2==1) return puts("NO"),void();
	for (int i=1;i<=cnt;i++)
	{
		if (!vis[i]) dfs(i);
	}
	puts("YES");
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=B[i];j++)
		{
			tot1++;
			if (v[tot1]) cout<<"R";
			else  cout<<"L";
		}
		cout<<endl;
	}
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