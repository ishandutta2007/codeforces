#include <stdio.h>

int x[50];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b>=2*a)
	{
		printf("YES\n");
		for(int i=1;i<a;i++) printf("1 ");
		printf("%d\n%d",b-(a-1),a);
	}
	else printf("NO");
}