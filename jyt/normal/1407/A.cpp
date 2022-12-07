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
#define N 1005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],cnt0,cnt1;
int main()
{
	for(scanf("%d",&T);T--;cnt0=cnt1=0,puts(""))
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),A[i]?cnt1++:cnt0++;
		if(cnt0>=cnt1)
		{
			printf("%d\n",cnt0);
			for(int i=1;i<=cnt0;i++) printf("0 ");
		}
		else
		{
			if(cnt1&1) cnt1--;
			printf("%d\n",cnt1);
			for(int i=1;i<=cnt1;i++) printf("1 ");
		}
	}
	return 0;
}