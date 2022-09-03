#include<cstdio>

long long d[36][36];
long long r;

int main()
{
    int i,j,k,l,n,m;
    scanf("%d%d",&n,&m);
    d[0][0]=1;
    d[1][1]=1;
    for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=0;k<i;k++)
			{
                for(l=0;l<j;l++)d[i][j]+=d[k][j-1]*d[i-k-1][l];
                for(l=0;l<j;l++)d[i][j]+=d[i-k-1][j-1]*d[k][l];
				d[i][j]-=d[i-k-1][j-1]*d[k][j-1];
			}
		}
	}
	for(j=m;j<=n;j++)r+=d[n][j];
	printf("%I64d",r);
}