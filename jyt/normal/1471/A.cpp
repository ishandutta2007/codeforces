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
int T,n,m,A[N];ll ans1,ans2;
int main()
{
	for(scanf("%d",&T);T--;ans1=ans2=0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),ans1+=(A[i]-1)/m+1,ans2+=A[i];
		ans2=(ans2-1)/m+1;
		printf("%lld %lld\n",ans2,ans1);
	}
	return 0;
}