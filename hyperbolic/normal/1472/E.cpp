#include <stdio.h>
#include <algorithm>
#define MAX 1234567890
struct str{
	int first;
	int second;
	int index;
}P2[200010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second<b.second;
	return a.first<b.first;
}
int x[200010];
std::pair<int,int> P[200010];

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
			int b,c;
			scanf("%d%d",&b,&c);
			P[i] = std::make_pair(b,c);
		}
		
		for(int i=1;i<=a;i++) P2[i] = {P[i].first,P[i].second,i};
		std::sort(P2+1,P2+a+1,cmp);
		P2[0] = {MAX,MAX,0};
		x[0] = 0;
		for(int i=1;i<=a;i++)
		{
			if(P2[x[i-1]].second<P2[i].second) x[i] = x[i-1];
			else x[i] = i;
		}
		
		for(int i=1;i<=a;i++)
		{
			int min,max,ans;
			min = 1, max = a;
			ans = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(P2[h].first<P[i].first)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
			if(P2[x[ans]].second<P[i].second)
			{
				printf("%d ",P2[x[ans]].index);
				goto u;
			}
			
			min = 1, max = a;
			ans = 0;
			while(min<=max)
			{
				int h = (min+max)/2;
				if(P2[h].first<P[i].second)
				{
					ans = h;
					min = h+1;
				}
				else max = h-1;
			}
			if(P2[x[ans]].second<P[i].first)
			{
				printf("%d ",P2[x[ans]].index);
				goto u;
			}
			
			printf("-1 ");
			u:;
		}
		printf("\n");
	}
}