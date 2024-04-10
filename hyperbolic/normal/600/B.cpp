#include <stdio.h>
#include <algorithm>

int x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	std::sort(x+1,x+a+1);
	
	for(int i=1;i<=b;i++)
	{
		int min = 1, max = a;
		int ans = 0;
		while(min<=max)
		{
			int h = (min+max)/2;
			if(x[h]<=y[i])
			{
				ans = h;
				min = h+1;
			}
			else max = h-1;
		}
		printf("%d ",ans);
	}
}