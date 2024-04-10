#include<cstdio>

int a[501];
int d[501][501];

int main()
{
	int i,j,k,n,m,l,mod;
	scanf("%d%d%d%d",&n,&m,&l,&mod);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
    d[0][0]=1;
    for(i=1;i<=n;i++)
	{
		for(j=0;j<m;j++)for(k=0;k+a[i]<=l;k++)(d[j+1][k+a[i]]+=d[j][k])%=mod;
	}
	i=0;
	for(k=0;k<=l;k++)(i+=d[m][k])%=mod;
	printf("%d",i);
}