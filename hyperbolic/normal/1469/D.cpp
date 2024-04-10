#include <stdio.h>
#include <vector>
#include <math.h>
std::vector< std::pair<int,int> > ans;

int x[10];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		x[0] = a;
		for(int i=1;i<=5;i++) x[i] = (int)(sqrt(x[i-1])+1);
		for(int i=2;i<=a;i++)
		{
			for(int j=0;j<=5;j++) if(i==x[j]) goto u;
			ans.push_back(std::make_pair(i,a));
			u:;
		}
		for(int i=1;i<=5;i++)
		{
			if(x[i-1]==x[i]) continue;
			ans.push_back(std::make_pair(x[i-1],x[i]));
			ans.push_back(std::make_pair(x[i-1],x[i]));
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
	}
}