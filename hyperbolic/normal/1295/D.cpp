#include <stdio.h>
#include <vector>

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int prime[100010];
int p = 1;
std::vector<long long int> V;

long long int func(long long int limit, int s, long long int value, int count)
{
	if(s>=V.size()) return 0;
	if(value>limit) return 0;
	
	long long int s1 = func(limit,s+1,value,count);
	long long int s2 = func(limit,s+1,value*V[s],count+1);
	if((count+1)%2==1) s2 += limit/(value*V[s]);
	else s2 -= limit/(value*V[s]);
	
	return s1+s2;
}
int main()
{
	for(int i=2;i<=100000;i++)
	{
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0) goto u;
		}
		prime[p++] = i;
		u:;
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int d = gcd(a,b);
		a/=d, b/=d;
		long long int min = a-1, max = a+b-1;
		for(int i=1;i<p;i++)
		{
			if(b%prime[i]==0)
			{
				V.push_back(prime[i]);
				while(b%prime[i]==0) b/=prime[i];
			}
		}
		if(b!=1) V.push_back(b);
		printf("%lld\n",(max-func(max,0,1,0))-(min-func(min,0,1,0)));
	}
}