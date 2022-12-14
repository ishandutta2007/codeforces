#include <stdio.h>
#include <algorithm>

struct str{
	int first;
	int second;
	int index;
}P[300010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i]={b,c,i};
	}
	std::sort(P+1,P+a+1,cmp);
	for(int i=1;i<a;i++)
	{
		if(P[i].second>=P[i+1].second)
		{
			printf("%d %d",P[i+1].index,P[i].index);
			return 0;
		}
	}
	printf("-1 -1");
}