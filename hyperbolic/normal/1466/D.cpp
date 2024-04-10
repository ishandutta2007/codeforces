#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> V[200010];
int x[200010];
std::pair<int,int> y[200010];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		for(int i=1;i<=a;i++) y[i] = std::make_pair(x[i],i);
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		
		printf("%lld ",sum);
		std::sort(y+1,y+a+1);
		for(int i=a;i>=1;i--)
		{
			for(int j=V[y[i].second].size()-1;j>=1;j--)
			{
				sum += y[i].first;
				printf("%lld ",sum);
			}
		}
		printf("\n");
	}
}