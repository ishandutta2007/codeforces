#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[200010];
int y[200010];
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=1;i<=a;i++)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		P[i] = std::make_pair(e,f);
	}
	std::sort(P+1,P+a+1);
	for(int i=2;i<=a;i++) P[i].second = P[i].second>P[i-1].second?P[i].second:P[i-1].second;
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	std::sort(y+1,y+b+1);
	y[0] = 0, y[b+1] = c;
	
	int min = 1, max = a;
	int ans = -1;
	while(min<=max)
	{
		int h = (min+max)/2;
		long long int sum = 0;
		for(int i=1;i<=b+1;i++)
		{
			int d = y[i]-y[i-1];
			int e = P[h].second;
			if(2*d-e<=0) sum += d;
			else
			{
				int s =  (2*d-e);
				
				if(d-s<0)
				{
					min = h+1;
					goto u;
				}
				int t = d-s;
				sum += (2*s+t);
			}
		}
		if(sum<=d)
		{
			ans = P[h].first;
			max = h-1;
		}
		else min = h+1;
		u:;
	}
	printf("%d",ans);
}