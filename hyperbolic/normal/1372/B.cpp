#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				printf("%d %d\n",a/i,a-(a/i));
				goto u;
			}
		}
		printf("1 %d\n",a-1);
		u:;
	}
}