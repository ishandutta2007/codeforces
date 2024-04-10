#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> V[100010];
int x[100010];
int dist[100010][110];
std::queue<int> Q;
int temp[110];

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		V[e].push_back(f);
		V[f].push_back(e);
	}
	
	for(int j=1;j<=c;j++)
	{
		for(int i=1;i<=a;i++) if(x[i]==j) dist[i][j] = 1, Q.push(i);
		while(!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			for(int i=0;i<V[v].size();i++)
			{
				if(dist[V[v][i]][j]==0)
				{
					dist[V[v][i]][j] = dist[v][j]+1;
					Q.push(V[v][i]);
				}
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=c;j++) temp[j] = dist[i][j];
		std::sort(temp+1,temp+c+1);
		int ans = 0;
		for(int j=1;j<=d;j++) ans += (temp[j]-1);
		printf("%d ",ans);
	}
}