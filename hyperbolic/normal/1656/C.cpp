#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V.push_back(b);
		}
		std::sort(V.begin(),V.end());
		V.erase(std::unique(V.begin(),V.end()),V.end());
		
		if(V.size()==1) printf("YES\n");
		else
		{
			if(V[0]==0)
			{
				if(V[1]==1) printf("NO\n");
				else printf("YES\n");
			}
			else if(V[0]==1)
			{
				for(int i=1;i<V.size();i++)
				{
					if(V[i]-V[i-1]==1)
					{
						printf("NO\n");
						goto u;
					}
				}
				printf("YES\n");
				u:;
			}
			else printf("YES\n");
		}
	}
}