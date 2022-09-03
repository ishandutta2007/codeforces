#include<stdio.h>
#include<string.h>

char str[200];

int main()
{
    int n;
    scanf("%*d");
    while(~scanf("%s",str))
    {
        n=strlen(str);
        if(n>10)printf("%c%d%c\n",str[0],n-2,str[n-1]);
        else puts(str);
    }
}