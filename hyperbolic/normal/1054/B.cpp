#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	if(x[1]>=1)
	{
		printf("1");
		return 0;
	}
	
	int max = x[1];
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=max+2)
		{
			printf("%d",i);
			return 0;
		}
		max = max>x[i]?max:x[i];
	}
	printf("-1");
}