#include <stdio.h>

char x[110];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='0')
		{
			printf("%d",count);
			count = 0;
		}
		else count++;
	}
	printf("%d",count);
}