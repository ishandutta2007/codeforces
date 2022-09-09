#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ull;

int n=0,m=0;int sz[5000];

const ull INF=1e18;
ull a[5000];ull dp[4001][4001];

int Solve(int l,int r)
{
	if(l>r)return 0;
	int p=l;for(int x=l+1;x<=r;x++)if(a[x]<a[p])p=x;
	int L=Solve(l,p-1),R=Solve(p+1,r);
	sz[p]=sz[L]+sz[R]+1;
	for(int i=0;i<=sz[L];i++)
	{
		for(int j=0;j<=sz[R];j++)
		{
			dp[p][i+j]=max(dp[p][i+j],dp[L][i]+dp[R][j]-a[p]*i*j*2);
			dp[p][i+j+1]=max(dp[p][i+j+1],dp[L][i]+dp[R][j]+m*a[p]-a[p]*(2*(i+1)*(j+1)-1));
		}
	}
	return p;
}

int main()
{
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)scanf("%llu",&a[i]);
	//for(int j=1;j<=n;j++)for(int i=1;i<=n;i++)dp[j][i]=-INF;
	int r=Solve(1,n);printf("%lld",dp[r][m]);
}