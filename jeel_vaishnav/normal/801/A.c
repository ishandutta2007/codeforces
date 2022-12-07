#include<stdio.h>
#include<string.h>
int main()
{
char s[101];
scanf("%s",s);
int len=strlen(s),chance=0,count=0;
for(int i=1;i<len;i++)
{
if(s[i]=='K'&&s[i-1]=='V')
count++;
else if(s[i]=='V'&&s[i-1]=='V'&&s[i+1]!='K'&&chance==0)
{
chance++;
count++;
}
else if(s[i]=='K'&&s[i-1]=='K'&&s[i-2]!='V'&&chance==0)
{
chance++;
count++;
}
}
    printf("%d",count);
}