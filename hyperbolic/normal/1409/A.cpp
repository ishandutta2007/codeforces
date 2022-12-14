#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int c = a>b?a-b:b-a;
		if(c==0) printf("0\n");
		else printf("%d\n",(c-1)/10+1);
	}
}