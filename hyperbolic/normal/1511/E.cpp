#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k =a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int value[300010];

char x[300010];
std::vector<char> V[300010];
int main()
{
	value[0] = 0;
	value[1] = 0;
	long long int C = 1;
	for(int i=2;i<=300000;i++)
	{
		value[i] = (C+2*value[i-2]+value[i-1])%MOD;
		C*=2, C%=MOD;
	}
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int j=0;j<=b+1;j++) V[0].push_back('*');
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		V[i].push_back('*');
		for(int j=1;j<=b;j++) V[i].push_back(x[j]);
		V[i].push_back('*');
	}
	for(int j=0;j<=b+1;j++) V[a+1].push_back('*');
	
	int C2 = 0;
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(V[i][j]=='o') C2++;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		for(int j=1;j<=b+1;j++)
		{
			if(V[i][j]=='o')
			{
				count++;
			}
			else
			{
				ans += value[count]*power(2,C2-count);
				ans %= MOD;
				count = 0;
			}
		}
	}
	
	for(int j=1;j<=b;j++)
	{
		int count = 0;
		for(int i=1;i<=a+1;i++)
		{
			if(V[i][j]=='o')
			{
				count++;
			}
			else
			{
				ans += value[count]*power(2,C2-count);
				ans %= MOD;
				count = 0;
			}
		}
	}
	
	printf("%lld",ans);
}