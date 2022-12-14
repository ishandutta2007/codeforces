#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

int a,b,c,d;
std::vector<int> V[100010];
int dist[10][100010];
std::queue<int> Q;
void init(int start, int target)
{
	for(int i=1;i<=a;i++) dist[target][i] = -1;
	dist[target][start] = 0;
	Q.push(start);
	while(!Q.empty())
	{
		int t = Q.front();
		Q.pop();
		for(int i=0;i<V[t].size();i++)
		{
			if(dist[target][V[t][i]]==-1)
			{
				dist[target][V[t][i]] = dist[target][t] + 1;
				Q.push(V[t][i]);
			}
		}
	}
}

int x[100010],y[100010];
int check[100010],check2[100010],check3[100010];
void func(int target, int bit, int start)
{
	check[bit] = 1;
	for(int i=1;i<=d;i++)
	{
		if(((bit>>i)&1)==0)
		{
			if(dist[0][start] + dist[i][start]+dist[i][target] == dist[0][target])
			{
				func(target,bit+(1<<i),y[i]);
			}
		}
	}
}

int car[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[c].push_back(d);
			V[d].push_back(c);
		}
		scanf("%d",&c);
		for(int i=1;i<=c;i++) scanf("%d",&x[i]);
		for(int i=1;i<=c;i++) car[i] = 1;
		
		scanf("%d",&d);
		for(int i=1;i<=d;i++)
		{
			int e;
			scanf("%d",&e);
			car[e] = 0;
			y[i] = x[e];
		}
		y[0] = 1;
		for(int i=0;i<=d;i++) init(y[i],i);
		
		for(int i=0;i<=128;i++) check2[i] = 0;
		check2[1] = 1;
		for(int i=1;i<=c;i++)
		{
			if(car[i]==0) continue;
			
			for(int j=0;j<=128;j++) check[j] = check3[j] = 0;
			func(x[i],1,1);
			for(int j=0;j<=128;j++)
			{
				if(check[j])
				{
					for(int k=0;k<=128;k++) if(check2[k]) check3[k|j] = 1;
				}
			}
			for(int j=0;j<=128;j++) check2[j] = check3[j];
		}
		
		int ans = 12345;
		for(int k=0;k<128;k++)
		{
			if(check2[k]==1)
			{
				int C = 0;
				for(int j=1;j<=d;j++)
				{
					if(((k>>j)&1)==0) C++;
				}
				ans = ans<C?ans:C;
			}
		}
		printf("%d\n",ans);
	}
}