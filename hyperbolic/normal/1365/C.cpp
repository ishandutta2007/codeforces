#include <stdio.h>

int x[200010],y[200010];
int count[400010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		x[b] = i;
	}
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		y[b] = i;
	}
	
	for(int i=1;i<=a;i++) count[(x[i]-y[i]+a)%a]++;
	
	int ans = 0;
	for(int i=0;i<=a;i++) ans = ans>count[i]?ans:count[i];
	printf("%d",ans);
}