#include<cstdio>
#include<algorithm>

double a[100];

int main()
{
	double max=0,now=1;
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%Lf",&a[i]);
	std::sort(a,a+n);
	for(i=n-1;i>=0;i--)if(max*(1-a[i])+now*a[i]>max)
	{
		max=max*(1-a[i])+now*a[i];
		now*=1-a[i];
	}
	printf("%.10lf",max);
}