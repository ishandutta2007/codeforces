#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans = 12345;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		if(b%c==0) ans = ans<b/c?ans:b/c;
	}
	printf("%d",ans);
}