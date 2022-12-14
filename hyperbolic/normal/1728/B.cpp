#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==0)
		{
			for(int i=1;i<a/2;i++) printf("%d %d ",2*i,2*i-1);
			printf("%d %d\n",a-1,a);
		}
		else
		{
			printf("1 2 3 ");
			for(int i=2;i<a/2;i++) printf("%d %d ",2*i+1,2*i);
			printf("%d %d\n",a-1,a);
		}
	}
}