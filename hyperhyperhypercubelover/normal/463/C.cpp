#include<cstdio>
#include<algorithm>

int a[2000][2000];
long long x[5000];
long long y[5000];

int main()
{
	int max1x,max1y,max2x,max2y;
    int i,j,n;
    long long max1=-1,max2=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)for(j=0;j<n;j++)
	{
		scanf("%d",&a[i][j]);
		x[i+j]+=a[i][j];
        y[n-i+j]+=a[i][j];
	}
	for(i=0;i<n;i++)for(j=0;j<n;j++)
	{
		if((i+j)&1)
		{
			if(max1<x[i+j]+y[n-i+j]-a[i][j])
			{
				max1=x[i+j]+y[n-i+j]-a[i][j];
				max1x=i+1;
				max1y=j+1;
			}
		}
		else
		{
			if(max2<x[i+j]+y[n-i+j]-a[i][j])
			{
				max2=x[i+j]+y[n-i+j]-a[i][j];
				max2x=i+1;
				max2y=j+1;
			}
		}
	}
	printf("%I64d\n%d %d %d %d",max1+max2,max1x,max1y,max2x,max2y);
}