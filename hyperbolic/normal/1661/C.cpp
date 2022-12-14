#include <stdio.h>
#include <algorithm>
#define MAX (long long int)1e16

int x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int limit;
		long long int min,max;
		long long int ans = MAX;
		
		limit = x[a];
		min = 0, max = MAX;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int S2 = (h+1)/2, S1 = h/2;
			for(int i=1;i<=a;i++)
			{
				int t1 = limit-x[i];
				int t2 = (S1<t1/2?S1:t1/2);
				t1 -= 2*t2, S1 -= t2;
				S2 -= t1;
			}
			
			if(S2<0) min = h+1;
			else
			{
				ans = ans<h?ans:h;
				max = h-1;
			}
		}
		
		limit = x[a]+1;
		min = 0, max = MAX;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int S2 = (h+1)/2, S1 = h/2;
			for(int i=1;i<=a;i++)
			{
				int t1 = limit-x[i];
				int t2 = (S1<t1/2?S1:t1/2);
				t1 -= 2*t2, S1 -= t2;
				S2 -= t1;
			}
			
			if(S2<0) min = h+1;
			else
			{
				ans = ans<h?ans:h;
				max = h-1;
			}
		}
		
		printf("%lld\n",ans);
	}
}