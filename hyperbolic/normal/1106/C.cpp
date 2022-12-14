#include <stdio.h>
#include <algorithm>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	long long int ans = 0;
	for(int i=1;i<=a/2;i++) ans += 2*x[i]*x[a-i+1];
	for(int i=1;i<=a;i++) ans += x[i]*x[i];
	printf("%lld",ans);
}