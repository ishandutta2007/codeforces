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
#define N 50
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,L,R,E[N][N];
int main()
{
	scanf("%d%d",&L,&R),n=21;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) E[i][j]=i>1?1<<i-2:1;
	n++,E[n][n+1]=L-1,R-=L-1;
	for(int i=0;i<20;i++) if(R-1>>i&1) R-=1<<i,E[i+2][n]=R,dbg1(i),dbg1(n),dbg2(R);
	E[1][n]=1;
	if(L>1) n++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) m+=E[i][j]>0;
	printf("YES\n%d %d\n",n,m);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) if(E[i][j]) printf("%d %d %d\n",i,j,E[i][j]);
	return 0;
}