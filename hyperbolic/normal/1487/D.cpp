#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int min = 1, max = 12345678;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(((long long int)(2*h+1)*(2*h+1)+1)/2<=a)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d\n",ans);
	}
}