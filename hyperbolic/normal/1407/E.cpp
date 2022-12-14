#include <stdio.h>
#include <queue>
#include <vector>
#define MAX 123456789

std::vector< std::pair<int,int> > V[500010],V2[500010];
int dist[500010][3];
int final[500010];
std::queue<int> Q;
int check[500010];
int inQueue[500010];
int ans[500010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=a;i++) dist[i][0] = dist[i][1] = MAX;
	for(int i=1;i<=a;i++) final[i] = MAX;
	
	for(int i=1;i<=b;i++)
	{
		int c,d,e;
		scanf("%d%d%d",&c,&d,&e);
		V[c].push_back(std::make_pair(d,e));
		V2[d].push_back(std::make_pair(c,e));
	}
	
	Q.push(a);
	dist[a][0] = dist[a][1] = 0;
	final[a] = 1;
	
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		check[k] = 1;
		
		for(int i=0;i<V2[k].size();i++)
		{
			int s = V2[k][i].first;
			int t = V2[k][i].second;
			if(check[s]) continue;
			
			dist[s][t] = dist[s][t] < final[k]+1? dist[s][t] : final[k]+1;
			if(dist[s][0] > dist[s][1])
			{
				ans[s] = 0;
				final[s] = dist[s][0];
			}
			else
			{
				ans[s] = 1;
				final[s] = dist[s][1];
			}
			
			if(final[s]<MAX)
			{
				if(inQueue[s]==0)
				{
					inQueue[s] = 1;
					Q.push(s);
				}
			}
		}
	}
	
	if(final[1]>=MAX) printf("-1\n");
	else printf("%d\n",final[1]-1);
	for(int i=1;i<=a;i++) printf("%d",ans[i]);
}