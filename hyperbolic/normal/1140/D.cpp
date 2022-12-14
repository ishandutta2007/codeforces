#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=2;i<=a-1;i++) ans += i*(i+1);
	printf("%d",ans);
}