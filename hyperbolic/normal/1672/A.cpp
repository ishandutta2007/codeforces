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
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			ans += (b-1);
		}
		printf("%s\n",ans%2==1?"errorgorn":"maomao90");
	}
}