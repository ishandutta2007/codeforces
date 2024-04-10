#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > V[100010];
int check[100010],ans[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) ans[i] = ((1<<30) - 1);
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		ans[c] &= e;
		ans[d] &= e;
		V[c].push_back(std::make_pair(d,e));
		V[d].push_back(std::make_pair(c,e));
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(((ans[i]>>j)&1)!=0)
			{
				ans[i] -= (1<<j);
				int control = 0;
				for(int k=0;k<V[i].size();k++) if((ans[i]|ans[V[i][k].first])!=V[i][k].second) control = 1;
				if(control==1) ans[i] += (1<<j);
			}
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}