#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		
		long long int S = 1;
		int ans = 0;
		long long int sum = 0;
		for(int i=1;i<=31;i++)
		{
			S*=2;
			long long int d = (S-1)*S/2;
			sum += d;
			if(sum<=a) ans++;
			else break;
		}
		printf("%d\n",ans);
	}
}