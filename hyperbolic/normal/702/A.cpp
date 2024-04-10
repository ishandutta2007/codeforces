#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 1;
	int count = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i]>x[i-1]) count++;
		else count = 1;
		ans = ans>count?ans:count;
	}
	printf("%d",ans);
}