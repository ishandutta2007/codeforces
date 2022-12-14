#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a<b)
		{
			if(a+c<=b) printf("0\n");
			else
			{
				c -= (b-a);
				a = b;
				printf("%d\n",(c+1)/2);
			}
		}
		else
		{
			if(b+c<a) printf("%d\n",c+1);
			else
			{
				c -= (a-b);
				printf("%d\n",(a-b)+(c+1)/2);
			}
		}
	}
}