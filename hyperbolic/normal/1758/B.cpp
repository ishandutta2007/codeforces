#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==1)
		{
			for(int i=1;i<=a;i++) printf("1 ");
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a-2;i++) printf("2 ");
			printf("1 3\n");
		}
	}
}