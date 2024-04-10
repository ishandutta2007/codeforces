#include<bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
struct segtree
{
	int l,r;
	int lnum,rnum;
	ll count;
	segtree()
	{
		l=r=lnum=rnum=count=0;
	}
}SegTree[800800];
int a[200200];
void pushup(int u)
{
	if(SegTree[u].l==SegTree[u].r)
	{
		SegTree[u].lnum=SegTree[u].rnum=SegTree[u].count=1;
		return ;
	}
	if(a[SegTree[u<<1].r]<=a[SegTree[u<<1|1].l])
	{
		if(SegTree[u<<1].lnum==SegTree[u<<1].r-SegTree[u<<1].l+1)
			SegTree[u].lnum=SegTree[u<<1].r-SegTree[u<<1].l+1+SegTree[u<<1|1].lnum;
		else	SegTree[u].lnum=SegTree[u<<1].lnum;
		if(SegTree[u<<1|1].lnum==SegTree[u<<1|1].r-SegTree[u<<1|1].l+1)
			SegTree[u].rnum=SegTree[u<<1|1].r-SegTree[u<<1|1].l+1+SegTree[u<<1].rnum;
		else	SegTree[u].rnum=SegTree[u<<1|1].rnum;
		SegTree[u].count=SegTree[u<<1].count+SegTree[u<<1|1].count+1ll*SegTree[u<<1].rnum*SegTree[u<<1|1].lnum;
	}
	else
	{
		SegTree[u].lnum=SegTree[u<<1].lnum;
		SegTree[u].rnum=SegTree[u<<1|1].rnum;
		SegTree[u].count=SegTree[u<<1].count+SegTree[u<<1|1].count;
	}
}
inline void reconstruct(int u,int l,int r)
{
	SegTree[u].l=l;
	SegTree[u].r=r;
	if(l==r)
	{
		pushup(u);
		return ;
	}
	int mid=(l+r)/2;
	reconstruct(u<<1,l,mid);
	reconstruct(u<<1|1,mid+1,r);
	pushup(u);
}
inline void update(int u,int p)
{
	if(SegTree[u].l!=SegTree[u].r)
	{
		int mid=(SegTree[u].l+SegTree[u].r)/2;
		if(p<=mid)
			update(u<<1,p);
		else	update(u<<1|1,p);
	}
	pushup(u);
}
inline ll query(int u,int l,int r)
{
	if(SegTree[u].l==l&&SegTree[u].r==r)
		return SegTree[u].count;
	if(SegTree[u].l==SegTree[u].r)
		return 1ll;
	int mid=(SegTree[u].l+SegTree[u].r)/2;
	if(r<=mid)
		return query(u<<1,l,r);
	else if(l>mid)
		return query(u<<1|1,l,r);
	else
	{
		int L=min(SegTree[u<<1].rnum,mid-l+1);
		int R=min(SegTree[u<<1|1].lnum,r-mid);
		return query(u<<1,l,mid)+query(u<<1|1,mid+1,r)+1ll*L*R*(bool)(a[mid]<=a[mid+1]);
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	reconstruct(1,1,n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		update(1,i);
	while(q--)
	{
		int aa,b,c;
		scanf("%d%d%d",&aa,&b,&c);
		if(aa^1)
		{
			printf("%I64d\n",query(1,b,c));
		}
		else
		{
			a[b]=c;
			update(1,b);
		}
	}
	return 0;
}