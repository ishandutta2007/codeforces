#include <stdio.h>

int x[110],check[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	check[1] = 1;
	int count = x[1];
	int c = 1;
	for(int i=2;i<=a;i++)
	{
		if(2*x[i]<=x[1])
		{
			c++;
			check[i] =1;
			count += x[i];
		}
	}
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += x[i];
	if(2*count>sum)
	{
		printf("%d\n",c);
		for(int i=1;i<=a;i++) if(check[i]==1) printf("%d ",i);
	}
	else printf("0");
}