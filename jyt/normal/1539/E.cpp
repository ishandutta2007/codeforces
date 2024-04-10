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
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,C[N],f[N],g[N],to1[N],to2[N];
struct info{int l,r;}A[N],B[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d%d%d%d",&C[i],&A[i].l,&A[i].r,&B[i].l,&B[i].r);
	for(int i=n,p1=n+1,p2=n+1,l1=0,r1=m,l2=0,r2=m;i>=0;i--)
	{
		l1=max(l1,A[i].l),r1=min(r1,A[i].r);
		l2=max(l2,B[i].l),r2=min(r2,B[i].r);
		// dbg1(l1),dbg1(r1),dbg1(l2),dbg1(r2),dbg1(p1),dbg2(p2);
		if(p2&&l1<=C[i]&&C[i]<=r1) f[i]=1,to1[i]=p2;
		if(p1&&l2<=C[i]&&C[i]<=r2) g[i]=1,to2[i]=p1;
		if(f[i]) p1=i,l2=B[i].l,r2=B[i].r;
		if(g[i]) p2=i,l1=A[i].l,r1=A[i].r;
		if(A[i].r<C[i]||C[i]<A[i].l) p1=0;
		if(B[i].r<C[i]||C[i]<B[i].l) p2=0;
	}
	// for(int i=0;i<=n;i++) dbg1(i),dbg1(f[i]),dbg2(g[i]);
	if(!f[0]&&!g[0]) return puts("No"),0;
	puts("Yes");
	for(int i=1,to=f[0]?to1[0]:to2[0],op=f[0]?0:1;i<=n;i++)
	{
		printf("%d ",!op);
		if(i==to) to=op?to1[i]:to2[i],op^=1;
	}
	return 0;
}