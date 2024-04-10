#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int ans = 0;
		while(a)
		{
			int b = a%10;
			ans = ans>b?ans:b;
			a/=10;
		}
		printf("%d\n",ans);
	}
}