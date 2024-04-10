#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

struct str{
	int first;
	int second;
	int index;
}P[100010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}

std::pair<int,int> ans[100010];
std::vector< std::pair<int,int> > V;
std::set< std::pair<int,int> > save;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		P[i].first = c, P[i].second = d, P[i].index = i;
	}
	
	std::sort(P+1,P+b+1,cmp);
	
	int S = 1;
	for(int i=1;i<=b;i++)
	{
		if(P[i].second==1)
		{
			S++;
			ans[P[i].index] = std::make_pair(S,S-1);
		}
		else
		{
			long long int left = (long long int)(S)*(S-1)/2;
			left -= (i-1);
			if(left>0) V.push_back(std::make_pair(P[i].index,S));
			else
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	
	for(int i=1;i<=b&&i<=1000;i++) for(int j=1;j<i;j++) save.insert(std::make_pair(i,j));
	for(int i=1;i<=b;i++)
	{
		if(ans[i]!=std::make_pair(0,0)) if(save.find(ans[i])!=save.end()) save.erase(ans[i]);
	}
	
	for(int i=0;i<V.size();i++)
	{
		std::set< std::pair<int,int> > ::iterator it = save.begin();
		if(it==save.end())
		{
			printf("-1");
			return 0;
		}
		else
		{
			if(it->first <= V[i].second)
			{
				ans[V[i].first] = (*it);
				save.erase(it);
			}
			else
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	for(int i=1;i<=b;i++) printf("%d %d\n",ans[i].first,ans[i].second);
}