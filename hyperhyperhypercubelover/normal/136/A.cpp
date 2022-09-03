#include<cstdio>

int a[111];

int main()
{
	int i,n,t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
		a[t]=i;
	}
	for(i=1;i<=n;i++)printf("%d ",a[i]);
}