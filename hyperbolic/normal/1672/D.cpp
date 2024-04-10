#include <stdio.h>
#include <map>
#include <vector>

int count[200010];
std::vector< std::pair<int,int> > V1,V2;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) count[i] = 0;
		int prev,s;
		
		prev = 0, s = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(prev!=b)
			{
				V1.push_back(std::make_pair(prev,s));
				prev = b, s = 1;
			}
			else s++;
		}
		V1.push_back(std::make_pair(prev,s));
		prev = 0, s = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			if(prev!=b)
			{
				V2.push_back(std::make_pair(prev,s));
				prev = b, s = 1;
			}
			else s++;
		}
		V2.push_back(std::make_pair(prev,s));
		
		int p = 0;
		for(int i=0;i<V1.size();i++)
		{
			if(p==V2.size())
			{
				printf("NO\n");
				goto u;
			}
			if(V1[i].first==V2[p].first)
			{
				if(count[V1[i].first]+V1[i].second>=V2[p].second)
				{
					count[V1[i].first] += (V1[i].second-V2[p].second);
					p++;
				}
				else
				{
					V2[p].second -= (count[V1[i].first]+V1[i].second);
					count[V1[i].first] = 0;
				}
			}
			else count[V1[i].first] += V1[i].second;
		}
		if(p==V2.size()) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}