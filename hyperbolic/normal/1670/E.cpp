#include <stdio.h>
#include <vector>

int b,C = 1;
std::vector< std::pair<int,int> > V[300010];
int ans[300010],ans2[300010];

void func(int k, int prev, int type)
{
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].first==prev) continue;
		if(type==1)
		{
			ans2[V[k][i].second] = b+C;
			ans[V[k][i].first] = C;
			C++;
			func(V[k][i].first,k,2);
		}
		else
		{
			ans2[V[k][i].second] = C;
			ans[V[k][i].first] = b+C;
			C++;
			func(V[k][i].first,k,1);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		C = 1;
		int a;
		scanf("%d",&a);
		b = (1<<a);
		for(int i=1;i<=b;i++) V[i].clear();
		
		for(int i=1;i<b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(std::make_pair(d,i));
			V[d].push_back(std::make_pair(c,i));
		}
		
		int root = 1;
		for(int i=1;i<=b;i++) if(V[i].size()==1) root = i;
		
		ans[root] = b;
		func(root,0,1);
		
		printf("%d\n",root);
		for(int i=1;i<=b;i++) printf("%d ",ans[i]);
		printf("\n");
		for(int i=1;i<b;i++) printf("%d ",ans2[i]);
		printf("\n");
	}
}