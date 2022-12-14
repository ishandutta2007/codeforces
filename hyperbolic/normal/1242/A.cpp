#include <stdio.h>
#include <vector>

std::vector<long long int> V;
int main()
{
	long long int a;
	scanf("%lld",&a);
	if(a==1)
	{
		printf("1");
		return 0;
	}
	
	long long int b = a;
	for(int i=2;(long long int)i*i<=b;i++)
	{
		if(a%i==0)
		{
			V.push_back(i);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) V.push_back(a);
	if(V.size()>=2)
	{
		printf("1");
		return 0;
	}
	else printf("%lld",V[0]);
}