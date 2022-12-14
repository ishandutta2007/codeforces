#include <stdio.h>
#include <algorithm>

std::pair<int,int> y[110];
int x[110],ans[110];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) ans[i] = (x[i]+1)/2;
	
	int sum = 0;
	for(int i=1;i<=a;i++) sum += ans[i];
	if(b<sum)
	{
		printf("-1");
		return 0;
	}
	
	b -= sum;
	for(int i=1;i<=a;i++) y[i] = {x[i],i};
	std::sort(y+1,y+a+1);
	
	int p = a;
	while(b)
	{
		if(ans[y[p].second]==x[y[p].second]) p--;
		else ans[y[p].second]++,b--;
	}
	
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}