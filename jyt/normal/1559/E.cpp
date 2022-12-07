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
#define mod 998244353
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,A[N],B[N],f[55][N],g[N];
int cal(int x) {x-=x<mod?0:mod;return x;}
int Solve(int x)
{
	int K=m/x,a,b;
	for(int i=1;i<=n;i++) K-=(A[i]-1)/x+1;
	for(int i=0;i<=K;i++) f[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		a=(A[i]-1)/x+1,b=B[i]/x;
		if(a>b) return 0;
		for(int j=0;j<=K;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>b-a) f[i][j]=cal(f[i][j]-f[i-1][j-b+a-1]+mod);
			if(j) f[i][j]=cal(f[i][j]+f[i][j-1]);
		}
	}
	return f[n][K];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&A[i],&B[i]);
	for(int i=1;i<=m;i++) g[i]=Solve(i);
	for(int i=m;i;i--)
		for(int j=i+i;j<=m;j+=i) g[i]=cal(g[i]-g[j]+mod);
	printf("%d\n",g[1]);
	return 0;
}