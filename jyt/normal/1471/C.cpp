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
int T,n,m,A[N],B[N];ll Sum[N],tot,ans;
int main()
{
	for(scanf("%d",&T);T--;ans=tot=0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=m;i++) scanf("%d",&B[i]);
		for(int i=1;i<=n;i++) ans+=B[A[i]];
		std::sort(A+1,A+1+n);
		for(int i=1;i<=n;i++) Sum[i]=Sum[i-1]+B[A[i]];
		for(int i=1;i<=min(n,m);i++)
		{
			tot+=B[i];
			ans=min(ans,tot+Sum[n-i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}