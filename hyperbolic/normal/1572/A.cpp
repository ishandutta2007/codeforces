#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> V[200010],V2[200010];
std::priority_queue<int, std::vector<int>, std::greater<int> > Q;
int dist[200010],count[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V2[i].clear();
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) count[i] = dist[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			for(int j=1;j<=b;j++)
			{
				int c;
				scanf("%d",&c);
				if(i>c) V[c].push_back(i);
				else V2[c].push_back(i);
				count[i]++;
			}
		}
		
		for(int i=1;i<=a;i++) if(count[i]==0) Q.push(i);
		for(int i=1;i<=a;i++)
		{
			if(Q.empty()) break;
			std::vector<int> temp;
			while(!Q.empty())
			{
				int k = Q.top();
				//printf("%d!!\n",k);
				Q.pop();
				dist[k] = i;
				for(int j=0;j<V[k].size();j++)
				{
					count[V[k][j]]--;
					if(count[V[k][j]]==0) Q.push(V[k][j]);
				}
				for(int j=0;j<V2[k].size();j++)
				{
					count[V2[k][j]]--;
					if(count[V2[k][j]]==0) temp.push_back(V2[k][j]);
				}
			}
			for(int j=0;j<temp.size();j++) Q.push(temp[j]);
		}
		
		
		int ans;
		for(int i=1;i<=a;i++)
		{
			if(dist[i]==0)
			{
				printf("-1\n");
				goto u;
			}
		}
		
		ans = dist[1];
		for(int i=2;i<=a;i++) ans = ans>dist[i]?ans:dist[i];
		printf("%d\n",ans);
		u:;
	}
	
}