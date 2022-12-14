#include <stdio.h>
#include <string.h>
char x[100010];
int main()
{
    int a,i,s,t;
    scanf("%s",x+1);
    a = strlen(x+1);
    s=t=a+1;
    for(i=1;i<=a;i++)
    {
        if(x[i]=='a');
        else
        {
            s = i;
            break;
        }
    }
    for(;i<=a;i++)
    {
        if(x[i]!='a');
        else
        {
            t = i;
            break;
        }
    }
    if(s==a+1)
    {
        for(i=1;i<a;i++) printf("a");
        printf("z");
        return 0;
    }
    for(i=s;i<t;i++) x[i]--;
    for(i=1;i<=a;i++) printf("%c",x[i]);
}