#include<cstdio>

int a[101];
int d[102][102];
int x[100];
int y[100];
int v[102];
int n;

int find(int x)
{
	if(x==n+1)return 1;
	if(v[x])return 0;
	int i;
	v[x]=1;
	for(i=1;i<=n+1;i++)if(d[x][i]&&find(i))
	{
        d[x][i]--;
        d[i][x]++;
        return 1;
	}
    return 0;
}

int main()
{
	int i,j,k,m,r=0,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]&1)
		{
			j=x[i];
			x[i]=y[i];
			y[i]=j;
		}
	}
    for(i=2;i<=40000;i++)
	{
		for(j=0;j<=n+1;j++)for(k=0;k<=n+1;k++)d[j][k]=0;
        for(j=1;j<=n;j++)
		{
			while(a[j]%i==0)
			{
				a[j]/=i;
                if(j&1)d[0][j]++;
                else d[j][n+1]++;
			}
		}
		for(j=0;j<m;j++)d[x[j]][y[j]]=100;
		for(j=0;j<=n+1;j++)v[j]=0;
		while(find(0))
		{
			r++;
			for(j=0;j<=n+1;j++)v[j]=0;
		}
	}
    for(i=1;i<=n;i++)if(a[i]>1)
	{
		t=a[i];
		for(j=0;j<=n+1;j++)for(k=0;k<=n+1;k++)d[j][k]=0;
        for(j=1;j<=n;j++)
		{
			while(a[j]%t==0)
			{
				a[j]/=t;
                if(j&1)d[0][j]++;
                else d[j][n+1]++;
			}
		}
		for(j=0;j<m;j++)d[x[j]][y[j]]=100;
		for(j=0;j<=n+1;j++)v[j]=0;
		while(find(0))
		{
			r++;
			for(j=0;j<=n+1;j++)v[j]=0;
		}
	}
	printf("%d",r);
}