#include <stdio.h>
#include <vector>

struct str{
	int first;
	int value1;
	int value2;
};
std::vector<str> V[200010];
long long int sum1[200010],sum2[200010];
int height[200010], next[200010][21];

void init(int k, int p, int h, long long int S1 = 0, long long int S2 = 0)
{
	sum1[k] = S1;
	sum2[k] = S2;
	height[k] = h;
	next[k][0] = p;
	
	for(int i=0;i<V[k].size();i++) init(V[k][i].first, k, h+1, S1 + V[k][i].value1, S2 + V[k][i].value2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=2;i<=a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			V[b].push_back({i,c,d});
		}
		init(1,1,1,0,0);
		for(int j=1;j<=20;j++) for(int i=1;i<=a;i++) next[i][j] = next[next[i][j-1]][j-1];
		
		for(int i=2;i<=a;i++)
		{
			if(sum2[i]<=sum1[i]) printf("%d ",height[i]-1);
			else
			{
				int p = i;
				for(int j=20;j>=0;j--)
				{
					if(sum2[next[p][j]]>sum1[i]) p = next[p][j];
				}
				p = next[p][0];
				printf("%d ",height[p]-1);
			}
		}
		printf("\n");
	}
}