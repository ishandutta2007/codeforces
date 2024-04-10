#include <stdio.h>
#include <vector>

std::vector<int> ans;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=(b+1)/2;i<=a;i++) if(i!=b) ans.push_back(i);
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
}