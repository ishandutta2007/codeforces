#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int C = 1;
		for(;;)
		{
			if(2*C>a)
			{
				printf("%d\n",C-1);
				goto u;
			}
			C*=2;
		}
		u:;
	}
}