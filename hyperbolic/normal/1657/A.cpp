#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
		{
			printf("0\n");
			continue;
		}
		
		int c = a*a+b*b;
		for(int i=1;i<=100;i++)
		{
			if(i*i==c)
			{
				printf("1\n");
				goto u;
			}
		}
		printf("2\n");
		u:;
	}
}