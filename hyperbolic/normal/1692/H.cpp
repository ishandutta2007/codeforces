#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

std::vector<int> index;
std::map<int,int> hash;

int x[200010],y[200010];
std::vector<int> V[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		index.clear();
		hash.clear();
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) y[i] = x[i];
		for(int i=1;i<=a;i++) index.push_back(x[i]);
		std::sort(index.begin(),index.end());
		index.erase(std::unique(index.begin(),index.end()),index.end());
		for(int i=0;i<index.size();i++) hash[index[i]] = i+1;
		for(int i=1;i<=a;i++) x[i] = hash[x[i]];
		
		for(int i=1;i<=a;i++) V[x[i]].push_back(i);
		int ans = 1, ans1 = 1, ans2 = 1;
		
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()>0)
			{
				int max = 1;
				int p = V[i].back();
				for(int j=(int)V[i].size()-2;j>=0;j--)
				{
					max -= (V[i][j+1]-V[i][j]);
					max += 2;
					if(max<1)
					{
						max = 1;
						p = V[i][j];
					}
					if(max>ans) ans = max, ans1 = V[i][j], ans2 = p;
				}
			}
		}
		printf("%d %d %d\n",y[ans1],ans1,ans2);
	}
}