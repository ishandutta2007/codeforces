#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int sum = 0;
		for(int j=1;j<=b;j++) sum += j;
		for(int i=2;i<=a;i++) sum += (b*(i-1)+b);
		printf("%lld\n",sum);
	}
}