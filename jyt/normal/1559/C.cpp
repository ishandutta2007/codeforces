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
int T,n,A[N],st;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		if(A[1])
		{
			printf("%d ",n+1);
			for(int i=1;i<=n;i++) printf("%d ",i);
			puts("");
			continue;
		}
		if(!A[n])
		{
			for(int i=1;i<=n;i++) printf("%d ",i);
			printf("%d\n",n+1);
			continue;
		}
		st=0;
		for(int i=1;i<n&&!st;i++) if(!A[i]&&A[i+1]) st=i;
		if(!st) {puts("-1");continue;}
		for(int i=1;i<=st;i++) printf("%d ",i);
		printf("%d ",n+1);
		for(int i=st+1;i<=n;i++) printf("%d ",i);
		puts("");
	}
	return 0;
}