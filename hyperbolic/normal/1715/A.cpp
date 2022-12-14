#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1&&b==1) printf("0\n");
		else printf("%d\n",a+b+(a<b?a:b)-3 + 1);
	}
}