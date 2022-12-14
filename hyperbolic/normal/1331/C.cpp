#include <stdio.h>

int x[10],y[10];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=6;i++) x[i] = a%2, a/=2;
	y[5] = x[1], y[2] = x[2], y[4] = x[3];
	y[3] = x[4], y[1] = x[5], y[6] = x[6];
	
	int s = 0;
	for(int i=6;i>=1;i--) s*=2, s+=y[i];
	printf("%d",s);
}