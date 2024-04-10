#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[200010];
long long int ans = 0;
int x[200010];
int func(int k, long long int C)
{
	ans += C*x[k];
	if(V[k].size()==0) return x[k];
	int q = C/V[k].size();
	int r = C%V[k].size();
	
	std::vector<int> save;
	for(int i=0;i<V[k].size();i++) save.push_back(func(V[k][i],q));
	std::sort(save.begin(),save.end());
	std::reverse(save.begin(),save.end());
	for(int i=0;i<r;i++) ans += save[i];
	return save[r]+x[k];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=2;i<=a;i++)
		{
			int c;
			scanf("%d",&c);
			V[c].push_back(i);
		}
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		func(1,b);
		printf("%lld\n",ans);
	}
}