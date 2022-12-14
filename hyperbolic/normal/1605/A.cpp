#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int d = (a+c-2*b);
		d%=3, d+=3, d%=3;
		if(d==0) printf("0\n");
		else printf("1\n");
	}
}