#include <stdio.h>
#include <vector>

std::vector<int> V[400010];
int value[400010],size[400010];
std::vector<int> save,temp;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		save.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<a;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		for(int i=1;i<=a;i++) value[i] = 1;
		for(int i=1;i<=a;i++) size[i] = V[i].size();
		for(int i=1;i<=a;i++) if(size[i]<=1) save.push_back(i);
		
		for(int i=1;i<=b&&!save.empty();i++)
		{
			temp.clear();
			while(!save.empty())
			{
				int t = save.back();
				save.pop_back();
				value[t] = 0;
				for(int j=0;j<V[t].size();j++)
				{
					size[V[t][j]]--;
					if(size[V[t][j]]==1) temp.push_back(V[t][j]);
				}
			}
			save = temp;
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++) ans += value[i];
		printf("%d\n",ans);
	}
}