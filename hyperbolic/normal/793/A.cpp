#include <stdio.h>

int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int min = x[1];
	for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if((x[i]-min)%b!=0)
		{
			printf("-1");
			return 0;
		}
		ans += (x[i]-min)/b;
	}
	printf("%lld",ans);
}