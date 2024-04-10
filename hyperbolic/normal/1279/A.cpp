#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b+c+1) printf("No\n");
		else if(b>a+c+1) printf("No\n");
		else if(c>a+b+1) printf("No\n");
		else printf("Yes\n");
	}
}