#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<long long int> V[200010];
long long int ans[200010];
int x[200010],y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) ans[i] = 0;
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) V[x[i]].push_back(y[i]);
		for(int i=1;i<=a;i++)
		{
			std::sort(V[i].begin(),V[i].end());
			std::reverse(V[i].begin(),V[i].end());
			for(int j=1;j<V[i].size();j++) V[i][j] += V[i][j-1];
			for(int j=1;j<=V[i].size();j++)
			{
				int t  = (V[i].size()/j)*j;
				ans[j] += V[i][t-1];
			}
		}
		
		for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
}