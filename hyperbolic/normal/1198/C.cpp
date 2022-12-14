#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[300010];
std::vector<int> edge;
int check[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		edge.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=3*a;i++) V[i].clear();
		for(int i=1;i<=3*a;i++) check[i] = 0;
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(std::make_pair(d,i));
			V[d].push_back(std::make_pair(c,i));
		}
		for(int i=1;i<=3*a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				if(check[V[i][j].first]==1)
				{
					check[V[i][j].first] = 0;
					edge.push_back(V[i][j].second);
					goto u;
				}
			}
			check[i] = 1;
			u:;
		}
		
		if(edge.size()>=a)
		{
			printf("Matching\n");
			for(int i=0;i<a;i++) printf("%d ",edge[i]);
			printf("\n");
		}
		else
		{
			printf("IndSet\n");
			std::vector<int> temp;
			for(int i=1;i<=3*a;i++) if(check[i]==1) temp.push_back(i);
			for(int i=0;i<a;i++) printf("%d ",temp[i]);
			printf("\n");
		}
	}
}