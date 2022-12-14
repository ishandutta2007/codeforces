#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a%2==0) printf("%d\n",(b-1)%a+1);
		else
		{
			int c = (a-1)/2;
			int s = (b-1)/c;
			printf("%d\n",(b-1+s)%a+1);
		}
	}
}