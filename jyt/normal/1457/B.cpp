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
int T,n,m,Max,A[N],ans;
int Solve(int x)
{
	int res=0;
	for(int i=1;i<=n;i++) if(A[i]^x) res++,i+=m-1;
	return res;
}
int main()
{
	for(scanf("%d",&T);T--;Max=0)
	{
		scanf("%d%d",&n,&m),ans=n;
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),Max=max(Max,A[i]);
		for(int i=1;i<=Max;i++) ans=min(ans,Solve(i));
		printf("%d\n",ans);
	}
	return 0;
}