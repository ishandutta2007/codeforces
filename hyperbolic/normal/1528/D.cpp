#include <stdio.h>
#include <queue>
#include <vector>
#define MAX (long long int)1e16

std::priority_queue< std::pair<long long int, int>, std::vector< std::pair<long long int, int> >, std::greater< std::pair<long long int,int> > > Q;
std::vector< std::pair<int,int> > V[610];
long long int dist[610];
int check[610];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back({d,e});
	}
	
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a;j++) dist[j] = MAX;
		for(int j=0;j<a;j++) check[j] = 0;
		for(int j=0;j<V[i].size();j++) dist[V[i][j].first] = V[i][j].second;
		
		for(int j=0;j<a;j++)
		{
			int v = -1;
			for(int k=0;k<a;k++)
			{
				if(check[k]==0)
				{
					if(v==-1) v = k;
					else if(dist[v]>dist[k]) v = k;
				}
			}
			
			check[v] = 1;
			int d = dist[v]%a;
			for(int k=0;k<V[v].size();k++)
			{
				dist[(V[v][k].first+d)%a] = dist[(V[v][k].first+d)%a] < dist[v] + V[v][k].second? dist[(V[v][k].first+d)%a] : dist[v] + V[v][k].second;
			}
			dist[(v+1)%a] = dist[(v+1)%a] < dist[v]+1? dist[(v+1)%a] : dist[v]+1;
		}
		dist[i] = 0;
		
		for(int j=0;j<a;j++) printf("%lld ",dist[j]);
		printf("\n");
	}
}