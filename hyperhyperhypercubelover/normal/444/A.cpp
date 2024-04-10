#include<cstdio>

int a[501];

int main()
{
	double max=0;
	int s,e,x;
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&s,&e,&x);
        if(1.*(a[s]+a[e])/x>max)max=1.*(a[s]+a[e])/x;
	}
	printf("%.12lf",max);
}