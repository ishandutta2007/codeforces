#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+b+1);
		
		int max = abs(c-d)-1;
		int min = 1;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(h>b)
			{
				max = h-1;
				continue;
			}
			
			if(c<d)
			{
				for(int i=h;i>=1;i--)
				{
					if(x[i]>=d-(h-i+1))
					{
						max = h-1;
						goto u;
					}
				}
			}
			else
			{
				for(int i=h;i>=1;i--)
				{
					if(x[i]>=a-d-(h-i))
					{
						max = h-1;
						goto u;
					}
				}
			}
			ans = h;
			min = h+1;
			u:;
		}
		printf("%d\n",ans);
	}
}