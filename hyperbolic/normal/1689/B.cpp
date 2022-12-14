#include <stdio.h>
#include <vector>

int x[1010],ans[1010],check[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a==1)
		{
			printf("-1\n");
			continue;
		}
		
		for(int i=1;i<=a-2;i++)
		{
			for(int j=1;j<=a;j++)
			{
				if(check[j]==0&&j!=x[i])
				{
					ans[i] = j;
					check[j] = 1;
					break;
				}
			}
		}
		std::vector<int> V;
		for(int j=1;j<=a;j++) if(check[j]==0) V.push_back(j);
		if(V[0]==x[a-1]||V[1]==x[a]) ans[a-1] = V[1], ans[a] = V[0];
		else ans[a-1] = V[0], ans[a] = V[1];
		
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}