#include <stdio.h>

int x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int count = 0;
	for(int i=2;i<=a-1;i++)
	{
		if(x[i]>x[i-1]&&x[i]>x[i+1]) count++;
		if(x[i]<x[i-1]&&x[i]<x[i+1]) count++;
	}
	printf("%d",count);
}