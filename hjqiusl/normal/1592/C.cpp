//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
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
vector<int>G[N];
int T,n,m,a[N],ans,ans1;
int f[N],sm,x,y;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void dfs(int k,int fa)
{
	f[k]=a[k];
	int now=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
		f[k]^=f[u];
	}
	if (k!=1)
	{
		if (f[k]==0||f[k]==sm) ans1++;
	}
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		sm=0;
		for (int i=1;i<=n;i++) a[i]=read(),sm^=a[i];
		for (int i=1;i<n;i++)
		{
			x=read(),y=read();
			ad(x,y);
			ad(y,x);
		}
		ans=0,ans1=0;
		dfs(1,0);
		if (sm==0)
		{
			puts("YES");
		} else
		if ((ans1>=2)&&(m>2))
		{
			puts("YES");
		}
		else puts("NO");
		for (int i=1;i<=n;i++) G[i].clear(),f[i]=0;
	}
}
/*

*/