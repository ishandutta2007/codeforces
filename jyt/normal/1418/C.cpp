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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],f[N][2];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=0;i<=n;i++) f[i][0]=f[i][1]=inf;
		f[0][0]=0,f[1][1]=A[1];
		for(int i=2;i<=n;i++)
		{
			f[i][0]=min(f[i-1][1],f[i-2][1]);
			f[i][1]=min(f[i-1][0]+A[i],f[i-2][0]+A[i-1]+A[i]);
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
	return 0;
}