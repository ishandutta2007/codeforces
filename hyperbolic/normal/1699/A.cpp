#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==1) printf("-1\n");
		else
		{
			printf("%d %d %d\n",0,0,a/2);
		}
	}
}