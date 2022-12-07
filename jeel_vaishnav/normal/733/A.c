#include<stdio.h>
#include<string.h>
int main()
{
char s[101];
scanf("%s",s);
int len=strlen(s),x=0,max=0;
for(int i=0;i<len;i++)
{
	x++;
	if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y')
	{
	if(x>max)
	max=x;
	x=0;
	}
}
x++;
if(x>max)
max=x;
printf("%d",max);
}