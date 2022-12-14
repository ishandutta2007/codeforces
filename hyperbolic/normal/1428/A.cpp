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
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==c) printf("%d\n",abs(b-d));
		else if(b==d) printf("%d\n",abs(a-c));
		else printf("%d\n",abs(b-d)+abs(a-c)+2);
	}
}