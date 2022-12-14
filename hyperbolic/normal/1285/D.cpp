#include <stdio.h>
#include <vector>

std::vector<int> V[100010];
long long int func(std::vector<int>& V2, int k)
{
	if(k<0) return 0;
	
	int count0 = 0, count1 = 0;
	for(int i=0;i<V2.size();i++)
	{
		if(V[V2[i]][k]==0) count0++;
		else count1++;
	}
	if(count0==0 || count1==0) return func(V2,k-1);
	else
	{
		std::vector<int> V3,V4;
		for(int i=0;i<V2.size();i++)
		{
			if(V[V2[i]][k]==0) V3.push_back(V2[i]);
			else V4.push_back(V2[i]);
		}
		long long int S1 = func(V3,k-1);
		long long int S2 = func(V4,k-1);
		return (S1<S2?S1:S2) + (1<<k);
	}
}

std::vector<int> V2;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=0;j<=30;j++)
		{
			V[i].push_back(b%2);
			b/=2;
		}
	}
	for(int i=1;i<=a;i++) V2.push_back(i);
	
	printf("%lld",func(V2,30));
}