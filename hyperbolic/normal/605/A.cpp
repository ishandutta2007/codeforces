#include <stdio.h>

int x[100010],check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--)
	{
		if(check[x[i]+1]) check[x[i]] = check[x[i]+1] + 1;
		else check[x[i]] = 1;
	}
	
	int max = 0;
	for(int i=1;i<=a;i++) max = max>check[i]?max:check[i];
	printf("%d",a-max);
}