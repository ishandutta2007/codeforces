#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>b)
		{
			if(b<d)
			{
				printf("No\n");
				continue;
			}
			else
			{
				if((a+b-d)<c)
				{
					printf("No\n");
					continue;
				}
				else
				{
					printf("Yes\n");
					continue;
				}
			}
		}
		else
		{
			if(a<d)
			{
				printf("No\n");
				continue;
			}
			else
			{
				if((a+b-d)<c)
				{
					printf("No\n");
					continue;
				}
				else
				{
					printf("Yes\n");
					continue;
				}
			}
		}
		
	}
}