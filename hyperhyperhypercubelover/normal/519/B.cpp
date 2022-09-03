#include<cstdio>

int main()
{
	int j,k;
	int i,n,t;
	scanf("%d",&n);
	j=k=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		j^=t;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d",&t);
		j^=t;
		k^=t;
	}
	for(i=2;i<n;i++)
	{
		scanf("%d",&t);
		k^=t;
	}
	printf("%d\n%d\n",j,k);
}