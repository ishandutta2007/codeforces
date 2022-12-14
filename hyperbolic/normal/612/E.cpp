#include <stdio.h>
#include <vector>

int next[1000010];
int ans[1000010],check[1000010];
std::vector<int> V,save[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&next[i]);
	
	for(int i=1;i<=a;i++)
	{
		if(check[i]==0)
		{
			V.clear();
			int p = i;
			while(check[p]==0)
			{
				check[p] = 1;
				V.push_back(p);
				p = next[p];
			}
			
			if(V.size()%2==1)
			{
				int p = next[V[(V.size()-1)/2]];
				for(int j=0;j<V.size();j++)
				{
					ans[V[j]] = p;
					p = next[p];
				}
			}
			else save[V.size()].push_back(i);
		}
	}
	
	for(int i=1;i<=a;i++) check[i] = 0;
	for(int i=2;i<=a;i+=2)
	{
		if(save[i].size()%2==1)
		{
			printf("-1");
			return 0;
		}
		for(int j=0;j<save[i].size();j+=2)
		{
			int s = save[i][j];
			int t = save[i][j+1];
			while(check[s]==0)
			{
				check[s] = 1;
				ans[s] = t;
				ans[t] = next[s];
				s = next[s], t = next[t];
			}
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}