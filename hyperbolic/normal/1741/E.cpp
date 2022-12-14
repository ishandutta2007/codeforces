#include <stdio.h>
#include <vector>

int a;
int check[200010],x[200010];
std::vector<int> event[200010];
int func(int k)
{
	if(k>a+1) return 0;
	if(k==a+1) return 1;
	if(check[k]!=-1) return check[k];
	
	int ans = func(k+x[k]+1);
	for(int i=0;i<event[k].size();i++)
	{
		int val = func(event[k][i]+1);
		ans = ans>val?ans:val;
	}
	return check[k] = ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) check[i] = -1;
		for(int i=0;i<=a+1;i++) event[i].clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) if(i-x[i]>0) event[i-x[i]].push_back(i);
		
		if(func(1)) printf("YES\n");
		else printf("NO\n");
	}
}