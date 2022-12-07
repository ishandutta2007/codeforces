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
#define N 55
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],mark[N],ans;
void clear()
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) mark[A[j]-A[i]]=0;
	ans=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		std::sort(A+1,A+1+n);
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(!mark[A[j]-A[i]]) mark[A[j]-A[i]]=1,ans++;
		printf("%d\n",ans);
		// dbg2(ans);
	}
	return 0;
}