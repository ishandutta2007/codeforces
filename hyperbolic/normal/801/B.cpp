#include <stdio.h>
#include <string.h>
char x[1010],y[1010];
int main()
{
	int a;
	scanf("%s%s",x+1,y+1);
	a = strlen(x+1);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]<y[i])
		{
			printf("-1");
			return 0;
		}
	}
	printf("%s",y+1);
}