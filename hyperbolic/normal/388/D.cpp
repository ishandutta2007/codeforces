#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

long long int check[110][110];
long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	if(check[a][b]) return check[a][b];
	return check[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}

long long int DP[110][110];
long long int check2[110][110][110];
long long int func(int k, int p, int C, int C2)
{
	if(C<0) return 0;
	if(p<0)
	{
		if(C==0) return 1;
		else return 0;
	}
	if(check2[p][C][C2]!=-1) return check2[p][C][C2];
	
	if(k>=(1<<p))
	{
		long long int t1 = 0, t2 = 0;
		for(int i=0;i<=C2;i+=2) t1 += comb(C2,i), t1 %= MOD;
		for(int i=1;i<=C2;i+=2) t2 += comb(C2,i), t2 %= MOD;
		
		long long int S1 = 0;
		if(p-C>=0)
		{
			S1 = DP[p][C] * power(2,(p-C)*C2);
			S1 %= MOD, S1 *= t1, S1 %= MOD;
		}
		
		long long int S2 = func(k-(1<<p),p-1,C,C2);
		S2 %= MOD, S2 *= t2, S2 %= MOD;
		long long int S3 = func(k-(1<<p),p-1,C-1,C2+1);
		S3 %= MOD;
		return check2[p][C][C2] = (S1+S2+S3)%MOD;
	}
	else
	{
		long long int t1 = 0;
		for(int i=0;i<=C2;i+=2) t1 += comb(C2,i), t1 %= MOD;
		
		return check2[p][C][C2] = (func(k,p-1,C,C2)*t1)%MOD;
	}
	
}

int main()
{
	DP[0][0] = 1;
	for(int i=1;i<=30;i++)
	{
		DP[i][0] = 1;
		for(int j=1;j<=i;j++)
		{
			long long int s1 = DP[i-1][j-1] * power(2,i-j);
			s1 %= MOD;
			long long int s2 = DP[i-1][j];
			DP[i][j] = (s1+s2)%MOD;
		}
	}
	
	int a;
	scanf("%d",&a);
	
	long long int sum = 0;
	
	for(int i=0;i<=30;i++) for(int j=0;j<=30;j++) for(int k=0;k<=30;k++) check2[i][j][k] = -1;
	
	for(int i=0;i<=30;i++) sum += func(a,30,i,0), sum %= MOD;
	printf("%lld",sum);
}