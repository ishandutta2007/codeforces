#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> V[200010];
int check[200010];
int dist[200010];

int func(int k)
{
	if(check[k]!=-1) return check[k];
	int ans = dist[k];
	for(int i=0;i<V[k].size();i++)
	{
		int t;
		if(dist[V[k][i]]<=dist[k]) t = dist[V[k][i]];
		else t = func(V[k][i]);
		ans = ans<t?ans:t;
	}
	return check[k] = ans;
}

std::queue<int> Q;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) dist[i] = 0;
		for(int i=1;i<=a;i++) check[i] = -1;
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
		}
		
		Q.push(1);
		dist[1] = 1;
		while(!Q.empty())
		{
			int k = Q.front();
			Q.pop();
			
			for(int i=0;i<V[k].size();i++)
			{
				if(dist[V[k][i]]) continue;
				dist[V[k][i]] = dist[k]+1;
				Q.push(V[k][i]);
			}
		}
		for(int i=1;i<=a;i++) printf("%d ",func(i)-1);
		printf("\n");
	}
}