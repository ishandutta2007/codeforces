#include <stdio.h>
#include <vector>
#define MAX 123456789
std::vector<int> V[200010];

int size[200010],parent[200010];
int make(int k, int p)
{
	int sum = 1;
	parent[k] = p;
	
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==p) continue;
		sum += make(V[k][i],k);
	}
	size[k] = sum;
	return sum;
}

std::pair<long long int, long long int> func(int s, long long int t)
{
	long long int sum = 0;
	long long int m = 0;
	for(int i=0;i<V[s].size();i++)
	{
		if(V[s][i]==parent[s]) continue;
		std::pair<long long int,long long int> P = func(V[s][i],t+size[s]-size[V[s][i]]);
		m = m>P.first-P.second-size[V[s][i]]?m:P.first-P.second-size[V[s][i]];
		sum += P.second;
	}
	long long int ans = m+sum+t+size[s]; // max?
	return std::make_pair(ans,sum+size[s]);
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	make(1,0);
	
	std::pair<long long int, long long int> P = func(1,0);
	printf("%lld",P.first);
}