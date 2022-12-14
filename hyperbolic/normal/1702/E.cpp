#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int check[200010];
int func(int k)
{
	if(check[k]==1) return 0;
	check[k] = 1;
	int ans = 1;
	for(int i=0;i<V[k].size();i++) ans += func(V[k][i]);
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			V[b].push_back(c);
			V[c].push_back(b);
		}
		
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()!=2)
			{
				printf("NO\n");
				goto u;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				int t = func(i);
				if(t==0||t%2==1)
				{
					printf("NO\n");
					goto u;
				}		
			}
		}
		printf("YES\n");
		u:;
	}
	
}