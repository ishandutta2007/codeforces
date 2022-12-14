#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		if(a%3==1)
		{
			if(a>=7) printf("%d 0 1\n",(a-7)/3);
			else printf("-1\n");
		}
		else if(a%3==2)
		{
			if(a>=5) printf("%d 1 0\n",(a-5)/3);
			else printf("-1\n");
		}
		else printf("%d 0 0\n",a/3);
	}
}