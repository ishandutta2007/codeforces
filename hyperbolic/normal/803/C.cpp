#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<long long int> V;
int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if(b>1000000000)
	{
		printf("-1");
		return 0;
	}
	long long int c = b*(b+1)/2;
	if(c>a)
	{
		printf("-1");
		return 0;
	}
	
	long long int g = a/c;
	for(long long int i=1;i*i<=a;i++)
	{
		if(a%i==0)
		{
			V.push_back(i);
			V.push_back(a/i);
		}
	}
	std::sort(V.begin(),V.end());
	for(int i=V.size()-1;i>=0;i--)
	{
		if(V[i]<=g)
		{
			for(int j=1;j<b;j++)
			{
				printf("%lld ",j*V[i]);
				a -= (j*V[i]);
			}
			printf("%lld",a);
			return 0;
		}
	}
}