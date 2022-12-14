#include <stdio.h>
#include <vector>
#include <algorithm>

std::pair<int,int> x[110];
std::vector<int> V;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i].first);
		for(int i=1;i<=a;i++) x[i].second = i;
		std::sort(x+1,x+a+1);
		
		printf("%d\n",x[a].second);
	}
}