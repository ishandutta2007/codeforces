#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> V,V2,prime;
std::map<int,int> check;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V2.clear();
		check.clear();
		V.clear();
		prime.clear();
		
		int a;
		scanf("%d",&a);
		int b = a;
		for(int i=2;i*i<=a;i++)
		{
			if(a%i==0)
			{
				V.push_back(i);
				if(i!=(a/i)) V.push_back(a/i);
			}
		}
		V.push_back(a);
		
		for(int i=2;i*i<=a;i++)
		{
			if(b%i==0)
			{
				prime.push_back(i);
				while(b%i==0) b/=i;
			}
		}
		if(b>1) prime.push_back(b);
		std::sort(V.begin(),V.end());
		
		if(prime.size()==1)
		{
			for(int i=0;i<V.size();i++) printf("%d ",V[i]);
			printf("\n0\n");
		}
		else if(prime.size()>=3)
		{
			for(int i=0;i+1<prime.size();i++) check[prime[i]*prime[i+1]] = 1;
			for(int i=0;i<prime.size();i++) check[prime[i]] = 1;
			check[prime.back()*prime[0]] = 1;
			
			for(int j=0;j<prime.size();j++)
			{
				printf("%d ",prime[j]);
				for(int i=0;i<V.size();i++)
				{
					if(check[V[i]]==0 && V[i]%prime[j]==0)
					{
						check[V[i]] = 1;
						printf("%d ",V[i]);
					}
				}
				if(j+1!=prime.size()) printf("%d ",prime[j]*prime[j+1]);
				else printf("%d\n",prime.back()*prime[0]);
			}
			printf("0\n");
		}
		else
		{
			V2.clear();
			for(int i=0;i<V.size();i++) if(V[i]%(prime[0]*prime[1])==0) V2.push_back(V[i]);
			if(V2.size()>=2)
			{
				check[V2[0]] = 1;
				check[V2[1]] = 1;
				for(int j=0;j<prime.size();j++) check[prime[j]] = 1;
				
				for(int j=0;j<prime.size();j++)
				{
					printf("%d ",prime[j]);
					for(int i=0;i<V.size();i++)
					{
						if(check[V[i]]==0 && V[i]%prime[j]==0)
						{
							check[V[i]] = 1;
							printf("%d ",V[i]);
						}
					}
					printf("%d ",V2[j]);
				}
				printf("\n");
				printf("0\n");
			}
			else
			{
				printf("%d %d %d\n",prime[0],prime[1],prime[0]*prime[1]);
				printf("1\n");
			}
		}
	}
}