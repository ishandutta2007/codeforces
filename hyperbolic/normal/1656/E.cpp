#include <stdio.h>
#include <vector>

int ans[100010];
std::vector<int> V[100010];
void func(int k, int prev, int S1, int S2)
{
	ans[k] = S1 - (V[k].size()-1)*S2;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,S2,S1);
	}
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
		for(int i=0;i<V[1].size();i++) func(V[1][i],1,1,-1);
		ans[1] = -V[1].size();
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}