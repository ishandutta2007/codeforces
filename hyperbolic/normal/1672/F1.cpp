#include <stdio.h>
#include <vector>
int x[200010],y[200010];
std::vector<int> V[200010],W[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) V[x[i]].push_back(i);
		
		for(int i=1;i<=a;i++) for(int j=0;j<V[i].size();j++) W[j+1].push_back(V[i][j]);
		
		for(int i=1;i<=a;i++)
		{
			if(W[i].size()==0);
			else if(W[i].size()==1) y[W[i][0]] = x[W[i][0]];
			else
			{
				for(int j=0;j+1<W[i].size();j++) y[W[i][j+1]] = x[W[i][j]];
				y[W[i][0]] = x[W[i].back()];
			}
		}
		
		for(int i=1;i<=a;i++) printf("%d ",y[i]);
		printf("\n");
		
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) W[i].clear();
	}
}