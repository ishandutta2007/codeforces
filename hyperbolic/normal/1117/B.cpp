#include <stdio.h>
#include <algorithm>
int x[200010];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	std::sort(x+1,x+a+1);
	
	long long int d = x[a] , e = x[a-1];
	long long int f = b/(c+1);
	long long int g = b%(c+1);
	printf("%lld",f*(c*d+e)+d*g);
}