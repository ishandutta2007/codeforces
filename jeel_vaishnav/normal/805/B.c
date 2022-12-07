#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
char string[n+1];
int i=0;
while(i<n)
{
string[i++]='a';
if(i<n)
string[i++]='a';
if(i<n)
string[i++]='b';
if(i<n)
string[i++]='b';
}
string[n]='\0';
printf("%s",string);
return 0;
}