#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,A[N],op,a,b;
class SegmentTree
{
#define lc x<<1
#define rc x<<1|1
#define mid ((l+r)>>1)
	struct node
	{
		int vl,vr,pl,pr,l,r;ll v;
		node() {vl=vr=pl=pr=v=0;}
		friend node operator+(node t1,node t2)
		{
			node res;
			res.vl=t1.vl,res.vr=t2.vr,res.l=t1.l,res.r=t2.r;
			if(t1.pl==t1.r&&t1.vr<=t2.vl) res.pl=t2.pl;
			else res.pl=t1.pl;
			if(t2.pr==t2.l&&t1.vr<=t2.vl) res.pr=t1.pr;
			else res.pr=t2.pr;
			res.v=t1.v+t2.v;
			if(t1.vr<=t2.vl) res.v+=(ll)(t1.r-t1.pr+1)*(t2.pl-t2.l+1);
			return res;
		}
	}t[N<<2];
public:
	void build(int x,int l,int r)
	{
		t[x].l=l,t[x].r=r;
		if(l==r)
		{
			t[x].vl=t[x].vr=A[l],t[x].pl=t[x].pr=l,t[x].v=1;
			return;
		}
		build(lc,l,mid),build(rc,mid+1,r),t[x]=t[lc]+t[rc];
		// dbg1(t[x].l),dbg1(t[x].r),dbg1(t[x].pl),dbg1(t[x].pr),dbg2(t[x].v);
	}
	void change(int x,int l,int r,int p,int v)
	{
		if(l==r)
		{
			t[x].vl=t[x].vr=A[l],t[x].pl=t[x].pr=l,t[x].v=1;
			return;
		}
		p<=mid?change(lc,l,mid,p,v):change(rc,mid+1,r,p,v);
		t[x]=t[lc]+t[rc];
	}
	node ask(int x,int l,int r,int _l,int _r)
	{
		if(_l<=l&&r<=_r) return t[x];
		if(_r<=mid) return ask(lc,l,mid,_l,_r);
		if(_l>mid) return ask(rc,mid+1,r,_l,_r);
		return ask(lc,l,mid,_l,_r)+ask(rc,mid+1,r,_l,_r);
	}
	ll Ask(int l,int r) {return ask(1,1,n,l,r).v;}
}T;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	T.build(1,1,n);
	for(;m--;)
	{
		scanf("%d%d%d",&op,&a,&b);
		if(op==1) A[a]=b,T.change(1,1,n,a,b);
		else printf("%lld\n",T.Ask(a,b));
	}
	return 0;
}