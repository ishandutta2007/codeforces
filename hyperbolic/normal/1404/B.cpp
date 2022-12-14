#include <stdio.h>
#include <vector>
#include <algorithm>

int a,b,c,d,e;
int ans1 = 0,ans2 = 0;
std::vector<int> V[100010];
int func(int k, int prev, int h)
{
	if(k==c) ans1 = h;
	
	std::vector<int> save;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int C = func(V[k][i],k,h+1);
		save.push_back(C);
	}
	
	if(save.size()==0) return 0;
	else if(save.size()==1)
	{
		ans2 = ans2>save[0]+1?ans2:save[0]+1;
		return save[0]+1;
	}
	else
	{
		std::sort(save.begin(),save.end());
		ans2 = ans2>save[save.size()-1]+save[save.size()-2]+2?ans2:save[save.size()-1]+save[save.size()-2]+2;
		return save[save.size()-1]+1;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans1 = ans2 = 0;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int f,g;
			scanf("%d%d",&f,&g);
			V[f].push_back(g);
			V[g].push_back(f);
		}
		
		if(e<=2*d) printf("Alice\n");
		else
		{
			int k = func(b,0,0);
			if(ans1<=d) printf("Alice\n");
			else if(ans2<=2*d) printf("Alice\n");
			else printf("Bob\n");
		}
	}
}