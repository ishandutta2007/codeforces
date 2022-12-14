#include <stdio.h>

long long int x[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) x[i] += x[i-1];
	
	long long int ans = 0;
	for(int i=1;b+i-1<=a;i++) ans += x[b+i-1]-x[i-1];
	printf("%.12lf",(double)ans/(a-b+1));
}