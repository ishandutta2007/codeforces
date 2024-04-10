#include <stdio.h>
#include <vector>
#include <algorithm>

int a,b;
int check[100010];
int getQuery(int s, int t)
{
	printf("? ");
	if(t==0)
	{
		for(int i=1;i<=b;i++)
		{
			if(i==s) printf("1");
			else printf("0");
		}
	}
	else
	{
		for(int i=1;i<=b;i++) printf("%d",check[i]);
	}
	printf("\n");
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

std::pair<int,int> edge[100010];
int main()
{
	scanf("%d%d",&a,&b);
	
	for(int i=1;i<=b;i++) edge[i].first = getQuery(i,0);
	for(int i=1;i<=b;i++) edge[i].second = i;
	std::sort(edge+1,edge+b+1);
	
	int prev = 0;
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		check[edge[i].second] = 1;
		int t = getQuery(i,1);
		if(prev+edge[i].first!=t) ans += (prev+edge[i].first)-t, ans -= edge[i].first;
		prev = t;
	}
	printf("! %d",ans+prev);
	fflush(stdout);
}