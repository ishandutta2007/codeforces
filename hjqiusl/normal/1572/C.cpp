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
// #define int ll
#define N 3005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,a[N],f[N][N];
poly G[N];
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		G[a[i]].push_back(i);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			f[i][j]=n;
	for (int len=2;len<=n;len++)
		for (int i=1;i<=n;i++)
		{
			int j=i+len-1;
			f[i][j]=f[i+1][j]+1;
			for (auto u:G[a[i]])
			{
				if (u>j) break;
				if (u>i&&u<=j)
				{
					f[i][j]=min(f[i][j],f[i+1][u-1]+f[u][j]+(u!=i+1));
				}
			}
		}
	writeln(f[1][n]);
	for (int i=1;i<=n;i++) G[i].clear();
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