#include <stdio.h>
#include <algorithm>

long long int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) x[i] += x[i-1];
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		printf("%lld\n",x[a-c+d]-x[a-c]);
	}
}