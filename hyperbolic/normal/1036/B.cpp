#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a>c || b>c) printf("-1\n");
		else
		{
			long long int ans = c;
			if((a+c)%2==1) ans--;
			if((b+c)%2==1) ans--;
			printf("%lld\n",ans);
		}
	}
}