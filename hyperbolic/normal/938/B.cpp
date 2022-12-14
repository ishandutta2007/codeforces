#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		int m = b-1<1000000-b?b-1:1000000-b;
		ans = ans>m?ans:m;
	}
	printf("%d",ans);
}