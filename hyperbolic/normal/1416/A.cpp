#include <stdio.h>
#include <vector>

std::vector<int> V[300010];
int ans[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) ans[i] = -1;
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) V[i].push_back(0);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
		}
		for(int i=1;i<=a;i++) V[i].push_back(a+1);
		for(int i=a;i>=1;i--)
		{
			int p = 0;
			for(int j=0;j+1<V[i].size();j++) p = p>V[i][j+1]-V[i][j]?p:V[i][j+1]-V[i][j];
			ans[p] = i;
		}
		for(int i=1;i<=a;i++)
		{
			if(ans[i]==-1) ans[i] = ans[i-1];
			else if(ans[i-1]!=-1 && ans[i-1]<ans[i]) ans[i] = ans[i-1];
		}
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}