#include <stdio.h>
#include <vector>
#define MAX 1000000007

struct str{
	int first;
	int second;
	int value1;
	int value2;
};

std::vector<str> ans;
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
		for(int i=1;i<a;i+=2)
		{
			if(x[i]>=x[i+1]) ans.push_back({i,i+1,x[i+1],MAX});
			else ans.push_back({i,i+1,x[i],MAX});
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d %d %d\n",ans[i].first,ans[i].second,ans[i].value1,ans[i].value2);
	}
}