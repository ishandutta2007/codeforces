#include <stdio.h>

char x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		for(int i=1;i<a;i++)
		{
			if(x[i]==x[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=1;i+2<=a;i++)
		{
			if(x[i]==x[i+2])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}