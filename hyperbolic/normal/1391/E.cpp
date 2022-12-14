#include <stdio.h>
#include <vector>
int a,b;
std::vector<int> V[500010];
std::vector<int> St;
std::vector<int> ans1;
std::vector< std::pair<int,int> > ans2;
std::vector<int> node[500010];
int control;
int check[500010];

void func(int k, int prev, int level)
{
	if(control) return;
	if(check[k]) return;
	
	check[k] = level;
	St.push_back(k);
	if(St.size()>=(a+1)/2)
	{
		for(int i=0;i<St.size();i++) ans1.push_back(St[i]);
		control = 1;
		return;
	}
	node[level].push_back(k);
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,level+1);
	}
	St.pop_back();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans1.clear();
		ans2.clear();
		St.clear();
		control = 0;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) node[i].clear();
		for(int i=1;i<=a;i++) check[i] = 0;
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		
		func(1,0,1);
		if(control)
		{
			printf("PATH\n");
			printf("%d\n",ans1.size());
			for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
			printf("\n");
		}
		else
		{
			for(int i=1;i<=a;i++) for(int j=1;j<node[i].size();j+=2) ans2.push_back(std::make_pair(node[i][j-1],node[i][j]));
			printf("PAIRING\n");
			printf("%d\n",ans2.size());
			for(int i=0;i<ans2.size();i++) printf("%d %d\n",ans2[i].first,ans2[i].second);
		}
	}
}