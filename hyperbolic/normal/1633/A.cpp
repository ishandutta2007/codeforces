#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%7==0) printf("%d\n",a);
		else
		{
			for(int i=1;i<=9;i++)
			{
				int b = (a/10)*10+i;
				if(b%7==0)
				{
					printf("%d\n",b);
					goto u;
				}
			}
		}
		u:;
	}
}