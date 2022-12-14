#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = 0;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		sum += (86400-c);
		if(sum>=b)
		{
			printf("%d",i);
			return 0;
		}
	}
}