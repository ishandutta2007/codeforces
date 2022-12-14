#include <stdio.h>
#include <vector>

int check[100010];
std::vector< std::pair<int,int> > V[100010];
int func(int k, int limit)
{
	if(check[k]==2) return 0;
	if(check[k]==1) return 1;
	
	check[k] = 1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].second<=limit) continue;
		int t = func(V[k][i].first,limit);
		if(t==1) return 1;
	}
	check[k] = 2;
	return 0;
}

void func2(int k, int limit, int &C)
{
	if(check[k]) return;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i].second<=limit) continue;
		func2(V[k][i].first,limit,C);
	}
	check[k] = C--;
}

struct str{
	int first;
	int second;
	int value;
}edge[100010];
std::vector<int> save;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		edge[i] = {c,d,e};
	}
	
	int min = 0, max = 1e9;
	int ans = 1e9;
	while(min<=max)
	{
		for(int i=1;i<=a;i++) check[i] = 0;
		int h = (min+max)/2;
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				int t = func(i,h);
				if(t==1)
				{
					min = h+1;
					goto u;
				}
			}
		}
		
		ans = h;
		max = h-1;
		u:;
	}
	
	for(int i=1;i<=a;i++) check[i] = 0;
	int C = a;
	for(int i=1;i<=a;i++) func2(i,ans,C);
	
	for(int i=1;i<=b;i++)
	{
		if(edge[i].value <= ans)
		{
			int s = check[edge[i].first];
			int t = check[edge[i].second];
			if(s>t) save.push_back(i);
		}
	}
	printf("%d %d\n",ans,save.size());
	for(int i=0;i<save.size();i++) printf("%d ",save[i]);
}