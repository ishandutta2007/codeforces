#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[110];
int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	
	int min = 1, max = a;
	int ans = a;
	while(min<=max)
	{
		int h = (min+max)/2;
		for(int i=0;i<h;i++) V[i].clear();
		for(int i=1;i<=a;i++) V[i%h].push_back(x[i]);
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<V[i].size();j++)
			{
				if(V[i][j]<j)
				{
					min = h+1;
					goto u;
				}
			}
		}
		ans = h;
		max = h-1;
		u:;
	}
	printf("%d",ans);
}