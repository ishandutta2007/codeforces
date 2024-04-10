#include <stdio.h>
#include <vector>
std::vector<int> V[100010];
int check[100010];
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
			V[i].clear();
			int b;
			scanf("%d",&b);
			for(int j=1;j<=b;j++)
			{
				int c;
				scanf("%d",&c);
				V[i].push_back(c);
			}
		}
		int p = 0,q = 0;
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				if(check[V[i][j]]==0)
				{
					check[V[i][j]] = 1;
					goto u;
				}
			}
			p = i;
			u:;
		}
		for(int i=1;i<=a;i++) if(check[i]==0) q = i;
		if(p==0) printf("OPTIMAL\n");
		else printf("IMPROVE\n%d %d\n",p,q);
	}
}