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
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
// #define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,m;
ll a[N];
int p[N],ip[N];
struct
{
	int opt,l,r;
}q[N];
int nx[N];
int vis[N];
int dfn[N];
int cnt;
int id[N];
int tim;
ll s[N];
int Dfn[N];
ll tag[N];
vector<int>G[N];
void getpre()
{
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	getpre();
	for (int i=1;i<=n;i++) p[i]=read(),ip[p[i]]=i;
	m=read();
	int B=1000;
	for (int nowi=1;nowi<=(m-1)/B+1;nowi++)
	{
		int L=(nowi-1)*B+1,R=min(m,nowi*B);
		// int tt=0;
		for (int j=L;j<=R;j++)
		{
			q[j].opt=read(),q[j].l=read(),q[j].r=read();
			if (q[j].opt==3)
			{
				vis[q[j].l]=1;
				vis[q[j].r]=1;
				// vis[p[q[j].l]]=1;
				// vis[p[q[j].r]]=1;
				// tt++;
			} else 
			if (q[j].opt==2)
			{
				vis[q[j].l]=1;
				// vis[p[q[j].l]]=1;
			}
		}
		cnt=0;
		++tim;
		for (int i=1;i<=n;i++)
		{
			if ((vis[i])&&dfn[i]!=tim)
			{
				int x=i;
				++cnt;
				x=ip[i];
				id[i]=cnt;
				dfn[i]=tim;
				while (!vis[x]&&dfn[x]!=tim)
				{
					dfn[x]=tim;
					id[x]=cnt;
					x=ip[x];
				}
			}
		}
		for (int i=1;i<=n;i++)
			if (vis[i]) nx[id[i]]=id[p[i]];
		for (int i=1;i<=n;i++)
			G[id[i]].push_back(i);
		for (int i=1;i<=cnt;i++) tag[i]=0;
		for (int i=L;i<=R;i++)
		{
			if (q[i].opt==1)
			{
				ll res=0;
				for (int j=1;j<=cnt;j++)
				{
					res+=1ll*tag[j]*(lower_bound(G[j].begin(),G[j].end(),q[i].r+1)-G[j].begin()-(lower_bound(G[j].begin(),G[j].end(),q[i].l)-G[j].begin()));
				}
				writeln(s[q[i].r]-s[q[i].l-1]+res);
			} else
			if (q[i].opt==2)
			{
				int x=id[q[i].l];
				++tim;
				while (Dfn[x]!=tim&&x)
				{
					Dfn[x]=tim;
					tag[x]+=q[i].r;
					x=nx[x];
				}
			} else
			{
				swap(nx[id[q[i].l]],nx[id[q[i].r]]);
				swap(ip[p[q[i].l]],ip[p[q[i].r]]);
				swap(p[q[i].l],p[q[i].r]);
			}
		}
		for (int i=1;i<=n;i++) a[i]+=tag[id[i]];
		getpre();
		for (int i=1;i<=n;i++) vis[i]=0,id[i]=0;
		for (int i=1;i<=cnt;i++) G[i].clear(),tag[i]=0;
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