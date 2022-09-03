#include<cstdio>

int a[5][1001];
int p[5][1001];
int d[1001];

int main()
{
	int i,j,k,n,m,res=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<n;i++)for(j=1;j<=m;j++)
	{
		scanf("%d",&a[i][j]);
        p[i][a[i][j]]=j;
	}
    for(i=1;i<=m;i++)
	{
        for(j=1;j<i;j++)
		{
			for(k=1;k<n;k++)if(p[k][a[0][j]]>p[k][a[0][i]])break;
            if(k==n&&d[j]>d[i])d[i]=d[j];
		}
		d[i]++;
		if(d[i]>res)res=d[i];
	}
	printf("%d",res);
}