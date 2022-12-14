#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=0;i<=32;i++)
	{
		if((1<<i)>a)
		{
			printf("%d",i);
			return 0;
		}
	}
}