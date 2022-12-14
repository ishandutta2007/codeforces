#include <stdio.h>

int x[100010];
int check[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int s = 1;
	long long int sum = 0;
	
	int max = x[a]+2;
	for(int i=a;i>=1;i--)
	{
		max--;
		max = max>x[i]+1?max:x[i]+1;
		check[i] = max;
	}
	for(int i=1;i<=a;i++) check[i] = check[i]>check[i-1]?check[i]:check[i-1];
	//for(int i=1;i<=a;i++) printf("%d ",check[i]);
	//printf("\n");
	for(int i=1;i<=a;i++)
	{
		sum += (check[i]-x[i]-1);
	}
	printf("%I64d",sum);
}