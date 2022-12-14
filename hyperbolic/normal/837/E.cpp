#include <stdio.h>
#include <vector>

std::vector<long long int> prime;
int check[1000010];
int isPrime(long long int k)
{
	for(int i=0;i<prime.size();i++) if(k%prime[i]==0) return 0;
	return 1;
}

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int func(long long int s, long long int t)
{
	long long int g = gcd(s,t);
	if(g>1) return func(s/g,t/g);
	else
	{
		if(isPrime(s))
		{
			long long int val1 = t/s;
			long long int val2 = t%s;
			return val1+val2;
		}
		else
		{
			long long int ans = 0;
			for(long long int i=t;i>=0;i--)
			{
				long long int g = gcd(s,i);
				if(g>1) return (t-i) + func(s,i);
			}
		}
	}
}

int main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=1000000;j+=i) check[j] = 1;
		}
	}
	
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	printf("%lld",func(a,b));
}