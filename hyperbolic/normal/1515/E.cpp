#include <stdio.h>

int MOD;
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

long long int check[410][410];
long long int comb(int a, int b)
{
	if(a==b) return 1;
	if(b==0) return 1;
	if(check[a][b]!=0) return check[a][b];
	return check[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}
long long int DP[410][410];

int main()
{
	int a;
	scanf("%d%d",&a,&MOD);
	
	for(int i=1;i<=a;i++)
	{
		for(int k=1;k<=i-2;k++)
		{
			for(int j=1;j+k<=i;j++)
			{
				long long int S = DP[i-k-1][j] * comb(j+k,j);
				S %= MOD;
				S *= power(2,k-1), S %= MOD;
				DP[i][j+k] += S, DP[i][j+k] %= MOD;
			}
		}
		DP[i][i] = power(2,i-1);
	}
	
	long long int sum = 0;
	for(int i=0;i<=a;i++) sum += DP[a][i], sum %= MOD;
	printf("%lld",sum);
}