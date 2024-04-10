#include <stdio.h>
#include <vector>

std::vector<int> V[210];
int x[110][110];
int check[110][110],check1[110],check2[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=2;i<=a+b;i++) V[i].clear();
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) V[i+j].push_back(x[i][j]);
		for(int i=2;i<=a+b;i++)
		{
			int S = 0;
			for(int j=0;j<V[i].size();j++) S ^= V[i][j];
			if(S!=0)
			{
				printf("Ashish\n");
				goto u;
			}
		}
		printf("Jeel\n");
		u:;
	}
}