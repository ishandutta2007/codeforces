#include<cstdio>

long long a[1000][1000];

int main()
{
	long long xs,ys,sum,t;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	xs=ys=sum=0;
	for(i=0;i<n;i++)for(j=0;j<m;j++)
	{
		scanf("%I64d",&a[i][j]);
		sum+=a[i][j];
        xs+=(2*i+1)*a[i][j];
        ys+=(2*j+1)*a[i][j];
	}
	if(sum==0)printf("0\n0 0\n");
	else
	{
		xs=(xs+sum-1)/sum/2;
		ys=(ys+sum-1)/sum/2;
		sum=0;
		for(i=0;i<n;i++)for(j=0;j<m;j++)sum+=4*a[i][j]*(((2*i+1)-2*xs)*((2*i+1)-2*xs)+((2*j+1)-2*ys)*((2*j+1)-2*ys));
		printf("%I64d\n%I64d %I64d\n",sum,xs,ys);
	}
}