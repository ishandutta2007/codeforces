#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int min = 0, max = 100000000;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(a<h||b<h) max = h-1;
			else
			{
				if((a-h)+(b-h)+c>=h)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
		}
		printf("%d\n",ans);
	}
}