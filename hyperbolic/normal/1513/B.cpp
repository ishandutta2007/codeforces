#include <stdio.h>
#include <algorithm>

#define MOD 1000000007

long long int fact[200010];
int x[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int count;
		long long int s1,s2;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		std::sort(x+1,x+a+1);
		if(x[1]!=x[2])
		{
			printf("0\n");
			continue;
		}
		for(int i=3;i<=a;i++)
		{
			if((x[i]&x[1])!=x[1])
			{
				printf("0\n");
				goto u;
			}
		}
		
		count = 0;
		for(int i=1;i<=a;i++) if(x[i]==x[1]) count++;
		s1 = (long long int)count*(count-1), s1 %= MOD;
		s2 = fact[a-2];
		printf("%lld\n",(s1*s2)%MOD);
		
		u:;
	}
}