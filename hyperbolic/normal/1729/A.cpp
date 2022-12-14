#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		int s = (a-1);
		int t = abs(b-c) + (c-1);
		if(s<t) printf("1\n");
		else if(s>t) printf("2\n");
		else printf("3\n");
	}
}