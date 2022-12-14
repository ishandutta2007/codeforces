#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a<=2)
		{
			printf("2\n");
			printf("1 2\n");
		}
		else
		{
			printf("%d\n",2);
			printf("%d %d\n",a,a-2);
			printf("%d %d\n",a-1,a-1);
			for(int i=a-1;i>=3;i--) printf("%d %d\n",i,i-2);
		}
	}
}