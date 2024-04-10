#include <stdio.h>
#include <vector>

int control;
std::vector< std::pair<int,int> > edge,ans;
std::vector<int> V1[200010],V2[200010];
int check[200010];
int check2[200010];


void func(int k)
{
	if(control) return;
	if(check[k]==2) return;
	if(check[k]==1)
	{
		control = 1;
		return;
	}
	
	check[k] = 1;
	for(int i=0;i<V2[k].size();i++) func(V2[k][i]);
	
	for(int i=0;i<V1[k].size();i++)
	{
		if(check2[V1[k][i]]==0)
		{
			int s0 = edge[V1[k][i]].first;
			int t0 = edge[V1[k][i]].second;
			if(s0==k)
			{
				ans.push_back(std::make_pair(t0,s0));
				check2[V1[k][i]] = 1;
			}
			else
			{
				ans.push_back(std::make_pair(s0,t0));
				check2[V1[k][i]] = 1;
			}
		}
	}
	check[k] = 2;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		ans.clear();
		edge.clear();
		control = 0;
		for(int i=0;i<=a;i++) V1[i].clear();
		for(int i=0;i<=a;i++) V2[i].clear();
		for(int i=0;i<=a;i++) check[i] = 0;
		for(int i=0;i<=b;i++) check2[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			if(c==0)
			{
				edge.push_back(std::make_pair(d,e));
				V1[d].push_back(edge.size()-1);
				V1[e].push_back(edge.size()-1);
			}
			else
			{
				V2[d].push_back(e);
				ans.push_back(std::make_pair(d,e));
			}
		}
		
		for(int i=1;i<=a;i++) if(check[i]==0) func(i);
		if(control) printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
		}
	}
}