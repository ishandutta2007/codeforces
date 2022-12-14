#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(b%2==0)
		{
			for(int j=1;j<=(b/2);j++) printf("1");
			printf("\n");
		}
		else
		{
			printf("7");
			for(int j=1;j<=((b-3)/2);j++) printf("1");
			printf("\n");
		}
	}
}