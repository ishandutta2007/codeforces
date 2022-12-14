#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 12345678

std::vector<int> V[200010],V2[200010],V3[200010];

int dist[200010],x[200010];
std::queue<int> Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V2[d].push_back(c);
	}
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) dist[i] = MAX;
	Q.push(x[c]);
	dist[x[c]] = 1;
	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		
		for(int i=0;i<V2[v].size();i++)
		{
			if(dist[V2[v][i]]==MAX)
			{
				dist[V2[v][i]] = dist[v] + 1;
				Q.push(V2[v][i]);
			}
		}
	}
	for(int i=1;i<=a;i++) for(int j=0;j<V[i].size();j++) if(dist[V[i][j]]==dist[i]-1) V3[i].push_back(V[i][j]);
	
	
	int min = 0, max = 0;
	for(int i=1;i<c;i++)
	{
		if(dist[x[i+1]]==dist[x[i]]-1)
		{
			if(V3[x[i]].size()>=2) max++;
		}
		else min++,max++;
	}
	printf("%d %d",min,max);
}