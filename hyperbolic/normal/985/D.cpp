#include <stdio.h>

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	
	long long int ans = a;
	long long int min = 1, max = (long long int)2e9;
	//printf("%lld %lld!!\n",min,max);
	while(min<=max)
	{
		long long int h = (min+max)/2;
		if(h<=b)
		{
			long long int s = h*(h+1)/2;
			if(s>=a)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		else
		{
			long long int s = b*(b+1)/2;
			if(s>=a)
			{
				ans = h;
				max = h-1;
			}
			else
			{
				long long int last = a - b*(b+1)/2;
				if((h-b)%2==0)
				{
					long long int k = (h-b)/2;
					long long int t = b + (b+k) + (2*b+k)*(k-1);
					if(t>=last)
					{
						ans = h;
						max = h-1;
					}
					else min = h+1;
				}
				else
				{
					long long int k = (h-b-1)/2;
					long long int t = b + (2*b+k+1)*(k);
					if(t>=last)
					{
						ans = h;
						max = h-1;
					}
					else min = h+1;
				}
			}
		}
	}
	printf("%lld",ans);
}