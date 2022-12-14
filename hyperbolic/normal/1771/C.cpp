#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> prime;
int check[100010],x[100010];
int main()
{
	for(int i=2;i<=32000;i++)
	{
		if(check[i]==0)
		{
			prime.push_back(i);
			for(int j=i;j<=32000;j+=i) check[j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int j=0;j<prime.size();j++)
		{
			int p = prime[j];
			int C = 0;
			for(int i=1;i<=a;i++)
			{
				if(x[i]%p==0)
				{
					C++;
					while(x[i]%p==0) x[i]/=p;
				}
			}
			
			if(C>1)
			{
				printf("YES\n");
				goto u;
			}
		}
		std::sort(x+1,x+a+1);
		for(int i=1;i<a;i++)
		{
			if(x[i]==1) continue;
			if(x[i]==x[i+1])
			{
				printf("YES\n");
				goto u;
			}
		}
		printf("NO\n");
		u:;
	}
}