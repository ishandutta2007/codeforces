#include <stdio.h>
#include <map>
#include <vector>

std::map< std::pair<int,int> , int > capacity;
std::vector<int> V[200010];
int x[200010];
int check[200010];

int func(int k, int prev)
{
	//printf("%d %d??\n",k,prev);
	check[k] = 1;
	int sum = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		if(check[V[k][i]]==1) continue;
		int t = func(V[k][i],k);
		int c = x[V[k][i]]-t;
		capacity[std::make_pair(k,V[k][i])] = c;
		sum -= c;
	}
	return sum;
}

std::vector< std::pair<int,int> > edge;
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int S = 0;
	for(int i=1;i<=a;i++) S += x[i];
	if(S!=0)
	{
		printf("Impossible");
		return 0;
	}
	
	int b;
	scanf("%d",&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
		edge.push_back(std::make_pair(c,d));
	}
	
	func(1,0);
	
	printf("Possible\n");
	for(int i=0;i<edge.size();i++)
	{
		int s = edge[i].first;
		int t = edge[i].second;
		if(capacity.find(std::make_pair(s,t))==capacity.end()) printf("%d\n",-capacity[std::make_pair(t,s)]);
		else printf("%d\n",capacity[std::make_pair(s,t)]);
	}
}