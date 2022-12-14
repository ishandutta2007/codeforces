#include <stdio.h>
#include <algorithm>
int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int min = 1, max = (a/2);
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=1;i<=h;i++)
		{
			if(x[a-h+i]-x[i]<b)
			{
				max = h-1;
				goto u;
			}
		}
		ans = h;
		min = h+1;
		u:;
	}
	printf("%d",ans);
}