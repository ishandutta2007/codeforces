#include<cstdio>

int main()
{
	int i,n,a,max=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a>max)max=a;
	}
	printf("%d",max);
}