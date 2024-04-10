#include <stdio.h>
#include <queue>


std::priority_queue<long long int> Q;
long long int ans[300010],s[300010];
int x[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--) s[i] = s[i+1] + x[i];
	for(int i=2;i<=a;i++) Q.push(s[i]);
	
	long long int ans = 0;
	for(int i=1;i<b;i++)
	{
		long long int t = Q.top();
		Q.pop();
		ans += t;
	}
	printf("%lld",ans+s[1]);
}