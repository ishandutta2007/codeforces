#include<cstdio>

long long a[100];
long long d[100][100][2];

int main()
{
	long long n,t,r,x;
	long long i,j,m;
	scanf("%I64d%I64d",&n,&t);
	n++;
    for(x=1;x<t;x<<=1);
    if(x!=t)puts("0");
    else
	{
		for(i=0;i<60;i++)a[59-i]=(n>>i)&1;
		for(j=0;t>>j;j++);
		m=j;
        d[0][0][1]=1;
        for(i=0;i<60;i++)for(j=0;j<=m;j++)
		{
			if(a[i+1])
			{
				d[i+1][j][0]+=d[i][j][1];
				d[i+1][j+1][1]+=d[i][j][1];
                d[i+1][j][0]+=d[i][j][0];
                d[i+1][j+1][0]+=d[i][j][0];
			}
			else
			{
				d[i+1][j][1]+=d[i][j][1];
                d[i+1][j][0]+=d[i][j][0];
                d[i+1][j+1][0]+=d[i][j][0];
			}
		}
		printf("%I64d",d[59][m][0]+d[59][m][1]-(m==1));
	}
}