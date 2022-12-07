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
#define N 55
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N],B[N],flag;
int main()
{
	for(scanf("%d",&T);T--;flag=0)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++) scanf("%d",&B[i]);
		std::sort(A+1,A+1+n),std::sort(B+1,B+1+n);
		for(int i=1;i<=n;i++) if(A[i]+B[n-i+1]>m) flag=1;
		puts(flag?"No":"Yes");
	}
	return 0;
}