#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a==1) printf("-1\n");
		else
		{
			for(int i=1;i<a;i++) printf("3");
			printf("4\n");
		}
	}
}