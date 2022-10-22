#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,m,p,c2,P[maxn];
struct node{int a,b;}a[maxn];
struct node2{int a,b;}b[maxn],b2[maxn];
struct node3{int x,y,z;}c[maxn];
struct node4{int l,r,mx,w;}t[maxn<<2];

inline bool cmp(node a,node b){return a.a<b.a;}
inline bool cmp2(node2 a,node2 b){return a.a<b.a;}
inline bool cmp3(node3 a,node3 b){return a.x<b.x;}

inline void upd(int now){t[now].mx=max(t[now<<1].mx,t[now<<1|1].mx);}

inline void pd(int now)
{
	if(t[now].w==0) return;
	if(t[now].l!=t[now].r)
	{
		t[now<<1].w+=t[now].w;
		t[now<<1|1].w+=t[now].w;
	}
	t[now].mx+=t[now].w; t[now].w=0;
}

inline void build(int now,int l,int r)
{
	t[now].l=l; t[now].r=r;
	if(l==r) {t[now].mx=-b2[l].b; return;}
	int mid=(l+r)>>1;
	build(now<<1,l,mid); build(now<<1|1,mid+1,r); upd(now);
}

inline void add(int now,int l,int r,int val)
{
	if(l>r) return; pd(now);
	if(t[now].l==l&&t[now].r==r) {t[now].w+=val; pd(now); return;}
	int mid=(t[now].l+t[now].r)>>1;
	if(l>=mid+1) add(now<<1|1,l,r,val),pd(now<<1);
	else if(r<=mid) add(now<<1,l,r,val),pd(now<<1|1);
	else add(now<<1,l,mid,val),add(now<<1|1,mid+1,r,val); upd(now);
}

inline int query(int now,int l,int r)
{
	if(t[now].l==l&&t[now].r==r) return t[now].mx;
	int mid=(t[now].l+t[now].r)>>1;
	if(l>=mid+1) return query(now<<1|1,l,r);
	else if(r<=mid) return query(now<<1,l,r);
	return max(query(now<<1,l,mid),query(now<<1|1,mid+1,r));
}

int main()
{
	n=read(); m=read(); p=read();
	for(int i=1;i<=n;i++) a[i].a=read(),a[i].b=read();
	for(int i=1;i<=m;i++) b[i].a=read(),b[i].b=read();
	for(int i=1;i<=p;i++) c[i].x=read(),c[i].y=read(),c[i].z=read();
	sort(a+1,a+n+1,cmp); sort(b+1,b+m+1,cmp2); sort(c+1,c+p+1,cmp3);
	for(int i=1;i<=m;i++)
	{
		if(b[i].a==b2[c2].a) b2[c2].b=min(b2[c2].b,b[i].b);
		else b2[++c2]=b[i];
	}
	for(int i=1;i<=c2;i++) P[i]=b2[i].a;
	build(1,1,c2); int st=1; ll ans=-inf;
	//for(int j=1;j<=3;j++) cout<<query(1,j,j)<<" "; cout<<endl;
	for(int i=1;i<=n;i++)
	{
		while(st<=p&&c[st].x<a[i].a)
		{
			int x=upper_bound(P+1,P+c2+1,c[st].y)-P; //cout<<x<<endl;
			add(1,x,c2,c[st].z); st++;
		}
		pd(1); ans=max(ans,(ll)t[1].mx-(ll)a[i].b); //cout<<st<<endl;
		//for(int j=1;j<=3;j++) cout<<query(1,j,j)<<" "; cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}