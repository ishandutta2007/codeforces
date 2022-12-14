#include <stdio.h>
#include <vector>
#define MOD 1000000007

std::vector<int> prime;
int count[100010];

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int func(int k, long long int S)
{
	if(S>100000) return 0;
	if(k==prime.size()) return power(2,count[S])-1;
	if(S*prime[k]>100000) return power(2,count[S])-1;
	
	long long int s1 = func(k+1,S);
	long long int s2 = func(k+1,S*prime[k]);
	return (s1-s2+MOD)%MOD;
}

int check[100010];
int main()
{
	for(int i=2;i<=100000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=100000;j+=i) check[j] = 1;
		}
	}
	
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		int c2 = c;
		for(int j=1;j*j<=c;j++)
		{
			if(c%j==0)
			{
				count[j]++;
				if(j*j!=c) count[c/j]++;
			}
		}
	}
	printf("%lld",func(0,1));
}