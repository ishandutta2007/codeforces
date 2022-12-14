#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int max = 0;
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=max)
			{
				printf("1\n");
				goto u;
			}
		}
		printf("%d\n",a);
		u:;
	}
}