#include <stdio.h>
#include <queue>
#define MAX (long long int)1e18

std::queue<int> Q2;
long long int count[1010][1010],isQueue[1010],dist[1010],check[1010];

std::vector< std::pair<int,int> > V[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=b;i++)
		{
			int c,d,e;
			scanf("%d%d%d",&c,&d,&e);
			V[c].push_back(std::make_pair(d,e));
			V[d].push_back(std::make_pair(c,e));
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) count[i][j] = MAX;
			for(int j=1;j<=a;j++) isQueue[j] = 0;
			
			while(!Q2.empty()) Q2.pop();
			Q2.push(i);
			isQueue[i] = 1;
			count[i][i] = 0;
			while(!Q2.empty())
			{
				int t = Q2.front();
				Q2.pop();
				for(int j=0;j<V[t].size();j++)
				{
					if(isQueue[V[t][j].first]==0)
					{
						isQueue[V[t][j].first] = 1;
						count[i][V[t][j].first] = count[i][t] + 1;
						Q2.push(V[t][j].first);
					}
				}
			}
		}
		
		long long int ans = MAX;
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				int s = V[i][j].first, t = i;
				long long int val = V[i][j].second;
				for(int k=1;k<=a;k++)
				{
					long long int C = count[k][1] + count[k][a] + count[k][s] + 2;
					if(C<MAX) ans = ans<C*val?ans:C*val;
					C = count[k][1] + count[k][a] + count[k][t] + 2;
					if(C<MAX) ans = ans<C*val?ans:C*val;
				}
				long long int C = count[s][1] + count[t][a] + 1;
				if(C<MAX) ans = ans<C*val?ans:C*val;
				C = count[t][1] + count[s][a] + 1;
				if(C<MAX) ans = ans<C*val?ans:C*val;
			}
		}
		
		printf("%lld\n",ans);
	}
}