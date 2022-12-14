#include <stdio.h>
#include <vector>

std::vector< std::pair<int,int> > ans;
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(a==1)
		{
			printf("0\n");
			continue;
		}
		
		ans.push_back(std::make_pair(1,a));
		if((x[1]+x[a])%2==1) x[a] = x[1];
		else x[1] = x[a];
		for(int i=2;i<=a-1;i++)
		{
			if((x[1]+x[i])%2==1) ans.push_back(std::make_pair(1,i));
			else ans.push_back(std::make_pair(i,a));
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}