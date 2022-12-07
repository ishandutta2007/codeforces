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
int T,n,m,A[N];ll ans;
int main()
{
	for(scanf("%d",&T);T--;ans=0)
	{
		scanf("%d%d",&n,&m),ans=-1e18;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
			for(int j=max(1,i-2*m);j<i;j++) ans=max(ans,(ll)i*j-m*(A[i]|A[j]));
		printf("%lld\n",ans);
	}
	return 0;
}