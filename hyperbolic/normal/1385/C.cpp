#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int min = 0, max = a;
		int ans = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			int L = a, R = h+1;
			for(int i=h+1;i<a;i++)
			{
				if(x[i]>x[i+1])
				{
					L = i;
					break;
				}
			}
			for(int i=a;i>h+1;i--)
			{
				if(x[i-1]<x[i])
				{
					R = i;
					break;
				}
			}
			
			if(L>=R)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d\n",ans);
	}
}