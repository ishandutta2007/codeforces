#include <stdio.h>
#define MAX (long long int)2e9

long long int x[200010],y[200010];
int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(x[i]>=b)
		{
			printf("0");
			return 0;
		}
	}
	
	int start = -1;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=0)
		{
			start = i;
			break;
		}
	}
	
	if(start==a-1)
	{
		long long int t = (b-x[a])/x[start];
		if(t*x[start]+x[a]>=b) printf("%lld",t);
		else printf("%lld",t+1);
	}
	else if(start==a-2)
	{
		long long int min = 1, max = MAX;
		long long int ans = MAX;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int t = b-(x[a]+x[a-1]*h);
			if(t<=0)
			{
				ans = h;
				max = h-1;
			}
			else
			{
				long long int t2 = (h+1)*h/2;
				if(x[a-2]>=(t/t2)+1)
				{
					ans = h;
					max = h-1;
				}
				else
				{
					if(x[a-2]*t2>=t)
					{
						ans = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
		}
		printf("%lld",ans);
	}
	else
	{
		int count = 0;
		while(1)
		{
			count++;
			for(int i=start;i<=a;i++) y[i] = y[i-1] + x[i];
			for(int i=start;i<=a;i++)
			{
				if(y[i]>=b)
				{
					printf("%d",count);
					return 0;
				}
			}
			for(int i=start;i<=a;i++) x[i] = y[i];
		}
	}
}