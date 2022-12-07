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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],id[N],Sum[N],Maxl,Minl,Maxr,Minr,ans[N];
class SegmentTree
{
#define lc x<<1
#define rc x<<1|1
#define mid (l+r>>1)
	struct node{int f,mx,mn;}t[N<<2];
	void upd(int x,int v) {t[x].f+=v,t[x].mx+=v,t[x].mn+=v;}
	void pushup(int x) {t[x].mx=max(t[lc].mx,t[rc].mx),t[x].mn=min(t[lc].mn,t[rc].mn);}
	void pushdown(int x) {if(t[x].f) upd(lc,t[x].f),upd(rc,t[x].f),t[x].f=0;}
public:
	void build(int x,int l,int r)
	{
		if(l==r) return void(t[x].mx=t[x].mn=l);
		build(lc,l,mid),build(rc,mid+1,r);
		pushup(x);
	}
	void add(int x,int l,int r,int _l,int _r,int v)
	{
		if(_l<=l&&r<=_r) return upd(x,v);
		pushdown(x);
		if(_l<=mid) add(lc,l,mid,_l,_r,v);
		if(_r>mid) add(rc,mid+1,r,_l,_r,v);
		pushup(x);
	}
	void ask(int x,int l,int r,int _l,int _r,int &Max,int &Min)
	{
		if(_l<=l&&r<=_r) {Max=max(Max,t[x].mx),Min=min(Min,t[x].mn);return;}
		pushdown(x);
		if(_l<=mid) ask(lc,l,mid,_l,_r,Max,Min);
		if(_r>mid) ask(rc,mid+1,r,_l,_r,Max,Min);
	}
}T;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),id[i]=i;
	std::sort(id+1,id+1+n,[](int t1,int t2){return A[t1]<A[t2];});
	T.build(1,0,n);
	for(int i=1,j=1,p;i<=n;i++) if(i==n||A[id[i]]!=A[id[i+1]])
	{
		// dbg1(i),dbg2(j);
		for(int k=j;k<=i;k++)
		{
			p=id[k],Maxl=Maxr=-inf,Minl=Minr=inf;
			T.ask(1,0,n,0,p,Maxl,Minl);
			T.ask(1,0,n,p,n,Maxr,Minr);
			// dbg1(k),dbg1(Maxl),dbg1(Minl),dbg1(Maxr),dbg2(Minr);
			if(Maxr-Minl>0) ans[p]=(Maxr-Minl)/2;
			if(Minr-Maxl<0) ans[p]=max(ans[p],(Maxl-Minr)/2);
		}
		for(int k=j;k<=i;k++) T.add(1,0,n,id[k],n,-2);
		for(int k=j;k<=i;k++)
		{
			p=id[k],Maxl=Maxr=-inf,Minl=Minr=inf;
			T.ask(1,0,n,0,p,Maxl,Minl);
			T.ask(1,0,n,p,n,Maxr,Minr);
			// dbg1(k),dbg1(Maxl),dbg1(Minl),dbg1(Maxr),dbg2(Minr);
			if(Maxr-Minl>0) ans[p]=max(ans[p],(Maxr-Minl+1)/2);
			if(Minr-Maxl<0) ans[p]=max(ans[p],(Maxl-Minr-1)/2);
		}
		j=i+1;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}