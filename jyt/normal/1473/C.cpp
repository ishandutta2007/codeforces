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
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N];
int main()
{
	for(scanf("%d",&T);T--;puts(""))
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<2*m-n;i++) printf("%d ",i);
		for(int i=m;i>=2*m-n;i--) printf("%d ",i);
	}
	return 0;
}