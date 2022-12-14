#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V;
long long int func(long long int k)
{
	long long int start = 1;
	long long int gap = 2;
	
	long long int sum = 0;
	for(int i=0;i<V.size();i++)
	{
		if(start>k) break;
		if(V[i]%2==1)
		{
			sum += (k-start)/gap + 1;
		}
		start*=2, gap*=2;
	}
	return sum;
}

int main()
{
	long long int a;
	scanf("%lld",&a);
	while(a)
	{
		V.push_back(a);
		a/=2;
	}
	std::reverse(V.begin(),V.end());
	
	long long int b,c;
	scanf("%lld%lld",&b,&c);
	printf("%lld",func(c)-func(b-1));
}