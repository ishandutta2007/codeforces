#include <stdio.h>
#include <vector>

std::vector<int> prime;
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
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int b;
		for(int i=0;i<prime.size();i++)
		{
			if(prime[i]>=a+1)
			{
				b = prime[i];
				break;
			}
		}
		int c;
		for(int i=0;i<prime.size();i++)
		{
			if(prime[i]>=b+a)
			{
				c = prime[i];
				break;
			}
		}
		printf("%lld\n",(long long int)b*c);
	}
}