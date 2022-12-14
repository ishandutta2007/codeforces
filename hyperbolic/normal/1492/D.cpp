#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(c==0)
	{
		printf("Yes\n");
		for(int i=1;i<=b;i++) printf("1");
		for(int i=1;i<=a;i++) printf("0");
		printf("\n");
		for(int i=1;i<=b;i++) printf("1");
		for(int i=1;i<=a;i++) printf("0");
		printf("\n");
	}
	else
	{
		if(a==0) printf("No");
		else if(b==1) printf("No");
		else
		{
			if(c>a+b-2) printf("No");
			else
			{
				printf("Yes\n");
				if(c<=a)
				{
					for(int i=1;i<=b-1;i++) printf("1");
					for(int i=1;i<=a-c;i++) printf("0");
					printf("1");
					for(int i=1;i<=c;i++) printf("0");
					printf("\n");
					
					for(int i=1;i<=b-1;i++) printf("1");
					for(int i=1;i<=a;i++) printf("0");
					printf("1");
					printf("\n");
				}
				else
				{
					for(int i=1;i<=(a+b-2)-c;i++) printf("1");
					printf("11");
					for(int i=1;i<=a-1;i++) printf("0");
					for(int i=1;i<=b - ((a+b-2)-c) - 2;i++) printf("1");
					printf("0\n");
					
					for(int i=1;i<=(a+b-2)-c;i++) printf("1");
					printf("10");
					for(int i=1;i<=a-1;i++) printf("0");
					for(int i=1;i<=b - ((a+b-2)-c) - 2;i++) printf("1");
					printf("1\n");
				}
			}
		}
	}
}