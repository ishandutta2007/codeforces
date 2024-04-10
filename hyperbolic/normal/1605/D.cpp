#include <stdio.h>
#include <vector>

int height[200010];
std::vector<int> V[200010];
void init(int k, int prev, int h)
{
	height[k] = h;
	for(int i=0;i<V[k].size();i++)
	{
		if(V[k][i]==prev) continue;
		init(V[k][i],k,h+1);
	}
}

std::vector<int> save[4],save2[4];
int check[1000010],ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		save[0].clear();
		save[1].clear();
		save2[1].clear();
		save2[2].clear();
		
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
		
		init(1,0,1);
		for(int i=1;i<=a;i++) save[height[i]%2].push_back(i);
		
		int pivot = 0;
		if(save[0].size()>save[1].size()) pivot = 1;
		int C = save[pivot].size();
		
		int start = 0;
		while((1<<start) < a) start++;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int j=start;j>=0;j--)
		{
			if(C >= (1<<j))
			{
				int s = (1<<j);
				for(int i=s;i<2*s;i++) check[i] = 1;
				C -= s;
			}
			else
			{
				int s = (1<<j);
				for(int i=s;i<2*s;i++) check[i] = 2;
			}
		}
		
		for(int i=1;i<=a;i++) save2[check[i]].push_back(i);
		
		for(int i=0;i<save[pivot].size();i++) ans[save[pivot][i]] = save2[1][i];
		for(int i=0;i<save[1-pivot].size();i++) ans[save[1-pivot][i]] = save2[2][i];
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}