#include <stdio.h>

long long int sum[4000010];
long long int value[4000010];

int main()
{
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	long long int MOD = b;
	value[1] = 1;
	value[2] = MOD-1;
	long long int S = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s1 = sum[i-1];
		S += value[i];
		long long int val = (s1+S)%MOD;
		sum[i] = (sum[i-1]+val)%MOD;
		for(int j=2;;j++)
		{
			int L = j*i;
			int R = (i+1)*j-1;
			if(R>a) R = a;
			if(L>R) break;
			value[L] += val, value[L] %= MOD;
			value[R+1] += (MOD-val), value[R+1] %= MOD;
		}
	}
	
	printf("%lld",(sum[a]+MOD-sum[a-1])%MOD);
}