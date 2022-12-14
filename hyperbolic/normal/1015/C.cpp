#include <stdio.h>
#include <vector>
#include <queue>

std::priority_queue<int> Q;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		ans += c;
		Q.push(c-d);
	}
	if(ans<=b)
	{
		printf("0");
		return 0;
	}
	int count = 0;
	while(!Q.empty())
	{
		int k = Q.top();
		Q.pop();
		ans -= k;
		count++;
		if(ans<=b)
		{
			printf("%d",count);
			return 0;
		}
	}
	printf("-1");
}