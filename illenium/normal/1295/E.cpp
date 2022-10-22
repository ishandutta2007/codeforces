#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e18
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],p[maxn],sum[maxn];
struct node{ll l,r,mn,w;}t[maxn<<3];

inline void upd(int now){t[now].mn=min(t[now<<1].mn,t[now<<1|1].mn);}

inline void pd(int now)
{
	if(t[now].w==0) return;
	t[now].mn+=t[now].w; t[now<<1].w+=t[now].w; t[now<<1|1].w+=t[now].w; t[now].w=0;
}

inline void build(int now,int l,int r)
{
	t[now].l=l; t[now].r=r; int mid=(l+r)>>1;
	if(l==r) {t[now].mn=sum[l]; return;}
	build(now<<1,l,mid); build(now<<1|1,mid+1,r); upd(now);
}

inline void add(int now,int l,int r,ll w)
{
	if(l>r) return;
	if(t[now].w) pd(now);
	if(t[now].l==l&&t[now].r==r) {t[now].w+=w; pd(now); return;}
	int mid=(t[now].l+t[now].r)>>1;
	if(l>=mid+1) add(now<<1|1,l,r,w),pd(now<<1);
	else if(r<=mid) add(now<<1,l,r,w),pd(now<<1|1);
	else add(now<<1,l,mid,w),add(now<<1|1,mid+1,r,w); upd(now);
}

inline ll query(int now,int x)
{
	if(t[now].w) pd(now);
	if(t[now].l==x&&t[now].r==x) return t[now].mn;
	int mid=(t[now].l+t[now].r)>>1;
	if(x<=mid) return query(now<<1,x); else return query(now<<1|1,x);
}

int main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) {int x=read(); p[a[i]]=x;}
	for(int i=1;i<=(n<<2);i++) t[i].mn=inf;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i]; build(1,1,n);
	ll ans=min(p[a[n]],p[a[1]]);
	for(int i=1;i<=n-1;i++)
	{
		//for(int j=1;j<=n;j++) cout<<query(1,j)<<" "; cout<<t[1].mn<<" "<<t[2].mn<<" "<<t[3].mn<<endl;
		add(1,a[i],n,-p[a[i]]); add(1,1,a[i]-1,p[a[i]]); pd(1);
		ans=min(ans,t[1].mn); //cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}