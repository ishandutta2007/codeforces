#include <stdio.h>
#include <algorithm>
#include <vector>

std::vector<int> ans;
std::pair<int,int> x[200010];
long long int sum[200010];
int check[200010];

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
			int b;
			scanf("%d",&b);
			x[i] = std::make_pair(b,i);
		}
		std::sort(x+1,x+a+1);
		
		for(int i=1;i<=a;i++) sum[i] = sum[i-1] + x[i].first;
		check[x[a].second] = 1;
		for(int i=a-1;i>=1;i--)
		{
			if(sum[i]>=x[i+1].first && check[x[i+1].second]==1) check[x[i].second] = 1;
			else check[x[i].second] = 0;
		}
		
		ans.clear();
		for(int i=1;i<=a;i++) if(check[i]==1) ans.push_back(i);
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
	}
}