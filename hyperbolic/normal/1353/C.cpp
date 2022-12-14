#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		long long int ans = 0;
		for(int i=1;;i++)
		{
			if(2*i+1>a) break;
			ans += (8*(long long int)i*i);
		}
		printf("%lld\n",ans);
	}
}