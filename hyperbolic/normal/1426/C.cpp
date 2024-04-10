#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int ans = a;
		for(int i=1;i<=70000;i++)
		{
			int s = (i-1) + (a-i-1)/i+1;
			ans = ans<s?ans:s;
		}
		printf("%d\n",ans);
	}
}