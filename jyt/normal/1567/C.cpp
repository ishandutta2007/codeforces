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
#define N 15
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N],An;ll f[N][2][2],ans;
void clear()
{
	for(int i=1;i<=An;i++)
		for(int j=0;j<2;j++) f[i][j][0]=f[i][j][1]=0;
	ans=An=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int x=n;x;x/=10) A[++An]=x%10;
		f[0][0][0]=1;
		for(int i=0;i<An;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++) if(f[i][j][k])
				{
					// dbg1(i),dbg1(j),dbg1(k),dbg2(f[i][j][k]);
					for(int l=0;l<=9;l++)
					{
						if(A[i+1]<l+k) f[i+1][1][j]+=f[i][j][k];
						else f[i+1][0][j]+=f[i][j][k];
					}
				}
		printf("%lld\n",f[An][0][0]-2);
	}
	return 0;
}