#include <stdio.h>
#include <algorithm>

int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int min = 1, max = a;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		if(a-h<=h)
		{
			max = h-1;
			continue;
		}
		
		for(int i=h;i>=1;i--)
		{
			if(x[a+i-h]<=x[i])
			{
				max = h-1;
				goto u;
			}
		}
		if(x[a-h]<=x[1]) max = h-1;
		else
		{
			min = h+1;
			ans = h;
		}
		
		u:;
	}
	
	if(ans==0)
	{
		printf("0\n");
		for(int i=1;i<=a;i++) printf("%d ",x[i]);
		return 0;
	}
	else
	{
		printf("%d\n",ans);
		for(int i=1;i<=ans;i++) y[2*i] = x[i];
		for(int i=0;i<=ans;i++) y[2*i+1] = x[a-ans+i];
		for(int i=2*ans+2;i<=a;i++) y[i] = x[i-ans-1];
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
	}
}