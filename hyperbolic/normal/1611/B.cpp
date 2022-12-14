#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int min = 0, max = 1000000000;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(a>=h && b>=h && (a-h)+(b-h)>=2*h)
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d\n",ans);
	}
}