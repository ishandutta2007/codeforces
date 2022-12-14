#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if((a+b)%2==1) printf("-1\n");
		else if(a==b)
		{
			if(a==0) printf("0\n");
			else printf("1\n");
		}
		else printf("2\n");
		
	}
}