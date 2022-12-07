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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,f[N],to[N],mark[N];
struct info{int x,l,r;}A[N];
int minp(int x,int y) {return f[x]-x<f[y]-y?x:y;}
class SegmentTree
{
#define lc t[x].ls
#define rc t[x].rs
#define mid ((l+r)>>1)
	struct node{int ls,rs,v,f;}t[N*32];
public:
	int root,cntnode;
	void change(int &x,int l,int r,int _l,int _r,int v)
	{
		if(!x) x=++cntnode;
		t[x].v=minp(t[x].v,v);
		if(_l<=l&&r<=_r) return void(t[x].f=minp(t[x].f,v));
		if(_l<=mid) change(lc,l,mid,_l,_r,v);
		if(_r>mid) change(rc,mid+1,r,_l,_r,v);
	}
	int ask(int x,int l,int r,int _l,int _r,int v=0)
	{
		if(!x||_l<=l&&r<=_r) return minp(v,t[x].v);
		v=minp(v,t[x].f);int res=0;
		if(_l<=mid) res=ask(lc,l,mid,_l,_r,v);
		if(_r>mid) res=minp(res,ask(rc,mid+1,r,_l,_r,v));
		return res;
	}
}T;
int main()
{
	scanf("%d%d",&n,&m),f[n+1]=n;
	for(int i=1;i<=m;i++) scanf("%d%d%d",&A[i].x,&A[i].l,&A[i].r);
	std::sort(A+1,A+1+m,[](info t1,info t2){return t1.x<t2.x;});
	for(int i=1,j=1,k,Min;i<=n;i++)
	{
		for(Min=0,k=j;A[j].x==i;j++)
			Min=minp(Min,T.ask(T.root,1,1e9,A[j].l,A[j].r));
		f[i]=f[Min]-Min+i-1,to[i]=Min,to[n+1]=minp(to[n+1],i);
		for(j=k;A[j].x==i;j++)
			T.change(T.root,1,1e9,A[j].l,A[j].r,i);
	}
	for(int i=to[n+1];i;i=to[i]) mark[i]=1;
	printf("%d\n",f[to[n+1]]-to[n+1]+n);
	for(int i=1;i<=n;i++) if(!mark[i]) printf("%d ",i);
	return 0;
}