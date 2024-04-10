//The Hunting Party - Keys To The Kingdom
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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int mx[N<<2],tag[N<<2];
int n,m,q;
pa a[N],b[N];
int ans;
vector<pa>G[N];
void pushdown(int k)
{
	if (!tag[k]) return;
	mx[k<<1]+=tag[k];
	mx[k<<1|1]+=tag[k];
	tag[k<<1]+=tag[k];
	tag[k<<1|1]+=tag[k];
	tag[k]=0;
}
void pushup(int k)
{
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		mx[k]=-b[l].se;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R,int w)
{
	if (L>R) return;
	if (L<=l&&r<=R)
	{
		mx[k]+=w;
		tag[k]+=w;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid) update(k<<1,l,mid,L,R,w);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,w);
	pushup(k);
}
void LYC_music()
{
	ans=-inf;
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1);
	for (int i=1;i<=m;i++) b[i].fi=read(),b[i].se=read();
	sort(b+1,b+m+1);
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read(),w=read();
		x=lower_bound(a+1,a+n+1,mp(x+1,0ll))-a;
		y=lower_bound(b+1,b+m+1,mp(y+1,0ll))-b;
		G[x].push_back({y,w});
	}
	build(1,1,m);
	for (int i=1;i<=n;i++)
	{
		for (auto u:G[i])
		{
			update(1,1,m,u.fi,m,u.se);
		}
		ans=max(ans,mx[1]-a[i].se);
	}
	writeln(ans);
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/