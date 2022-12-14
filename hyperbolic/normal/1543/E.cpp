#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> V[20][70010];
int check[20][70010];
int color[20][70010],number[20][70010];
int hash[70010];
std::queue<int> Q;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int c = (1<<i);
			for(int j=0;j<c;j++) check[i][j] = 0;
			for(int j=0;j<c;j++) V[i][j].clear();
		}
		
		int b = a*(1<<(a-1));
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			V[a][c].push_back(d);
			V[a][d].push_back(c);
		}
		
		for(int i=a;i>=1;i--)
		{
			int c = (1<<i);
			
			int C = 0;
			check[i][V[i][0][0]] = 2;
			Q.push(0);
			while(!Q.empty())
			{
				int s = Q.front();
				Q.pop();
				if(check[i][s]) continue;
				check[i][s] = 1;
				
				int t;
				for(int j=0;j<V[i][s].size();j++)
				{
					int k = V[i][s][j];
					if(check[i][k]==2) t = k;
				}
				color[i][s] = color[i][t] = C++;
				for(int j=0;j<V[i][t].size();j++)
				{
					int k = V[i][t][j];
					if(check[i][k]==0) check[i][k] = 2;
				}
				for(int j=0;j<V[i][s].size();j++) Q.push(V[i][s][j]);
			}
			
			
			for(int j=0;j<c;j++)
			{
				if(check[i][j]==1)
				{
					for(int k=0;k<V[i][j].size();k++)
					{
						int t = V[i][j][k];
						if(check[i][t]==1) V[i-1][color[i][j]].push_back(color[i][t]);
					}
				}
			}
		}
		
		number[0][0] = 0;
		for(int i=1;i<=a;i++)
		{
			int c = (1<<i);
			for(int j=0;j<c;j++)
			{
				if(check[i][j]==1) number[i][j] = number[i-1][color[i][j]];
				else number[i][j] = number[i-1][color[i][j]] + (c/2);
			}
		}
		
		int c = (1<<a);
		for(int i=0;i<c;i++) hash[number[a][i]] = i;
		for(int i=0;i<c;i++) printf("%d ",hash[i]);
		printf("\n");
		
		int a2 = a;
		while(a2%2==0) a2/=2;
		if(a2!=1)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=0;i<c;i++)
		{
			int t = number[a][i];
			int C = 0;
			for(int j=0;j<a;j++)
			{
				if(t%2==1) C ^= j;
				t/=2;
			}
			printf("%d ",C);
		}
		printf("\n");
	}
}