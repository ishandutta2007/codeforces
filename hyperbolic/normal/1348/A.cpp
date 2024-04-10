#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		int b = 0, c = 0;
		for(int i=1;i<(a/2);i++) b += (1<<i);
		b += (1<<a);
		for(int i=(a/2);i<a;i++) c += (1<<i);
		printf("%d\n",b-c);
	}
}