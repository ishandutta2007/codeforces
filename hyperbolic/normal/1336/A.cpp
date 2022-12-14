#include <stdio.h>
#include <queue>
#include <vector>

std::vector<int> V[200010];
std::priority_queue<int> Q;

int func(int k, int prev, int h)
{
	int s = 0;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		s += func(V[k][i],k,h+1);
	}
	Q.push(h-1-s);
	
	return s+1;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	func(1,0,1);
	
	long long int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int k = Q.top();
		Q.pop();
		
		ans += k;
	}
	printf("%lld",ans);
}