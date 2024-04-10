#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector< std::pair<int,int> > V;
bool cmp(std::pair<int,int> a, std::pair<int,int> b)
{
	return a.second<b.second;
}

int x[300010],check[110];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		if(check[x[i]]==0)
		{
			V.push_back({x[i],i});
			check[x[i]] = 1;
		}
	}
	
	while(b--)
	{
		int c;
		scanf("%d",&c);
		for(int i=0;i<V.size();i++)
		{
			if(V[i].first==c)
			{
				printf("%d ",V[i].second);
				for(int j=0;j<i;j++) V[j].second++;
				V[i].second = 1;
				std::sort(V.begin(),V.end(),cmp);
				break;
			}
		}
	}
}