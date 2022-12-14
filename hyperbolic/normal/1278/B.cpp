#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		if(b<c)
		{
			long long int t = b;
			b = c;
			c = t;
		}
		
		long long int ans = 12345678;
		long long int min = 0, max = 12345678;
		while(min<=max)
		{
			long long int h = (min+max)/2;
			if(h*(h+1)/2>=b-c)
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		while(((b-c)+ans*(ans+1)/2)%2==1) ans++;
		printf("%lld\n",ans);
	}
}