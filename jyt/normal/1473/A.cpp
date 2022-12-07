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
int T,n,m,A[N],flag,ans;
int main()
{
	for(scanf("%d",&T);T--;flag=ans=0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),flag|=A[i]>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++) if(A[i]+A[j]<=m) ans=1;
		puts(flag&&!ans?"NO":"YES");
	}
	return 0;
}