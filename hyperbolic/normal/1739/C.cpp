#include <stdio.h>
#define MOD 998244353

long long int check[110][110];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check[s][t]) return check[s][t];
	return check[s][t] = (comb(s-1,t-1) + comb(s-1,t))%MOD;
}

long long int val1[110],val2[110];
int main()
{
	val1[2] = 1;
	val2[2] = 0;
	for(int i=4;i<=60;i+=2)
	{
		val1[i] = comb(i-1,i/2);
		val2[i] = comb(i-2,i/2);
		val1[i] += val2[i-2];
		val2[i] += val1[i-2];
		val1[i] %= MOD, val2[i] %= MOD;
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%lld %lld 1\n",val1[a],val2[a]);
	}
}