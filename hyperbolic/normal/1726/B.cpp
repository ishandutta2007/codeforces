#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1)
		{
			printf("YES\n");
			printf("%d\n",b);
			continue;
		}
		if(b<a)
		{
			printf("NO\n");
			continue;
		}
		b-=a;
		
		if(a%2==0)
		{
			if(b%2==1)
			{
				printf("NO\n");
				continue;
			}
			else
			{
				printf("YES\n");
				printf("%d %d ",b/2 + 1,b/2 + 1);
				for(int i=1;i<=a-2;i++) printf("1 ");
				printf("\n");
			}
		}
		else
		{
			printf("YES\n");
			printf("%d ",b+1);
			for(int i=1;i<=a-1;i++) printf("1 ");
			printf("\n");
		}
	}
}