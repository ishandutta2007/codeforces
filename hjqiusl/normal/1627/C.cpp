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
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int du[N],a[N];
int s;
int vs[N];
int n;
vector<pa>G[N];
void BellaKira()
{
	n=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		du[x]++,du[y]++;
		G[x].push_back(mp(y,i));
		G[y].push_back(mp(x,i));
//		U[i]=x,V[i]=y;
	}
	int ans=1;
	for (int i=1;i<=n;i++)
		if (du[i]>2) ans=0;
		else
		{
			if (du[i]==1) s=i;
		}
	if (!ans) puts("-1");
	else
	{
	for (int i=1;i<=n;i++)
	{
		vs[s]=1;
		for (auto U:G[s])
		{
			int u=U.fi;
			if (vs[u]) continue;
			s=u;
			a[U.se]=((i%2==1)?2:3);
			break;
		}
	}
	for (int i=1;i<n;i++) writesp(a[i]);
	puts("");
	}
	for (int i=1;i<=n;i++) G[i].clear(),a[i]=du[i]=0,vs[i]=0;
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