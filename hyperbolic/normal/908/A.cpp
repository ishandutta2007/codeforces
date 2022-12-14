#include <stdio.h>
#include <string.h>
char x[110];
int main()
{
	int a,count=0;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='a'||x[i]=='e'||x[i]=='i'||x[i]=='o'||x[i]=='u') count ++;
		if(x[i]=='5'||x[i]=='1'||x[i]=='3'||x[i]=='7'||x[i]=='9') count ++;
	}
	printf("%d",count);
}