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
int T,n,A[N];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		if(A[1]!=A[2])
		{
			if(A[1]==A[3]) puts("2");
			else puts("1");
		}
		else for(int i=3;i<=n;i++) if(A[i]!=A[1]) {printf("%d\n",i);break;}
	}
	return 0;
}