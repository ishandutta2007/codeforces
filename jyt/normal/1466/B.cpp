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
int T,n,A[N],ans;
int main()
{
	for(scanf("%d",&T);T--;ans=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
			if(A[i]>A[i-1]) ans++;
			else if(A[i]==A[i-1]) A[i]++,ans++;
			else if(A[i]<A[i-1]) A[i]++;
		printf("%d\n",ans);
	}
	return 0;
}