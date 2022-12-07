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
#define N 705
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,f[N][N][9][2],ans;char A[N];
int cal(int x) {x-=x<mod?0:mod;return x;}
int main()
{
	scanf("%s",A+1),n=strlen(A+1);
	for(int i=0;i<9;i++) f[0][0][i][1]=1;
	for(int i=0,nj,nl;i<n;i++)
		for(int j=0;j<=i;j++)
			for(int k=0;k<9;k++)
				for(int l=0;l<2;l++) if(f[i][j][k][l])
					for(int s=0;s<=(l?A[i+1]-48:9);s++)
						nj=j+(s>k),nl=l&(s==A[i+1]-48),f[i+1][nj][k][nl]=cal(f[i+1][nj][k][nl]+f[i][j][k][l]);
	for(int i=1,v=1;i<=n;v=(10ll*v+1)%mod,i++)
		for(int j=0;j<9;j++) ans=(ans+(ll)(f[n][i][j][0]+f[n][i][j][1])*v)%mod;
	printf("%d\n",ans);
	return 0;
}