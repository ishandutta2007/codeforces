#include<cstdio>

int main()
{
	int i,n,k;
	scanf("%d%d",&n,&k);
	if(n*(n-1)/2<=k)puts("no solution");
	else
	{
		for(i=0;i<n;i++)
			printf("0 %d\n",i);
	}
}