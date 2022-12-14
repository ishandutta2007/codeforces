#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1)
		{
			printf("2\n");
			continue;
		}
		
		int b = a/3, c = a%3;
		if(c==0) printf("%d\n",b);
		else if(c==1) printf("%d\n",b+1);
		else if(c==2) printf("%d\n",b+1);
	}
}