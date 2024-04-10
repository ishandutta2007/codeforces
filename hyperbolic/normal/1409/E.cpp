#include <stdio.h>
#include <algorithm>
int x[200010],y[200010];
int check1[200010],check2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		for(int i=1;i<=a;i++)
		{
			int min = 1, max = i-1;
			int ans = i;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(x[i]-x[h]<=b)
				{
					ans = h;
					max = h-1;
				}
				else min = h+1;
			}
			check1[i] = i-ans+1;
		}
		
		for(int i=a;i>=1;i--)
		{
			int min = i+1, max = a;
			int ans = i;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(x[h]-x[i]<=b)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
			check2[i] = ans-i+1;
		}
		
		check1[0] = 0;
		check2[a+1] = 0;
		for(int i=1;i<=a;i++) check1[i] = check1[i]>check1[i-1]?check1[i]:check1[i-1];
		for(int i=a;i>=1;i--) check2[i] = check2[i]>check2[i+1]?check2[i]:check2[i+1];
		
		int ans = 0;
		for(int i=0;i<=a;i++)
		{
			int s = check1[i]+check2[i+1];
			ans = ans>s?ans:s;
		}
		printf("%d\n",ans);
	}
}