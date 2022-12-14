#include <stdio.h>

long long int x[10010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		for(int j=1;j<=b;j++) x[j] = (c+(b-j))/b;
		
		long long int ans = 0;
		for(int j=1;j<=b;j++) ans += x[j]*x[j];
		printf("%lld\n",ans);
	}
}