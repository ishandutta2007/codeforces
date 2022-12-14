#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%3==1)
		{
			printf("1");
			a--;
		}
		while(a>0)
		{
			printf("2");
			a-=2;
			if(a==0) break;
			printf("1");
			a--;
			if(a==0) break;
		}
		printf("\n");
	}
}