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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int A[4][N];ll Sum[4],ans;
int main()
{
	for(int i=1;i<=3;i++) scanf("%d",&A[i][0]);
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=A[i][0];j++) scanf("%d",&A[i][j]),Sum[i]+=A[i][j];
		std::sort(A[i]+1,A[i]+1+A[i][0]);
	}
	ans=Sum[1]+Sum[2]+Sum[3]-2*min(A[1][1]+min(A[2][1],A[3][1]),A[2][1]+A[3][1]);
	for(int i=1;i<=3;i++) ans=max(ans,Sum[1]+Sum[2]+Sum[3]-2*Sum[i]);
	printf("%lld\n",ans);
	return 0;
}