#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[500010];
std::vector<int> save[500010];
void func(int k, int prev, int h, int target)
{
	if(V[k].size()==1)
	{
		save[target].push_back(h);
		return;
	}
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		func(V[k][i],k,h+1,target);
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	
	
	for(int i=0;i<V[1].size();i++) func(V[1][i],1,0,V[1][i]);
	for(int i=0;i<V[1].size();i++) std::sort(save[V[1][i]].begin(),save[V[1][i]].end());
	
	int ans = 0;
	for(int i=0;i<V[1].size();i++)
	{
		int t = V[1][i];
		for(int j=1;j<save[t].size();j++)
		{
			if(save[t][j]<=save[t][j-1]) save[t][j] = save[t][j-1]+1;
		}
		ans = ans>save[t].back()+1?ans:save[t].back()+1;
	}
	printf("%d",ans);
}