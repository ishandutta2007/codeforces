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
#define inf 4e18
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,a,b,c,A[N];ll f[N][4];
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	f[0][1]=f[0][2]=f[0][3]=-inf;
	for(int i=1;i<=n;i++)
	{
		f[i][1]=max(f[i-1][1],(ll)A[i]*a);
		f[i][2]=max(f[i-1][2],f[i][1]+(ll)A[i]*b);
		f[i][3]=max(f[i-1][3],f[i][2]+(ll)A[i]*c);
	}
	printf("%lld\n",f[n][3]);
	return 0;
}