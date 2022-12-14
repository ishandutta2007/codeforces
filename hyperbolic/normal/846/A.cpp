#include <stdio.h>

int x[110];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 0;
	for(int i=0;i<=a;i++)
	{
		int count = 0;
		for(int j=1;j<=i;j++) if(x[j]==0) count++;
		for(int j=i+1;j<=a;j++) if(x[j]==1) count++;
		ans = ans>count?ans:count;
	}
	printf("%d",ans);
}