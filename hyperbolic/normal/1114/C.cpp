#include <stdio.h>
#include <algorithm>

std::pair<long long int,int> prime[2000010];
int p = 1;
void func(long long int k)
{
	for(long long int i=2; i*i<=k;i++)
	{
		if(k%i==0)
		{
			prime[p].first = i;
			prime[p].second = 0;
			while(k%i==0)
			{
				prime[p].second++;
				k/=i;
			}
			p++;
		}
	}
	if(k>1) prime[p++] = std::make_pair(k,1);
}
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	func(b);
	long long int ans = 1;
	for(int i=1;i<=18;i++) ans *= 10;
	
	for(int i=1;i<p;i++)
	{
		long long int s = 0;
		long long int t = a;
		while(t)
		{
			s += (t/prime[i].first);
			t /= prime[i].first;
		}
		s/=prime[i].second;
		ans = ans<s?ans:s;
	}
	printf("%lld",ans);
}