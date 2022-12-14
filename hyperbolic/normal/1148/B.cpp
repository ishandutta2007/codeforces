#include <stdio.h>
#include <algorithm>

int x[200010],y[200010];
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	std::sort(x+1,x+a+1);
	std::sort(y+1,y+b+1);
	
	if(e>=a)
	{
		printf("-1");
		return 0;
	}
	
	
	int S = 0;
	int pivot = 1;
	for(int i=1;i<=a;i++)
	{
		if((i-1)>e) break;
		
		int min = 1, max = b;
		int ans = b+1;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(y[h]>=x[i]+c)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		if(b-ans+1<=e-(i-1))
		{
			printf("-1");
			return 0;
		}
		else S = S>y[ans+(e-(i-1))]?S:y[ans+(e-(i-1))];
	}
	printf("%d",S+d);
}