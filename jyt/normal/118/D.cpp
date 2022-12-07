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
#define mod 100000000
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,a,b,f[N][N][2],ans;
int cal(int x) {x-=x<mod?0:mod;return x;}
int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b),f[0][0][0]=f[0][0][1]=1;
	for(int i=0;i<=n;i++)
		for(int j=i?0:1;j<=m;j++)
		{
			for(int k=1;k<=min(a,i);k++)
				f[i][j][0]=cal(f[i][j][0]+f[i-k][j][1]);
			for(int k=1;k<=min(b,j);k++)
				f[i][j][1]=cal(f[i][j][1]+f[i][j-k][0]);
		}
	printf("%d\n",cal(f[n][m][0]+f[n][m][1]));
	return 0;
}