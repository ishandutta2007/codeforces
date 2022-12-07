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
int T,n,A[N],B[N],C[N],Cn;
void Print()
{
	ll Sum=0;int p=0;
	for(int i=1;i<=n;i++) Sum+=A[i],p=Sum<0?i:p;
	dbg2(p);
}
int main()
{
	for(scanf("%d",&T);T--;Cn=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&B[i]);
			if(!B[i]) C[++Cn]=A[i];
		}
		std::sort(C+1,C+1+Cn),std::reverse(C+1,C+1+Cn),Cn=0;
		for(int i=1;i<=n;i++) if(!B[i]) A[i]=C[++Cn];
		for(int i=1;i<=n;i++) printf("%d ",A[i]);puts("");
		// Print();
	}
	return 0;
}