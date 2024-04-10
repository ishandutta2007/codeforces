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
#define N 505
#define inf 1e18
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n;ll f[N][N],ans=inf;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) f[i][j]=inf;
	f[1][n]=0;
	for(int i=1;i<=n;i++)
		for(int j=n;j>i;j--)
			if(f[i][j]<inf)
			{
				f[i+1][j]=min(f[i+1][j],f[i][j]+i*(i+1)*j);
				f[i][j-1]=min(f[i][j-1],f[i][j]+i*(j-1)*j);
			}
	for(int i=1;i<n;i++) ans=min(ans,f[i][i+1]);
	printf("%lld\n",ans);
	return 0;
}