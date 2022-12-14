#include <stdio.h>
#include <vector>

std::pair<int,int> P[5];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%d%d",&P[1].first,&P[1].second);
	scanf("%d%d",&P[2].first,&P[2].second);
	scanf("%d%d",&P[3].first,&P[3].second);
	if((P[1].first-P[2].first)*(P[1].first-P[3].first)<0)
	{
		printf("NO");
		return 0;
	}
	if((P[1].second-P[2].second)*(P[1].second-P[3].second)<0)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
}