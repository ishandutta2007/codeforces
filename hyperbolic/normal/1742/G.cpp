#include <stdio.h>
#include <vector>
#include <algorithm>

int x[200010];
std::vector< std::pair<int,int> > V;
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
		for(int i=1;i<=a;i++) V.push_back(std::make_pair(x[i],x[i]));
		
		while(!V.empty())
		{
			std::sort(V.begin(),V.end());
			std::reverse(V.begin(),V.end());
			if(V[0].first==0) break;
			
			printf("%d ",V[0].second);
			int val = V[0].first;
			for(int i=0;i<V.size();i++) V[i].first -= (V[i].first&val);
			std::reverse(V.begin(),V.end());
			V.pop_back();
		}
		for(int i=0;i<V.size();i++) printf("%d ",V[i].second);
		printf("\n");
	}
}