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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],mark[N][N],Sum[N],Max,f[N],ans;
void clear()
{
	ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) mark[i][j]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]);
		for(int i=1;i<=n;i++)
		{
			Max=0,mark[i][i-1]=1;
			for(int j=i;j<=n;j++)
			{
				Sum[A[j]]++,Max=max(Max,Sum[A[j]]);
				if((j-i&1)&&j-i+1-Max>=Max) mark[i][j]=1;
			}
			for(int j=i;j<=n;j++) Sum[A[j]]=0;
		}
		for(int i=1;i<=n;i++)
		{
			f[i]=mark[1][i-1]?1:-inf;
			for(int j=1;j<i;j++)
				if(A[i]==A[j]&&mark[j+1][i-1]) f[i]=max(f[i],f[j]+1);
			if(mark[i+1][n]||i==n) ans=max(ans,f[i]);
			// dbg1(i),dbg1(f[i]),dbg2(ans);
		}
		printf("%d\n",ans);
		// dbg2(ans);
	}
	return 0;
}