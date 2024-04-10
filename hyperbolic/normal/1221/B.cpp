#include <stdio.h>

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			printf("%s",(i+j)%2==0?"W":"B");
		}
		printf("\n");
	}
}