#include <stdio.h>
#include <vector>
#include <algorithm>

int x[100010],check[100010],ans[100010],type[100010];
std::vector<int> next[100010];

bool cmp(int s, int t)
{
	return check[s]<check[t];
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) next[i].clear();
		for(int i=0;i<=a+1;i++) ans[i] = check[i] = type[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) check[x[i]] = 1;
		
		for(int i=1;i<=a;i++) next[x[i]].push_back(i);
		ans[0] = a+1, ans[a+1] = 0;
		
		for(int i=0;i<=a+1;i++) std::sort(next[i].begin(),next[i].end(),cmp);
		
		if(check[a+1]) type[0] = 0;
		else type[0] = 1;
		
		if(check[a+1])
		{
			for(int j=0;j<next[ans[0]].size();j++)
			{
				type[j+1] = 1-type[0];
				ans[j+1] = next[ans[0]][j];
			}
		}
		else
		{
			for(int j=0;j<next[ans[a+1]].size();j++)
			{
				type[j+1] = 1-type[0];
				ans[j+1] = next[ans[a+1]][j];
			}
		}
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<next[ans[i]].size();j++)
			{
				type[i+j+1] = 1-type[i];
				ans[i+j+1] = next[ans[i]][j];
			}
		}
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum += type[i];
		
		printf("%d\n",sum);
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}