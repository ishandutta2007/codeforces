#include <stdio.h>
#include <vector>
int x[100010],check[100010];
std::vector<int> V[100010];

int func(int k, int p)
{
	int ans = x[k];
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==0)
		{
			int s = func(V[k][i],k);
			ans = ans<s?ans:s;
		}
	}
	return ans;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V[d].push_back(c);
	}
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) if(check[i]==0) sum += func(i,0);
	printf("%lld",sum);
}