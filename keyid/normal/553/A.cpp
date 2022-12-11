#include <cstdio>

typedef long long LL;

const int MAX=1005,MOD=1000000007;

int c[MAX],C[MAX][MAX];

void preprocess(int n)
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
}

int main()
{
	preprocess(1000);
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++) scanf("%d",&c[i]);
	int ans=1,sum=c[0];
	for (int i=1;i<k;i++)
	{
		sum+=c[i];
		ans=(LL)ans*C[sum-1][c[i]-1]%MOD;
	}
	printf("%d",ans);
	return 0;
}