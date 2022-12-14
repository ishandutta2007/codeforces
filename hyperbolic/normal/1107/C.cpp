#include <stdio.h>
#include <queue>

std::priority_queue<int> Q;
int x[200010];
char y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	scanf("%s",y+1);
	
	long long int ans = 0;
	for(int i=1;i<=a+1;i++)
	{
		if(y[i]!=y[i-1])
		{
			for(int j=1;j<=b&&!Q.empty();j++)
			{
				ans += Q.top();
				Q.pop();
			}
			while(!Q.empty()) Q.pop();
			Q.push(x[i]);
		}
		else Q.push(x[i]);
	}
	
	printf("%lld",ans);
}