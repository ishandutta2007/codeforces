#include <stdio.h>
#include <vector>

int dist[2010][2010],check[2010],prev[2010];
int count[3];
std::vector<int> V[2010];
int a;
void getQuery(int k)
{
	printf("? %d\n",k);
	fflush(stdout);
	
	for(int i=1;i<=a;i++) scanf("%d",&dist[k][i]);
}

int main()
{
	scanf("%d",&a);
	getQuery(1);
	check[1] = 1;
	
	int start;
	for(int i=2;i<=a;i++) count[dist[1][i]%2]++;
	if(count[0]<=count[1])
	{
		for(int i=2;i<=a;i++)
		{
			if(dist[1][i]==1)
			{
				prev[i] = 1;
				check[i] = 1;
			}
		}
		start = 2;
	}
	else start = 1;
	
	for(int i=2;i<=a;i++) if(dist[1][i]%2==start%2) V[dist[1][i]].push_back(i);
	
	for(int i=start;i<=a;i+=2)
	{
		for(int j=0;j<V[i].size();j++)
		{
			int v = V[i][j];
			getQuery(v);
			for(int k=1;k<=a;k++)
			{
				if(dist[v][k]==1)
				{
					if(check[k]==1) prev[v] = k;
					else prev[k] = v, check[k] = 1;
				}
			}
			check[v] = 1;
		}
	}
	
	printf("!\n");
	for(int i=2;i<=a;i++) printf("%d %d\n",i,prev[i]);
	fflush(stdout);
}