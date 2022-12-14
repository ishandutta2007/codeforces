#include <stdio.h>
#include <algorithm>

std::pair<int,int> x[500010];
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
			scanf("%d",&x[i].first);
			x[i].second = i;
		}
		std::sort(x+1,x+a+1);
		if(x[1].first+x[2].first<=x[a].first)
		{
			printf("%d %d %d\n",x[1].second,x[2].second,x[a].second);
		}
		else printf("-1\n");
	}
}