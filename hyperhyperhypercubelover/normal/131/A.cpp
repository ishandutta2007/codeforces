#include<stdio.h>
#include<string.h>

char str[200];

int main()
{
    bool flag=true;;
    int i,n;
    scanf("%s",str);
    n=strlen(str);
    for(i=1;i<n;i++)
    {
        if((str[i]<='z')&&(str[i]>='a'))flag=false;
    }
    if(!flag)puts(str);
    else
    {
        for(i=0;i<n;i++)
        {
            if((str[i]<='z')&&(str[i]>='a'))putchar(str[i]-'a'+'A');
            else putchar(str[i]-'A'+'a');
        }
    }
}