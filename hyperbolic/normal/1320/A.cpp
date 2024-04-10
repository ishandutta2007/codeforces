#include <stdio.h>

int x[200010];
long long int check[600010],check2[600010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		check[x[i]-i+200000]++;
		check2[x[i]-i+200000] += i;
	}
	
	long long int ans = 0;
	for(int i=0;i<=600000;i++)
	{
		long long int s = (long long int)check[i]*(i-200000) + check2[i];
		ans = ans>s?ans:s;
	}
	printf("%lld",ans);
}