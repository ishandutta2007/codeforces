#include <stdio.h>
#include <stack>

std::stack<int> St;
int x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!St.empty()) St.pop();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		St.push(x[1]);
		
		for(int i=2;i<=a;i++)
		{
			while(!St.empty())
			{
				int k = St.top();
				if(k<x[i])
				{
					if(St.size()==1) break;
					else St.pop();
				}
				else
				{
					St.push(x[i]);
					break;
				}
			}
		}
		if(St.size()==1) printf("YES\n");
		else printf("NO\n");
	}
}