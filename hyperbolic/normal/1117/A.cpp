#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	int b = x[1];
	for(int i=2;i<=a;i++) b = b>x[i]?b:x[i];
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==b) y[i] = y[i-1]+1;
		else y[i] = 0;
	}
	
	int c = y[1];
	for(int i=1;i<=a;i++) c = c>y[i]?c:y[i];
	printf("%d",c);
}