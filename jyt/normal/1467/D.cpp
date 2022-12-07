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
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,Q,a,b,A[N],f[N][N],Sum[N],ans;
int cal(int x) {x-=x<mod?0:mod;return x;}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),f[i][0]=1;
	for(int i=0;i<m;i++)
		for(int j=1;j<=n;j++) if(f[j][i])
			f[j+1][i+1]=cal(f[j+1][i+1]+f[j][i]),f[j-1][i+1]=cal(f[j-1][i+1]+f[j][i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) Sum[i]=(Sum[i]+(ll)f[i][j]*f[i][m-j])%mod;
		ans=(ans+(ll)A[i]*Sum[i])%mod;
	}
	for(;Q--;)
	{
		scanf("%d%d",&a,&b);
		ans=(ans+(ll)(b-A[a]+mod)*Sum[a])%mod,A[a]=b;
		printf("%d\n",ans);
	}
	return 0;
}