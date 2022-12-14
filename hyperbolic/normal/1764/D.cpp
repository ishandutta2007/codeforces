#include <stdio.h>
long long int MOD;
int a,b;

long long int DP[5010][5010],sum[5010][5010],fact[5010];
int main()
{
	scanf("%d%lld",&a,&MOD);
	if(a==3)
	{
		printf("3");
		return 0;
	}
	
	fact[0] = 1;
	for(int i=1;i<=a;i++) fact[i] = (i*fact[i-1])%MOD;
	
	b = a/2;
	DP[0][0] = 1;
	for(int t=0;t<=a;t++) sum[0][t] = DP[0][t];
	for(int s=1;s<=b+3;s++)
	{
		for(int t=0;t<s;t++)
		{
			int L = s-b-1;
			if(L<0)
			{
				DP[s][t] = sum[s-1][s-t-1];
			}
			else DP[s][t] = (sum[s-1][s-t-1] - sum[L][s-t-1] + MOD)%MOD;
			DP[s][t] %= MOD;
		}
		if(s<=b-1) DP[s][s] = 1;
		for(int t=0;t<=s;t++) sum[s][s-t] = sum[s-1][s-t] + DP[s][t], sum[s][s-t] %= MOD;
	}
	
	long long int ans = 0;
	for(int i=b;i<=2*b-1;i++)
	{
		int s = a-i-2;
		if(s<-1) continue;
		if(s==-1)
		{
			long long int val = fact[2*b-2];
			ans += val, ans %= MOD;
			continue;
		}
		
		long long int c = 2*b-i;
		for(int t=0;t<=a;t++)
		{
			long long int val = DP[s][t];
			val *= fact[t+(i-1)], val %= MOD;
			//printf("%d %d %d %lld!!\n",i,t,t+i-1,fact[t+i-1]);
			val *= c, val %= MOD;
			ans += val, ans %= MOD;
			//printf("%d %d : %lld??\n",i,t,val);
		}
	}
	ans *= a, ans %= MOD;
	printf("%lld",ans);
}