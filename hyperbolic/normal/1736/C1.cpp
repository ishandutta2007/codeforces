#include <stdio.h>
#include <vector>

std::vector<int> event[200010];

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<=a;i++) event[i].clear();
		for(int i=1;i<=a;i++)
		{
			int start = i-x[i];
			if(start>=1) event[start].push_back(i);
		}
		
		long long int ans = 0;
		int limit = a+1;
		for(int i=a;i>=1;i--)
		{
			for(int j=0;j<event[i].size();j++) limit = limit<event[i][j]?limit:event[i][j];
			
			int R = limit-1;
			int L = i;
			ans += (R-L+1);
		}
		printf("%lld\n",ans);
	}
}