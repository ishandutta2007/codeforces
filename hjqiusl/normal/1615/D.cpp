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
int s[N],lst[N],col[N];
vector<int>gg[N],gg1[N];
vector<pa>G[N];
int ky[N];
int n,m;
int Vl[N];
int ans;
void ad(int x,int y,int w)
{
	G[x].push_back(mp(y,w));
	// G[y].push_back(mp(x,
}
void dfs(int k,int fa)
{
	// cout<<"??"<<k<<" "<<s[k]<<endl;
	for (auto U:G[k])
	{
		int u=U.fi,w=U.se;
		if (u==fa) continue;
		if (w==-1)
		{
			// cout<<"??lst"<<" "<<u<<endl;
			lst[u]=u;
			s[u]=s[k];
			ky[u]=1;
			dfs(u,k);
		}
		else
		{
			lst[u]=lst[k];
			s[u]=s[k]^w;
			Vl[u]=w;
			dfs(u,k);
		}
	}
}
void dfs1(int k,int cl)
{
	// cout<<"col "<<k<<" "<<cl<<endl;
	if (!ans) return;
	col[k]=cl;
	for (auto u:gg[k])
	{
		if ((~col[u])&&(col[u]!=cl^1))
		{
			ans=0;
			return;
		}
		if (col[u]==-1) 
			dfs1(u,cl^1);
	}
	for (auto u:gg1[k])
	{
		if ((~col[u])&&(col[u]!=cl))
		{
			ans=0;
			return;
		}
		if (col[u]==-1) 
		{
			// cout<<k<<"->"<<u<<" "<<cl<<endl;
			dfs1(u,cl);
		}
	}
}
void dfs2(int k,int fa,int vl)
{
	s[k]^=vl;
	if (fa)
	{
		if (ky[k])
		{
			if (col[k]==vl)
			{
				cout<<fa<<" "<<k<<" "<<0<<endl;
			} else
			{
				cout<<fa<<" "<<k<<" "<<1<<endl;
				vl^=1;
			}
		} else
		{
			cout<<fa<<" "<<k<<" "<<Vl[k]<<endl;
		}
	}
	for (auto U:G[k])
	{
		int u=U.fi;
		if (u==fa) continue;
		dfs2(u,k,vl);
	}
}
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read(),v=read();
		ad(x,y,v);
		ad(y,x,v);
	}
	s[1]=0;
	dfs(1,0);
	ans=1;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		int w=__builtin_popcount(s[u]^s[v])%2;
		int val=read();
		// cout<<"??"<<w<<" "<<val<<endl;
		if (val!=w)
		{
			int x=lst[u],y=lst[v];
			// cout<<"???"<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<endl;
			if (x==y) 
			{
				ans=0;
				continue;
			}
			gg[x].push_back(y);
			gg[y].push_back(x);
		} else
		{
			int x=lst[u],y=lst[v];
			if (x==y) continue;
			gg1[x].push_back(y);
			gg1[y].push_back(x);
			// cout<<"????"<<x<<" "<<y<<endl;
		}
	}
	// cout<<"?"<<ans<<endl;
	for (int i=0;i<=n;i++) col[i]=-1;
	if (!ans) puts("NO");
	else
	{
		dfs1(0,0);
		for (int i=1;i<=n;i++)
			if (ky[i]&&col[i]==-1)
				dfs1(i,0);
		// cout<<0<<endl;
		// for (int i=1;i<=n;i++)
			// if (ky[i]) cout<<col[i]<<","<<i<<endl;
		if(!ans) puts("NO");
		else
		{
			puts("YES");
			dfs2(1,0,0);
		}
	}
	for (int i=0;i<=n;i++)
		G[i].clear(),gg[i].clear(),ky[i]=0,gg1[i].clear(),lst[i]=0,col[i]=0,s[i]=0;
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