#include <stdio.h>
#include <stack>

std::stack<int> St;
int x[100010];
int ans[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		St.push(i);
		if(x[i-1]<x[i])
		{
			int p = x[i-1];
			while(!St.empty() && p<x[i])
			{
				ans[St.top()] = p;
				St.pop();
				p++;
			}
			if(St.empty() && p<x[i])
			{
				printf("-1");
				return 0;
			}
		}
	}
	while(!St.empty())
	{
		ans[St.top()] = a+1;
		St.pop();
	}
	for(int i=1;i<=a;i++) printf("%d ",ans[i]);
}