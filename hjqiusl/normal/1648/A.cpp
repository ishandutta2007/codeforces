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
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
poly g[N],g1[N];
int n,m;
int ans;
void BellaKira()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			int x=read();
			g[x].push_back(i);
			g1[x].push_back(j);
		}
	}
	for (int i=1;i<=100000;i++)
	{
		sort(g[i].begin(),g[i].end());
		int sm=0,sm1=0;
		for (auto u:g[i]) sm1+=u;
		for (int j=0;j<g[i].size();j++)
		{
			int u=g[i][j];
			sm1-=u;
			sm+=u;
			ans+=u*(j+1)-sm;
			ans+=sm1-u*(g[i].size()-j-1);
		}
	}
	for (int i=1;i<=100000;i++)
	{
		sort(g1[i].begin(),g1[i].end());
		int sm=0,sm1=0;
		for (auto u:g1[i]) sm1+=u;
		for (int j=0;j<g1[i].size();j++)
		{
			int u=g1[i][j];
			sm1-=u;
			sm+=u;
			ans+=u*(j+1)-sm;
			ans+=sm1-u*(g1[i].size()-j-1);
		}
	}
	writeln(ans/2);
	
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