//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast",O3,O2)
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < ll,ll >
#define pa1 pair < int,pa >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],vis[N];
int x;
vector<int>g;
int g1[N];
ll ans;
inline void ad(ll &x,ll y)
{
	x=(x+y)%mod;
}
signed main()
{
//	freopen("data.in","r",stdin);
	T=read();
	while (T--)
	{
		n=read();ans=0;
		for (int i=1;i<=n;i++) a[i]=read();
		a[n+1]=0;
		vector<pa1>f,g;
		f.push_back({a[n],{0,1}});
		for (int i=n-1;i>=1;i--)
		{
//			if (i%10000==0) cerr<<"?"<<i<<endl;
			vector<pa1>().swap(g);
			vector<int>G,g1,g2;
			for (int l=1,r;l<=a[i];)
			{
				r=a[i]/(a[i]/l);
				x=(a[i]/l)+((a[i]%l)>0);
				if (g.empty()||g[g.size()-1].fi!=x)
					g.push_back({x,{0,0}}),g1.push_back(l-1),g2.push_back((a[i]/l));
				if (l!=r&&a[i]%r==0)
				{
					x=(a[i]/r);
					if (g.empty()||g[g.size()-1].fi!=x)
						g.push_back({x,{0,0}}),g1.push_back(r-1),g2.push_back((a[i]/r));
				}
				l=r+1;
			}
			reverse(g.begin(),g.end());
			reverse(g1.begin(),g1.end());
			reverse(g2.begin(),g2.end());
			int l=(int)g.size()-1;
			for (int r=(int)f.size()-1;r>=0;r--)
			{
				while (l>=0&&g[l].fi>f[r].fi)
				{
					l--;
				}
				if (l>=0)
				{
					ad(g[l].se.fi,f[r].se.fi+g1[l]*f[r].se.se);
					ad(g[l].se.se,f[r].se.se);
					if (G.empty()||G[(int)G.size()-1]!=l)
						G.push_back(l);
				} else break;
			}
			reverse(G.begin(),G.end());
			vector<pa1>().swap(f);
			for (auto u:G)
			{
				if (f.empty()||g2[u]!=f[f.size()-1].fi)
					f.push_back({g2[u],g[u].se});
				else ad(f[f.size()-1].se.fi,g[u].se.fi),ad(f[f.size()-1].se.se,g[u].se.se);
			}
			if (f.empty()||f[f.size()-1].fi!=a[i])
			{
				f.push_back({a[i],{0,1}});
			} else
				ad(f[f.size()-1].se.se,1);
			for (auto u:f) 
			{
				ad(ans,u.se.fi);
			}
		}
		writeln(ans);
	}
		
				
				
}
/*
1
3
2 3 2

*/