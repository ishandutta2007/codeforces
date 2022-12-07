#include<stdio.h>
#include<string.h>
int main()
{
char s[101],check[6]="hello";
scanf("%s",s);
int len=strlen(s),x=0;
for(int i=0;i<len;i++)
{
if(s[i]==check[x])
x++;
}
if(x==5)
printf("YES");
else
printf("NO");
}