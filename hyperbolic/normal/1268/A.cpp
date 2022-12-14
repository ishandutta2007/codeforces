#include <stdio.h>

char x[200010];
int y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) x[i]-='0';
	for(int i=1;i<=a;i++) y[i] = x[(i-1)%b+1];
	for(int i=1;i<=a;i++)
	{
		if(y[i]>x[i]) goto u;
		else if(y[i]<x[i])
		{
			y[b]++;
			break;
		}
	}
	
	for(int i=b;i>=1;i--)
	{
		if(y[i]>=10)
		{
			y[i-1]++;
			y[i]-=10;
		}
	}
	u:;
	
	for(int i=b+1;i<=a;i++) y[i] = y[i-b];
	
	printf("%d\n",a);
	for(int i=1;i<=a;i++) printf("%d",y[i]);
	return 0;
}