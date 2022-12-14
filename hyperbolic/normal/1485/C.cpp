#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int p = 0,start = 0;
		long long int ans = 0;
		for(int i=1;i<=b;i++)
		{
			int t = a/(i+1);
			if(t>i-1) ans += (i-1);
			else
			{
				start = i;
				p = t;
				break;
			}
		}
		for(int i=p;i>=1;i--)
		{
			long long int L = a/(i+1)-1;
			long long int R = a/(i)-1;
			if(L>b) break;
			if(L<start) L = start-1;
			if(R>b) R = b;
			ans += (R-L)*i;
		}
		printf("%lld\n",ans);
	}
}