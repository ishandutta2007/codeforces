#include <stdio.h>
#include <vector>
int ans;
std::vector<int> V[300010];

int func(int k, int prev)
{
	int ans1 = 2 ,ans2 = 2;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int s = func(V[k][i],k);
		if(ans1<=s)
		{
			ans2 = ans1;
			ans1 = s;
		}
		else if(ans2<=s) ans2 = s;
	}
	ans = ans>ans1+ans2-3+V[k].size()?ans:ans1+ans2-3+V[k].size();
	return ans1-1 + V[k].size();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		ans = 2;
		func(1,0);
		printf("%d\n",ans);
	}
}