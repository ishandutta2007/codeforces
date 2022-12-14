#include <stdio.h>
#include <algorithm>
struct str{
	int first;
	int second;
	int index;
}x[200010];
bool cmp(str a, str b)
{
	return a.second<b.second;
}

std::pair<int,int> ans[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=b;i++)
		{
			int c,d;
			scanf("%d%d",&c,&d);
			x[i] = {c,d,i};
		}
		std::sort(x+1,x+b+1,cmp);
		
		long long int sum = 0;
		for(int i=1;i<=2*a;i++) sum += x[i].second;
		for(int i=1;i<=2*a;i++) ans[i] = std::make_pair(x[i].first,x[i].index);
		std::sort(ans+1,ans+2*a+1);
		
		printf("%lld\n",sum);
		for(int i=1;i<=a;i++) printf("%d %d\n",ans[i].second,ans[2*a-i+1].second);
	}
}