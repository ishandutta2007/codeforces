#include <stdio.h>
#include <string.h>
char x[100010];
int main()
{
	int a;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++) printf("%c",x[i]);
	for(int i=a;i>=1;i--) printf("%c",x[i]);
}