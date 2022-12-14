#include <stdio.h>
#include <vector>
#include <algorithm>

int p[200010],check[200010],check2[200010];
std::vector< std::vector<int> > ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) check[i] = check2[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			check[b] = 1;
			p[i] = b;
		}
		
		if(a==1)
		{
			printf("1\n1\n1\n");
			continue;
		}
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				std::vector<int> V;
				int t = i;
				while(check2[t]==0)
				{
					V.push_back(t);
					check2[t] = 1;
					t = p[t];
				}
				std::reverse(V.begin(),V.end());
				ans.push_back(V);
			}
		}
		
		printf("%d\n",ans.size());
		for(int j=0;j<ans.size();j++)
		{
			std::vector<int> V = ans[j];
			printf("%d\n",V.size());
			for(int i=0;i<V.size();i++) printf("%d ",V[i]);
			printf("\n");
		}
	}
}