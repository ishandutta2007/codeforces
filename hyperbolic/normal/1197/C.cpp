#include <stdio.h>
#include <algorithm>

int x[300010],y[300010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++) y[i] = x[i]-x[i+1];
	std::sort(y+1,y+a);
	
	long long int ans = x[a]-x[1];
	for(int i=1;i<b;i++) ans += y[i];
	printf("%lld",ans);
}