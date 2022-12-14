#include <stdio.h>
#include <set>
#include <vector>

int check[100010];
std::vector<int> V[100010];
int func(int k)
{
	if(check[k]==2) return 0;
	if(check[k]==1) return 1;
	
	check[k] = 1;
	for(int i=0;i<V[k].size();i++) if(func(V[k][i])) return 1;
	check[k] = 2;
	return 0;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) check[i] = 0;
		
		int ans = 0;
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			if(c==d) continue;
			V[c].push_back(d);
			ans++;
		}
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0) ans += func(i);
		}
		printf("%d\n",ans);
	}
}