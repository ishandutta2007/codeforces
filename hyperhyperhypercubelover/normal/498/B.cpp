#include<cstdio>
#include<cmath>

double d[5002][5002];
double x[5002];
double t[5002];
int y[5002];

int main()
{
	double r=0,tt;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
	{
        scanf("%lf%d",&x[i],&y[i]);
        x[i]/=100;
	}
	x[n]=0;
	y[n]=10000;
    d[0][0]=1;
    for(i=0;i<=n;i++)
	{
		tt=pow(1-x[i],y[i]);
		for(j=0;j<=m;j++)t[j]=d[i][j];
		for(j=0;j<=m;j++)
		{
			d[i][j+1]+=d[i][j]*(1-x[i]);
			d[i+1][j+1]+=d[i][j]*x[i];
			if(j+y[i]<=m)
			{
				d[i][j+y[i]]-=t[j]*tt;
                d[i+1][j+y[i]]+=t[j]*tt;
			}
		}
	}
    for(i=0;i<n;i++)r+=d[i][m]*i;
    r+=d[n][m]*n;
    printf("%.10lf",r);
}