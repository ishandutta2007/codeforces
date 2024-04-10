#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==1) printf("0\n");
		else if(a==2) printf("%d\n",b);
		else printf("%d\n",2*b);
	}
}