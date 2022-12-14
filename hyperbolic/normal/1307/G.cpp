#include <stdio.h>
#include <vector>
#include <queue>
#define VSIZE 50
#define MAX 1234567890

struct Edge{
		int v1;
		int v2;
		int capacity;
		int cost;
	};
std::vector<Edge> V;
std::vector<int> edge[VSIZE+1];

struct MCMF{
	
	void addEdge(int v1, int v2, int capacity, int cost)
	{
		V.push_back({v1,v2,capacity,cost});
		V.push_back({v2,v1,0,-cost});
		int s1 = V.size()-2, s2 = V.size()-1;
		edge[v1].push_back(s1);
		edge[v2].push_back(s2);
	}
	
	int end;
	std::queue<int> Q;
	int check[VSIZE+1],dist[VSIZE+1];
	int prev[VSIZE+1];
	
	void SPFA(int start)
	{
		for(int i=0;i<=VSIZE;i++) dist[i] = MAX;
		dist[start] = 0;
		for(int i=1;i<=VSIZE;i++)
		{
			for(int j=0;j<V.size();j++)
			{
				int v1 = V[j].v1;
				int v2 = V[j].v2;
				int cap = V[j].capacity;
				int cost = V[j].cost;
				if(cap>0 && dist[v1] + cost < dist[v2]) dist[v2] = dist[v1] + cost, prev[v2] = j;
			}
		}
	}
	
	int func(int start) // flow, cost
	{
		int sum = 0;
		int p = end;
		while(p!=start) 
		{
			V[prev[p]].capacity--;
			V[prev[p]^1].capacity++;
			sum += V[prev[p]].cost;
			p = V[prev[p]].v1;
		}
		return sum;
	}
	
	std::vector<int> flowTable(int start)
	{
		std::vector<int> ans;
		ans.push_back(0);
		int sum = 0;
		
		while(1)
		{
			SPFA(start);
			if(dist[end] == MAX) break;
			sum += func(start);
			ans.push_back(sum);
		}
		return ans;
	}
}F;

std::vector<int> table;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		F.addEdge(c,d,1,e);
	}
	F.end = a;
	table = F.flowTable(1);
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		double ans = MAX;
		for(int j=1;j<table.size();j++)
		{
			double s = (double)(table[j]+d)/j;
			ans = ans<s?ans:s;
		}
		printf("%.12lf\n",ans);
	}
	
}