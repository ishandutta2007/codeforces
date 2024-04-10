#include <stdio.h>
#include <algorithm>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		std::reverse(x+1,x+a+1);
		
		for(int i=1;i<=a;i++) x[i] += x[i-1];
		
		while(b--)
		{
			int c;
			scanf("%d",&c);
			int ans = -1;
			int min = 1, max = a;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(x[h]>=c)
				{
					ans = h;
					max = h-1;
				}
				else min = h+1;
			}
			printf("%d\n",ans);
		}
	}
}