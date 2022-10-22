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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int pr[N],cnt,vis[N],id[N];
int inv[N];
poly E[N];
int f[N],g[N];
int a[N];
int n;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		y>>=1;
		x=x*x%mod;
	}
	return res;
}
struct node
{
	int v,x,y;
	node(){v=x=y=0;}
	node(int to,int a,int b){v=to,x=a,y=b;}
};
vector<node>G[N];
void ad(int x,int y,int wx,int wy)
{
	G[x].push_back(node(y,wx,wy));
}
void dfs(int k,int fa)
{
	for (auto U:G[k])
	{
		int u=U.v;
		if (u==fa) continue;
		int x=U.x,y=U.y;
		
        for (auto uu:E[x]) f[uu]--;
        for (auto uu:E[y]) f[uu]++;
        // cout<<"?"<<u<<" "<<k<<" "<<x<<" "<<y<<" "<<g[2]<<" "<<f[2]<<endl;
        
        for (auto uu:E[x])
        	g[uu]=min(g[uu],f[uu]);
        for (auto uu:E[y])
        	g[uu]=min(g[uu],f[uu]);
        	
		dfs(u,k);
		
        for (auto uu:E[x]) f[uu]++;
        for (auto uu:E[y]) f[uu]--;
        // cout<<"!"<<x<<" "<<y<<endl;
    }
}
void dfs1(int k,int fa)
{
	for (auto U:G[k])
	{
		int u=U.v;
		if (u==fa) continue;
		int x=U.x,y=U.y;
		a[u]=a[k];
        for (auto uu:E[y]) a[u]=a[u]*uu%mod;
        for (auto uu:E[x]) a[u]=a[u]*inv[uu]%mod;
		dfs1(u,k);
    }
}
void BellaKira()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),wx=read(),wy=read();
		ad(x,y,wx,wy);
		ad(y,x,wy,wx);
	}
	dfs(1,0);
	a[1]=1;
	for (int i=1;i<=n;i++) a[1]=quickPower(i,max(0ll,-g[i]))*a[1]%mod;
	dfs1(1,0);
	for (int i=2;i<=n;i++) a[1]=(a[1]+a[i])%mod;
	writeln(a[1]);
	for (int i=1;i<=n;i++) a[i]=0,G[i].clear(),f[i]=g[i]=0;
}
signed main()
{
	for (int i=0;i<=200000;i++) inv[i]=quickPower(i,mod-2);
	for (int i=2;i<=200000;i++)
	{
		int now=i;
		for (int j=2;j*j<=now;j++)
		{
			if (now%j==0)
			{
				while (now%j==0)
				{
					E[i].push_back(j);
					now/=j;
				}
			}
		}
		if (now!=1) E[i].push_back(now);
	}
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/