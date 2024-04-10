#include <stdio.h>

int main()
{
	// x y => gx+y/bx => gx+y>=n/2 , gx+y+bx>=n
	// x z =>
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		long long int min = 1, max = 2;
		for(int i=1;i<=18;i++) max*=10;
		long long int ans = max;
		
		while(min<=max)
		{
			long long int h = (min+max)/2;
			long long int s = h/(b+c);
			long long int t = h - s*(b+c);
			
			long long int x1, y1;
			if(t<=b) x1 = s*b + t, y1 = s*c;
			else x1 = s*b+b, y1 = s*c+(t-b);
			if(x1>=(a+1)/2 && (x1+y1)>=a)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%lld\n",ans);
	}
}