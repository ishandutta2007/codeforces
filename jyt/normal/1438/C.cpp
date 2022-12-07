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
#define N 5005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N][N];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&A[i][j]),A[i][j]+=(i+j&1)^(A[i][j]&1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) printf("%d%c",A[i][j],j<m?' ':'\n');
	}
	return 0;
}