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
#define N 400005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N];ll Sum;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&m,&n),Sum=0;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		std::sort(A+1,A+1+n);
		for(int i=n;~i;i--)
		{
			// if(A[i]<=n-i) {printf("%d\n",n-i);break;}
			Sum+=m-A[i];
			if(Sum>=m||!i) {printf("%d\n",n-i);break;}
		}
	}
	return 0;
}