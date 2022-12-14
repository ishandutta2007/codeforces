#include <stdio.h>
#include <vector>
#include <algorithm>
int x[100010];
int check[100010];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int min = x[1];
		for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<=a;i++)
		{
			if(x[i]%min==0)
			{
				check[i] = 1;
				V.push_back(x[i]);
			}
		}
		std::sort(V.begin(),V.end());
		
		int p = 0;
		for(int i=1;i<=a;i++) if(check[i]==1) x[i]=V[p++];
		
		for(int i=1;i<a;i++)
		{
			if(x[i]>x[i+1])
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}