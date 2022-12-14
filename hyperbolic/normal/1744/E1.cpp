#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V,V1,V2;
int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		V.clear();
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		long long int val = (long long int)a*b;
		
		for(int i=1;i<=40000;i++)
		{
			if(a%i==0)
			{
				V1.push_back(i);
				V1.push_back(a/i);
			}
		}
		for(int i=1;i<=40000;i++)
		{
			if(b%i==0)
			{
				V2.push_back(i);
				V2.push_back(b/i);
			}
		}
		
		for(int i=0;i<V1.size();i++)
		{
			for(int j=0;j<V2.size();j++)
			{
				long long int val2 = V1[i]*V2[j];
				V.push_back(val2);
				V.push_back(val/val2);
			}
		}
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		for(int i=0;i<V.size();i++)
		{
			long long int L = a/V[i], R = c/V[i];
			while(L*V[i]<=a) L++;
			while(R*V[i]>c) R--;
			
			long long int val2 = val/V[i];
			long long int L2 = b/val2, R2 = d/val2;
			
			while(L2*val2<=b) L2++;
			while(R2*val2>d) R2--;
			
			if(L<=R && L2<=R2)
			{
				printf("%lld %lld\n",L*V[i],L2*val2);
				goto u;
			}
		}
		printf("-1 -1\n");
		u:;
	}
}