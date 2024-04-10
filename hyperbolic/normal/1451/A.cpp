#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("0\n");
		else if(a==2) printf("1\n");
		else if(a==3) printf("2\n");
		else if(a%2==0) printf("2\n");
		else printf("3\n");
	}
}