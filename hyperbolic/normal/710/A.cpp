#include <stdio.h>

char x[10];
int main()
{
	scanf("%s",x+1);
	if(x[1]=='a'||x[1]=='h')
	{
		if(x[2]=='1'||x[2]=='8') printf("3\n");
		else printf("5\n");
	}
	else if(x[2]=='1'||x[2]=='8') printf("5\n");
	else printf("8\n");
}