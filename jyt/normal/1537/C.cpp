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
int T,n,A[N],Min,ans,id;
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		std::sort(A+1,A+1+n);
		Min=abs(A[2]-A[1]);
		for(int i=1;i<n;i++) Min=min(Min,abs(A[i]-A[i+1]));
		if(A[n]-A[1]==Min)
		{
			for(int i=1;i<=n;i++) printf("%d ",A[i]);puts("");
		}
		else
		{
			for(int i=1;i<n;i++)
				if(abs(A[i]-A[i+1])==Min)
				{
					for(int j=i+1;j<=n;j++) printf("%d ",A[j]);
					for(int j=1;j<=i;j++) printf("%d ",A[j]);
					puts("");
					break;
				}
		}
	}
	return 0;
}