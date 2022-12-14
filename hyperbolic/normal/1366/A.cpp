#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans = 0;
		int min = 0, max = 1000000000;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(h>a || h>b)
			{
				max = h-1;
				continue;
			}
			int d = a-h;
			int c = b-h;
			if(c+d>=h)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d\n",ans);
	}
}