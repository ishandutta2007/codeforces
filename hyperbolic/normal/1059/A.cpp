#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[100010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		P[i]=std::make_pair(d,e);
	}
	P[a+1] = std::make_pair(b,b);
	P[0] = std::make_pair(0,0);
	int ans = 0;
	
	for(int i=0;i<=a;i++)
	{
		int s = P[i+1].first - (P[i].first+P[i].second);
		ans += s/c;
	}
	printf("%d",ans);
}