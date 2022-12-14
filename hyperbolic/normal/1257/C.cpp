#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
		}
		
		
		int ans = 12345678;
		for(int i=1;i<=a;i++)
		{
			if(V[i].size()<=1) continue;
			for(int j=0;j<=V[i].size()-2;j++)
			{
				int k = V[i][j+1]-V[i][j];
				ans = ans<k?ans:k;
			}
		}
		if(ans==12345678) printf("-1\n");
		else printf("%d\n",ans+1);
	}
}