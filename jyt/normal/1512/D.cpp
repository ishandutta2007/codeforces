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
int T,n,A[N];
void Solve()
{
	ll Sum=0;
	for(int i=1;i<n;i++) Sum+=A[i];
	// dbg2(Sum);
	for(int i=1;i<n;i++)
		if(Sum-A[i]==A[n])
		{
			for(int j=1;j<n;j++) if(i^j) printf("%d ",A[j]);
			puts("");
			return;
		}
	if(Sum-A[n-1]==A[n-1])
	{
		for(int i=1;i<=n-2;i++) printf("%d ",A[i]);
		puts("");
		return;
	}
	puts("-1");
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n),n+=2;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		std::sort(A+1,A+1+n);
		Solve();
	}
	return 0;
}