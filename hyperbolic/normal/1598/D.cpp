#include <stdio.h>
#include <vector>

std::pair<int,int> P[200010];
int count1[200010],count2[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) count1[i] = count2[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			P[i] = std::make_pair(b,c);
			count1[b]++;
			count2[c]++;
		}
		
		long long int ans = (long long int)a*(a-1)*(a-2)/6;
		for(int i=1;i<=a;i++) ans -= (long long int)(count1[P[i].first]-1)*(count2[P[i].second]-1);
		printf("%lld\n",ans);
	}
}