#include <stdio.h>

int func(long long int a, int C)
{
	for(int i=1;i<=C;i++) a/=10;
	return a%10;
}

int count[20],count2[20];
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	while(a)
	{
		count[a%10]++;
		a/=10;
	}
	long long int b2 = b;
	while(b2)
	{
		count2[b2%10]++;
		b2/=10;
	}
	
	int C1 = 0, C2 = 0;
	for(int i=9;i>=0;i--) C1 += count[i];
	for(int i=9;i>=0;i--) C2 += count2[i];
	if(C1<C2)
	{
		for(int i=9;i>=0;i--) for(int j=1;j<=count[i];j++) printf("%d",i);
		return 0;
	}
	else
	{
		long long int ans = 0 ,S = 0;
		for(int i=C2-1;i>=0;i--)
		{
			int start = 0;
			if(i==C2-1) start = 1;
			for(int j=func(b,i)-1;j>=0;j--)
			{
				if(count[j]>=1)
				{
					long long int S2 = S;
					S2 *= 10, S2 += j;
					count[j]--;
					for(int k=9;k>=0;k--) for(int l=1;l<=count[k];l++) S2 *= 10, S2 += k;
					count[j]++;
					ans = ans>S2?ans:S2;
					break;
				}
			}
			if(count[func(b,i)]>=1)
			{
				S *= 10, S += func(b,i);
				count[func(b,i)]--;
			}
			else goto u;
		}
		ans = ans>S?ans:S;
		u:;
		printf("%lld",ans);
	}
}