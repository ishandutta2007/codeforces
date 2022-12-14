#include <stdio.h>
#include <queue>
#define MAX 123456789
int x[100010];

std::priority_queue<int> Q;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++) Q.push(x[i+1]-x[i]-1);
	
	int ans = x[a]-x[1]+1;
	for(int i=1;i<=c-1;i++)
	{
		int t = Q.top();
		Q.pop();
		ans -= t;
	}
	printf("%d",ans);
}