#include <stdio.h>

int x[100010];
int check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		check[b] = a-i+1;
	}
	
	int count = 0;
	int max = 0;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=a;i>=1;i--)
	{
		int b = x[i];
		if(max>check[b]) count++;
		max = max>check[b]?max:check[b];
	}
	printf("%d",count);
}