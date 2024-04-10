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
#define inf 1e18
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N],B[N];ll now,ti,ans;
void clear()
{
	now=ti=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&n,&m),ans=inf;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<n;i++) scanf("%d",&B[i]);
		for(int i=1,tmp;i<=n;i++)
		{
			// dbg1(i),dbg1(ti),dbg2(now);
			ans=min(ans,ti+(m-now+A[i]-1)/A[i]);
			if(now<B[i]) tmp=(B[i]-now+A[i]-1)/A[i],ti+=tmp,now+=(ll)tmp*A[i];
			now-=B[i],ti++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}