#include<cstdio>

int a[300][300];
int d[600][300][300];

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
	for(j=0;j<n;j++)for(k=0;k<n;k++)d[0][j][k]=-2e9;
	d[0][0][0]=a[0][0];
	for(i=1;i<n+n-1;i++)for(j=0;j<n;j++)for(k=0;k<n;k++)
	{
		d[i][j][k]=-2e9;
		if(i-j<0||i-k<0||i-j>=n||i-k>=n)continue;
        if(d[i-1][j][k]>=d[i][j][k])d[i][j][k]=d[i-1][j][k];
        if(j>0&&d[i-1][j-1][k]>=d[i][j][k])d[i][j][k]=d[i-1][j-1][k];
        if(k>0&&d[i-1][j][k-1]>=d[i][j][k])d[i][j][k]=d[i-1][j][k-1];
        if(j>0&&k>0&&d[i-1][j-1][k-1]>=d[i][j][k])d[i][j][k]=d[i-1][j-1][k-1];
        if(j==k)d[i][j][k]+=a[j][i-j];
        else d[i][j][k]+=a[j][i-j]+a[k][i-k];
	}
	printf("%d",d[n+n-2][n-1][n-1]);
}