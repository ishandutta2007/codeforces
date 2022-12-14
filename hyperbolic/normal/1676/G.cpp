#include <stdio.h>
#include <vector>

std::vector<int> V[4010];
char x[4010];
int check[4010];
int ans;

int func(int k)
{
	int sum = check[k];
	for(int i=0;i<V[k].size();i++) sum += func(V[k][i]);
	if(sum==0) ans++;
	return sum;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		
		for(int i=2;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			V[b].push_back(i);
		}
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='W') check[i] = 1;
			else check[i] = -1;
		}
		
		func(1);
		printf("%d\n",ans);
	}
}