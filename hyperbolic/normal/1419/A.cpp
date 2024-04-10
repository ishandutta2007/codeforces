#include <stdio.h>

char x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		if(a%2==1)
		{
			for(int i=1;i<=a;i+=2)
			{
				if((x[i]-'0')%2==1)
				{
					printf("1\n");
					goto u;
				}
			}
			printf("2\n");
			u:;
		}
		else
		{
			for(int i=2;i<=a;i+=2)
			{
				if((x[i]-'0')%2==0)
				{
					printf("2\n");
					goto v;
				}
			}
			printf("1\n");
			v:;
		}
	}
}