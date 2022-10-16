#include<stdio.h>
#include<string.h>
int main()
{
    char m;
    int x;
    char s[100];
    scanf("%s",s);
    m='a';
    x=strlen(s)-1;
    for(int k=0;k<=x;k++)
        if (m<s[k]) m=s[k];
    for(int k=0;k<=x;k++)
        if (m==s[k]) printf("%c",m);
    
    }