#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<int,int> > V;
int x[100010],ans[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) ans[i] = 1;
		for(int i=1;i<a;i++) V.push_back(std::make_pair(x[i]-x[i+1],i+1));
		std::sort(V.begin(),V.end());
		std::reverse(V.begin(),V.end());
		for(int i=0;i<V.size();i++) ans[a-i] = V[i].second;
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}