#include <stdio.h>

int x[200010];
int main()
{
	int Case;
	scanf("%d",&Case);
	for(int T=1;T<=Case;T++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		b++;
		
		long long int min = 0, max = 1234567890;
		long long int ans = 1000000000;
		
		while(min<=max)
		{
			long long int h = (min+max)/2;
			
			int s = 0;
			int r = 0;
			long long int t = 0;
			for(int i=1;i<=a;i++)
			{
				while(1)
				{
					if(r==a || x[r+1]-x[i]>2*h)
					{
						if(s<(r-i+1))
						{
							s = (r-i+1);
							t = x[i]+h;
						}
						break;
					}
					else r++;
				}
			}
			
			if(s>=b)
			{
				ans = t;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%lld\n",ans);
		
	}
}