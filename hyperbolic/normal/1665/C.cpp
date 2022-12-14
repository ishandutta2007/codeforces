#include <stdio.h>
#include <vector>
#include <algorithm>

std::vector<int> V[200010],save;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		save.clear();
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
		}
		
		for(int i=1;i<=a;i++) if(V[i].size()>0) save.push_back(V[i].size());
		save.push_back(1);
		std::sort(save.begin(),save.end());
		std::reverse(save.begin(),save.end());
		
		int n = save.size();
		int ans = 200000;
		int min = n, max = 200000;
		while(min<=max)
		{
			int h = (min+max)/2;
			int sum = 0;
			for(int i=0;i<save.size();i++)
			{
				if(save[i]>(h-i))
				{
					sum += (save[i]-(h-i));
				}
			}
			if(sum<=(h-n))
			{
				ans = h;
				max = h-1;
			}
			else min = h+1;
		}
		printf("%d\n",ans);
	}
}