#include <stdio.h>
#include <queue>

std::priority_queue<int> Q;
int check[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		while(!Q.empty()) Q.pop();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			Q.push(b);
		}
		for(int i=0;i<=a;i++) check[i] = 0;
		
		while(!Q.empty())
		{
			int t = Q.top();
			Q.pop();
			
			if(t==0) break;
			else if(t>a) Q.push(t/2);
			else
			{
				if(check[t]==0) check[t] = 1;
				else Q.push(t/2);
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			if(check[i]==0)
			{
				printf("NO\n");
				goto u;
			}
		}
		printf("YES\n");
		u:;
	}
}