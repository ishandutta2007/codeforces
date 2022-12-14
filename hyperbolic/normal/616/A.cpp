#include <stdio.h>
#include <string.h>
char x[1000010],y[1000010];
char s1[2000010],s2[2000010];
int main()
{
	int a,b,i,j;
	scanf("%s%s",x+1,y+1);
	a = strlen(x+1) , b = strlen(y+1);
	for(i=1;i<=2000000;i++) s1[i]=s2[i]='0';
	for(i=a,j=1;i>=1;i--,j++) s1[j] = x[i];
	for(i=b,j=1;i>=1;i--,j++) s2[j] = y[i];
	for(i=2000000;i>=1;i--)
	{
		if(s1[i]>s2[i])
		{
			printf(">");
			return 0;
		}
		if(s1[i]<s2[i])
		{
			printf("<");
			return 0;
		}
	}
	printf("=");
}