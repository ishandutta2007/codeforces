#include <stdio.h>
#include <vector>
#include <algorithm>
std::vector<int> V[110];
int x[110][110];
int start[110],end[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		for(int i=1;i<=a;i++) std::sort(x[i]+1,x[i]+b+1);
		for(int i=1;i<=a;i++) start[i] = 1, end[i] = b;
		
		for(int i=1;i<=b;i++)
		{
			int p = 1;
			for(int j=1;j<=a;j++)
			{
				if(x[j][start[j]]<x[p][start[p]]) p = j;
			}
			
			for(int j=1;j<=a;j++)
			{
				if(j==p) V[j].push_back(x[j][start[j]++]);
				else V[j].push_back(x[j][end[j]--]);
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++) printf("%d ",V[i][j]);
			printf("\n");
		}
	}
}