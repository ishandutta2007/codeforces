#include <stdio.h>
#include <vector>

int ans = 0;
std::vector<int> V[200010];
int x[200010],y[200010],value[200010];
int func(int k)
{
	long long int sum = 0;
	for(int i=0;i<V[k].size();i++) sum += func(V[k][i]);
	if(sum<x[k])
	{
		ans++;
		value[k] = y[k];
	}
	else value[k] = sum<y[k]?sum:y[k];
	return value[k];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
		}
		for(int i=1;i<=a;i++) scanf("%d%d",&x[i],&y[i]);
		func(1);
		printf("%d\n",ans);
	}
}