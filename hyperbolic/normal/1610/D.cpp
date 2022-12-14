#include <stdio.h>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	if(b<0) return 1;
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k,k%=MOD;
	}
	return ans;
}

int x[200010];
int count[110];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		int C = 0;
		while(x[i]%2==0) C++, x[i]/=2;
		count[C]++;
	}
	
	long long int S = 0;
	int C = 0;
	for(int i=30;i>=1;i--)
	{
		long long int S2 = (power(2,count[i]-1)-1) * power(2,C);
		S2%=MOD;
		
		S += S2, S %= MOD;
		C+=count[i];
	}
	
	long long int S3 = power(2,count[0])-1;
	S3 *= power(2,C), S3 %= MOD;
	S += S3, S %= MOD;
	
	printf("%lld",S);
	
}