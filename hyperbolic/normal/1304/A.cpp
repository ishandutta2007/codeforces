#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c,d,e;
		scanf("%d%d%d%d",&b,&c,&d,&e);
		if((c-b)%(d+e)==0) printf("%d\n",(c-b)/(d+e));
		else printf("-1\n");
	}
}