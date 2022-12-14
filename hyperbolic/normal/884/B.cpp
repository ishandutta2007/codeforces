#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum = a-1;
	for(int i=1;i<=a;i++)
	{
		int c;
		scanf("%d",&c);
		sum += c;
	}
	printf("%s",sum==b?"YES":"NO");
}