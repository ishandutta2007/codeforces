//QwQcOrZ yyds!!!
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
#define N 200005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m,P,f[N],w[N],p[N],dep[N],st[N][25];
int cnt;
vector<int>G[N];
pa E[N];
bool cmp(int x,int y)
{
	return w[x]<w[y];
}
int gf(int x)
{
	if (x==f[x]) return x;
	return f[x]=(gf(f[x]));
}
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) x=st[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i]) x=st[x][i],y=st[y][i];
	return st[x][0];
}
vector<int>work(int x,int y)
{
	int z=lca(x,y);
	vector<int>g;
	while (x!=z)
	{
		g.push_back(x);
		x=st[x][0];
	}
	g.push_back(z);
	vector<int>g1;
	while (y!=z)
	{
		g1.push_back(y);
		y=st[y][0];
	}
	reverse(g1.begin(),g1.end());
	for (auto u:g1) g.push_back(u);
	return g;
}
signed main()
{
	n=read();m=read(),P=read();
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (gf(u)==gf(v)) E[++cnt]={u,v};
		else
		{
			f[gf(u)]=gf(v);
			ad(u,v);
			ad(v,u);
		}
	}
	dfs(1,0);
	if (m==n-1)
	{
		int x=0,y=0,z=0;
		for (int i=1;i<=n;i++)
			if (dep[i]%2) x++;
			else y++;
		if (x<y)
		{
			writeln(1);
			for (int i=1;i<=n;i++)
				if (dep[i]%2==0) 
				{
					z++;
					writesp(i);
					if (z==(P/2)+(P%2)) break;
				}
			return 0;
		}
			writeln(1);
			for (int i=1;i<=n;i++)
				if (dep[i]%2)
				{
					z++;
					writesp(i);
					if (z==(P/2)+(P%2)) break;
				}
			return 0;
	}
		
	for (int i=1;i<=cnt;i++)
	{
		int x=E[i].fi,y=E[i].se,z=dep[x]+dep[y]-dep[lca(x,y)]*2+1;
//		cout<<x<<" "<<y<<" "<<z<<" "<<lca(x,y)<<endl;
		w[i]=z;
		p[i]=i;
	}
	sort(p+1,p+cnt+1,cmp);
	for (int i=1;i<=cnt;i++)
	{
		int x=E[p[i]].fi,y=E[p[i]].se;
		if (w[p[i]]<=P)
		{
			writeln(2);
			auto g=work(x,y);
			writeln(g.size());
			for (auto u:g) writesp(u);
			puts("");
			return 0;
		} else
		{
			writeln(1);
			auto g=work(x,y);
			for (int i=0;i<g.size()-1;i+=2)
			{
				writesp(g[i]);
				if ((i/2)+1==(P/2+P%2)) break;
			}
			return 0;
		}
	}
}	
/*

*/