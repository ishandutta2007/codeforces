#include <stdio.h>
int x[10010];
int t= 1;
int main()
{
	for(int i=1;i<10;i++)
	{
		int s = i;
		x[t] = s%10;
		t++;
	}
	
	for(int i=10;i<100;i++)
	{
		int s = i;
		x[t] = s/10;
		x[t+1] = s%10;
		t+=2;
	}
	
	for(int i=100;i<1000;i++)
	{
		int s = i;
		x[t] = s/100;
		x[t+1] = (s/10)%10;
		x[t+2] = s%10;
		t+=3;
	}
	int a;
	scanf("%d",&a);
	
	printf("%d",x[a]);
}