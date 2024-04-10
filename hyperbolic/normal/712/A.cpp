#include <stdio.h>
int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	y[a]=x[a];
	for(int i=a-1;i>=1;i--) y[i]=x[i]+x[i+1];
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
}