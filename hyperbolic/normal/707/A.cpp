#include <stdio.h>
char x[10];
int main()
{
	int a,b;
	scanf("%d %d\n",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			scanf("%s",x+1);
			if(x[1]=='C'||x[1]=='M'||x[1]=='Y')
			{
				printf("#Color");
				return 0;
			}
		}
	}
	printf("#Black&White");
}