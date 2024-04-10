#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) printf("()");
		printf("\n");
		
		for(int i=1;i<a;i++)
		{
			for(int j=1;j<i;j++) printf("()");
			printf("(())");
			for(int j=i+2;j<=a;j++) printf("()");
			printf("\n");
		}
	}
}