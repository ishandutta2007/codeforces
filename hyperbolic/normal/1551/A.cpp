#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%3==0) printf("%d %d\n",a/3,a/3);
		else if(a%3==1) printf("%d %d\n",a/3+1,a/3);
		else printf("%d %d\n",a/3,a/3+1);
	}
}