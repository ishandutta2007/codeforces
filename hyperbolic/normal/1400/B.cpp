#include <stdio.h>


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d,e,f;
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
		
		long long int ans = 0;
		for(int i=0;i<=c;i++)
		{
			if(i*e>a) continue;
			int c1 = i;
			int c2 = (a-i*e)/f;
			if(c2>d) c2 = d;
			
			int c3 = c-i;
			if(c3*e>b) c3 = b/e;
			int c6 = (d-c2);
			if(c6*f>b) c6 = b/f;
			int c4 = (b-e*c3)/f;
			int c5 = (b-c6*f)/e;
			if(c2+c4>d) c4 = d-c2;
			if(c1+c5>c) c5 = c-c1;
			
			ans = ans>c1+c2+c3+c4?ans:c1+c2+c3+c4;
			ans = ans>c1+c2+c5+c6?ans:c1+c2+c5+c6;
		}
		printf("%lld\n",ans);
	}
}