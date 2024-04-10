#include <stdio.h>
#include <set>
#include <vector>

std::vector<int> V[100010],S2[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
		if(c<d)
		{
			S2[c].push_back(d);
		}
		else
		{
			S2[d].push_back(c);
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) for(std::vector<int> ::iterator it = S2[i].begin();it!=S2[i].end();it++) ans += (S2[*it].size());
	printf("%lld\n",ans);
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		int s1 = (V[d].size()-S2[d].size());
		for(std::vector<int> ::iterator it = S2[d].begin();it!=S2[d].end();it++)
		{
			int v = (*it);
			ans -= s1;
			ans -= S2[v].size();
			S2[v].push_back(d);
			ans += (V[v].size()-S2[v].size());
		}
		
		S2[d].clear();
		printf("%lld\n",ans);
	}
}