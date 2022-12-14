#include <stdio.h>
#include <vector>
#include <algorithm>

int ans = 0;
std::vector<int> V[200010],V2;
int func(int k, int prev)
{
	int save = -1;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		int t = func(V[k][i],k);
		if(save==-1) save = t;
		else if(save>t)
		{
			ans = ans>save+2?ans:save+2;
			save = t;
		}
		else ans = ans>t+2?ans:t+2;
	}
	return save+1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		V2.clear();
		
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
		
		for(int i=0;i<V[1].size();i++) V2.push_back(func(V[1][i],1));
		std::sort(V2.begin(),V2.end());
		for(int i=0;i<V2.size();i++)
		{
			if(i+1==V2.size()) ans = ans>V2[i]+1?ans:V2[i]+1;
			else ans = ans>V2[i]+2?ans:V2[i]+2;
		}
		printf("%d\n",ans);
	}
}