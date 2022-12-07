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
#define N 105
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],Min,Max;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n),Min=100,Max=-100;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),Min=min(Min,A[i]),Max=max(Max,A[i]);
		if(Min<0) puts("NO");
		else
		{
			puts("YES");
			printf("%d\n",Max+1);
			for(int i=0;i<=Max;i++) printf("%d ",i);puts("");
		}
	}
	return 0;
}