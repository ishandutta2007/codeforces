#include <stdio.h>
#include <vector>

std::vector<int> V[200010],ans;
int color[200010],x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) color[i] = 0;
		ans.clear();
		
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) V[x[i]].push_back(i);
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()>=b) for(int j=0;j<b;j++) color[V[i][j]] = j+1;
			else for(int j=0;j<V[i].size();j++) ans.push_back(V[i][j]);
		}
		int t = (ans.size()/b)*b;
		for(int i=0;i<t;i++) color[ans[i]] = i%b + 1;
		
		for(int i=1;i<=a;i++) printf("%d ",color[i]);
		printf("\n");
	}
}