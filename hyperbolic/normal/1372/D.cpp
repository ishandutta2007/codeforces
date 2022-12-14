#include <stdio.h>

int x[400010];
long long int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a+1;i<=2*a;i++) x[i] = x[i-a];
	
	long long int odd = 0, even = 0;
	for(int i=1;i<=a+1;i+=2) odd += x[i];
	for(int i=2;i<=a+1;i+=2) even += x[i];
	check[1] = odd;
	check[2] = even;
	for(int i=3;i<=a;i++) check[i] = check[i-2] - x[i-2] + x[a+i-1];
	
	long long int ans = 0;
	for(int i=1;i<=a;i++) ans = ans>check[i]?ans:check[i];
	printf("%lld",ans);
}