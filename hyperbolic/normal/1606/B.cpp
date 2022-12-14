#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		
		long long int s = 1;
		long long int t = 1;
		long long int count = 0;
		while(s<a)
		{
			if(t==b)
			{
				long long int k = (a-s)/b;
				count += k;
				s += k*b;
				
				if(s==a) break;
			}
			s += t;
			t = s<b?s:b;
			count++;
		}
		
		printf("%lld\n",count);
	}
}