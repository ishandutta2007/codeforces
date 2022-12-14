#include <stdio.h>

long long int fact[110];
int func(long long int k)
{
	int ans = 0;
	while(k)
	{
		ans += k%2;
		k/=2;
	}
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=15;i++) fact[i] = i*fact[i-1];
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		
		int S = 0;
		int ans = func(a);
		
		int b = (1<<13);
		for(int i=0;i<b;i++)
		{
			int C = 0;
			long long int a2 = a;
			for(int j=0;j<=12;j++)
			{
				if(((i>>j)&1)==1) a2 -= fact[j+3],C++;
			}
			if(a2>=0)
			{
				int t = func(a2) + C;
				ans = ans<t?ans:t;
			}
		}
		printf("%d\n",ans);
	}
}