#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(b+c<=a-2) printf("Yes\n");
		else if(b+c==a-1) printf("No\n");
		else if(b==a&&c==a) printf("Yes\n");
		else printf("No\n");
	}
}