#include <stdio.h>
#include <vector>
std::vector< std::pair<int,int> > ans;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		int l = 1, r = a;
		while(l<=r)
		{
			ans.push_back(std::make_pair(3*l-2,3*r));
			l++, r--;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}