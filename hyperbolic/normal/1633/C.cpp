#include <stdio.h>

int func(long long int s1, long long int t1, long long int s2, long long int t2)
{
	long long int k1 = (s2-1)/t1;
	long long int k2 = (s1-1)/t2;
	long long int m = k1<k2?k1:k2;
	s1 -= m*t2, s2 -= m*t1;
	
	while(1)
	{
		s2 -= t1;
		if(s2<=0) return 1;
		s1 -= t2;
		if(s1<=0) return 0;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		
		long long int e,f,g;
		scanf("%lld%lld%lld",&e,&f,&g);
		
		for(int i=0;i<=e;i++)
		{
			long long int s = a+i*g;
			long long int t = b+(e-i)*f;
			int val = func(s,t,c,d);
			if(val==1)
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}