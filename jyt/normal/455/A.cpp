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
int n,Max,A[N];ll Sum[N],f[N][2];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),Sum[A[i]]+=A[i],Max=max(Max,A[i]);
	for(int i=1;i<=Max;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=f[i-1][0]+Sum[i];
	}
	printf("%lld\n",max(f[Max][0],f[Max][1]));
	return 0;
}