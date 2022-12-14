#include <stdio.h>
#include <set>
#define MAX (long long int)2e18

std::multiset<long long int> S;

int main()
{
	int a;
	scanf("%d",&a);
	long long int sum = 0;
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		S.insert(b);
		sum += b;
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		long long int ans = MAX;
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		std::multiset<long long int> ::iterator it1, it2;
		it1 = S.lower_bound(c);
		if(it1!=S.end())
		{
			long long int t = d-(sum-(*it1));
			t = t>0?t:0;
			ans = ans<t?ans:t;
		}
		if(it1!=S.begin())
		{
			it1--;
			long long int s = (c-(*it1));
			long long int t = d-(sum-(*it1));
			t = t>0?t:0;
			ans = ans<s+t?ans:s+t;
		}
		printf("%lld\n",ans);
	}
}