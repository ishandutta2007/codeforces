#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
long long int MAX = 2;
struct str{
	int first;
	long long int second;
};
bool operator<(str a, str b)
{
	return a.second>b.second;
}
std::vector<int> V[200010];
int x[200010];
long long int sum[600010];
long long int dist[5][200010];

void func(int v, int start)
{
	std::priority_queue<str> Q;
	Q.push({start,0});
	while(!Q.empty())
	{
		int k = Q.top().first;
		int d = Q.top().second;
		Q.pop();
		if(dist[v][k]!=-1) continue;
		dist[v][k] = d;
		
		for(int i=0;i<V[k].size();i++) Q.push({V[k][i],d+1});
	}
}
int main()
{
	for(int i=1;i<=16;i++) MAX*=10;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d,e;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) dist[1][i] = dist[2][i] = dist[3][i] = -1;
		
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+b+1);
		for(int i=1;i<=b;i++) sum[i] = sum[i-1] + x[i];
		
		for(int i=1;i<=b;i++)
		{
			int f,g;
			scanf("%d%d",&f,&g);
			V[f].push_back(g);
			V[g].push_back(f);
		}
		func(1,c);
		func(2,d);
		func(3,e);
		
		long long int ans = MAX;
		for(int i=1;i<=a;i++)
		{
			if(dist[2][i]+dist[1][i]+dist[3][i]>b) continue;
			long long int S = 2*(sum[dist[2][i]]) + (sum[dist[2][i]+dist[1][i]+dist[3][i]]-sum[dist[2][i]]);
			ans = ans<S?ans:S;
		}
		printf("%lld\n",ans);
	}
}