#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1) printf("1 1\n");
		else if(b==1) printf("1 1\n");
		else printf("2 2\n");
	}
}