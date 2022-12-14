#include <stdio.h>
#include <queue>
#include <vector>
std::priority_queue< int, std::vector<int>, std::greater<int> > Q;
std::vector<int> V[100010];
int check[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	Q.push(1);
	while(!Q.empty())
	{
		int k = Q.top();
		Q.pop();
		if(check[k]) continue;
		check[k] = 1;
		printf("%d ",k);
		
		for(int i=0;i<V[k].size();i++) Q.push(V[k][i]);
	}
}