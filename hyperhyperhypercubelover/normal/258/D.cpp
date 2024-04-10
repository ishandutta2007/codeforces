#include<cstdio>

int a[1001];
double d[1001][1001];
double t[1001][1001];

int main()
{
	double res=0;
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++)for(j=i+1;j<=n;j++)if(a[i]>a[j])d[i][j]=1;
    while(m--)
	{
        scanf("%d%d",&i,&j);
        if(i>j)i^=j^=i^=j;
        for(k=1;k<i;k++)
		{
			t[k][i]=(d[k][i]+d[k][j])/2;
			t[k][j]=(d[k][i]+d[k][j])/2;
		}
        for(k=i+1;k<j;k++)
		{
			t[i][k]=(d[i][k]+1-d[k][j])/2;
            t[k][j]=(d[k][j]+1-d[i][k])/2;
		}
        for(k=j+1;k<=n;k++)
		{
			t[i][k]=(d[i][k]+d[j][k])/2;
			t[j][k]=(d[i][k]+d[j][k])/2;
		}
		t[i][j]=1/2.;
        for(k=1;k<=n;k++)
		{
			d[k][i]=t[k][i];
			d[i][k]=t[i][k];
            d[k][j]=t[k][j];
            d[j][k]=t[j][k];
		}
	}
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)res+=d[i][j];
	printf("%.10lf",res);
}