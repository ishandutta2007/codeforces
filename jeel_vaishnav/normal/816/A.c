#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[6];
    scanf("%s",s);
    int min=0;
    while(1)
    {
        if(s[1]==s[3]&&s[0]==s[4])
            break;
       min++;
       s[4]++;
       if(s[4]-'9'==1)
       {
           s[4]='0';
           s[3]++;
       }
        if(s[3]=='6')
        {
            s[3]='0';
            s[1]++;
        }
        if(s[1]=='4'&&s[0]=='2')
        {
            s[1]='0';
            s[0]='0';
        }
        else if(s[1]-'9'==1)
        {
            s[1]='0';
            s[0]++;
        }
    }
    printf("%d",min);
}