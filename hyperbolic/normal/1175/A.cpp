#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		long long int b,c;
		scanf("%lld%lld",&b,&c);
		
		long long int ans = 0;
		while(b)
		{
			ans += b%c;
			if(b>=c)
			{
				ans++;
				b/=c;
			}
			else break;
		}
		printf("%lld\n",ans);
	}
}