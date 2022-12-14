#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a>=1900) printf("Division 1\n");
		else if(a>=1600) printf("Division 2\n");
		else if(a>=1400) printf("Division 3\n");
		else printf("Division 4\n");
	}
}