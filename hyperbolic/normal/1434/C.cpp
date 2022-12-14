#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a>b*c) printf("-1\n");
		else if(d>=c) printf("%lld\n",a);
		else
		{
			long long int t = a%(d*b);
			long long int s = (a-t)/(d*b);
			//printf("%lld %lld??\n",s,t);
			long long int ans = (s*(s+1)/2)*d*b+(s+1)*t;
			printf("%lld\n",ans);
		}
	}
}