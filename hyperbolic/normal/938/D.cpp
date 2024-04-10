#include <stdio.h>
#include <queue>
#include <vector>
#define MAX (long long int)1e16

struct str{
	long long int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.first>b.first;
}
std::priority_queue<str> Q;
std::vector< std::pair<int, long long int> > V[200010];
long long int x[200010],ans[200010];


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		long long int e;
		scanf("%d%d%lld",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) Q.push({x[i],i});
	for(int i=1;i<=a;i++) ans[i] = MAX;
	
	while(!Q.empty())
	{
		long long int dist = Q.top().first;
		int ind = Q.top().second;
		Q.pop();
		if(ans[ind]<=dist) continue;
		ans[ind] = dist;
		
		for(int i=0;i<V[ind].size();i++) Q.push({2*V[ind][i].second+dist,V[ind][i].first});
	}
	
	for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
}