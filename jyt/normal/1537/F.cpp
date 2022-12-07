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
int T,n,m,A[N],B[N],a,b,fa[N<<1];ll flag,Sum1,Sum2;
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
void merge(int x,int y) {int f1=find(x),f2=find(y);if(f1^f2) fa[f1]=f2;}
void clear() {flag=Sum1=Sum2=0;}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&B[i]);
		for(int i=1;i<=n<<1;i++) fa[i]=i;
		for(int i=1;i<=m;i++) scanf("%d%d",&a,&b),merge(a,b+n),merge(a+n,b);
		for(int i=1;i<=n;i++) if(find(i)==find(i+n)) flag=1;
		for(int i=1;i<=n;i++) fa[1]^fa[i]?Sum1+=B[i]-A[i]:Sum2+=B[i]-A[i];
		if((Sum1+Sum2)&1) puts("No");
		else if(flag) puts("Yes");
		else if(Sum1==Sum2) puts("Yes");
		else puts("No");
	}
	return 0;
}