#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=2;;i++)
		{
			int b = (1<<i) - 1;
			if(a%b==0)
			{
				printf("%d\n",a/b);
				break;
			}
		}
	}
}