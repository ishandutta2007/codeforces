#include <stdio.h>
#include <vector>
#include <stack>
std::vector<int> V[200010];
std::stack<int> ans;
int check[200010],MAX;
void func(int k)
{
	check[k] = 1;
	ans.push(k);
	for(int i=0;i<V[k].size();i++)
	{
		if(check[V[k][i]]==0)
		{
			func(V[k][i]);
			ans.push(k);
		}
	}
}
int main()
{
	int a,b,c,d,e,count=0;
	scanf("%d%d%d",&a,&b,&c);
	if((2*a)%c==0) MAX = (2*a)/c;
	else MAX = (2*a)/c+1;
	for(int i=1;i<=b;i++)
	{
		scanf("%d%d",&d,&e);
		V[d].push_back(e);
		V[e].push_back(d);
	}
	func(1);
	while(!ans.empty())
	{
		if(ans.size()<=MAX)
		{
			printf("%d ",ans.size());
			while(!ans.empty()) printf("%d ",ans.top()),ans.pop();
			count++;
			if(count<c)
			{
				for(int i=1;i<=c-count;i++) printf("1 1\n");
			}
			return 0;
		}
		else
		{
			printf("%d ",MAX);
			for(int i=1;i<=MAX;i++) printf("%d ",ans.top()),ans.pop();
			count++;
			printf("\n");
		}
	}
}