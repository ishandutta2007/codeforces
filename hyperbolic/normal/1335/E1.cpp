#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[210];

int check[200010];
int count[210];
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=200;i++) V[i].clear();
		
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=200;i++) V[i].push_back(std::make_pair(0,a+1));
		for(int i=1;i<=200;i++) count[i] = 1;
		for(int i=1;i<=a;i++)
		{
			int v = x[i];
			V[v].push_back(std::make_pair(0,0));
			V[v][count[v]].first = i;
			count[v]++;
		}
		
		for(int i=1;i<=200;i++) count[i] = 1;
		for(int i=a;i>=1;i--)
		{
			int v = x[i];
			V[v][count[v]].second = i;
			count[v]++;
		}
		
		
		int ans = 0;
		for(int i=1;i<=200;i++)
		{
			for(int j=1;j<=a;j++) check[j] = check[j-1] + (x[j]==i?1:0);
			for(int j=1;j<=200;j++)
			{
				for(int k=0;k<V[j].size();k++)
				{
					if(V[j][k].first<V[j][k].second)
					{
						int S = check[V[j][k].second-1] - check[V[j][k].first];
						ans = ans>2*k+S?ans:2*k+S;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}