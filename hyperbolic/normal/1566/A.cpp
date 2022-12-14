#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int s1,s2;
		if(a%2==0) s1 = a/2 -1, s2 = a/2 + 1;
		else s1 = a/2, s2 = a/2 + 1;
		printf("%d\n",b/s2);
	}
}