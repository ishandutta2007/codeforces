#include<stdio.h>

int main()
{
    char t;
    while(~(t=getchar()))
    {
        if(((t<'a')||(t>'z'))&&((t<'A')||(t>'Z')))continue;
        if(t<'a')t+='a'-'A';
        if((t=='a')||(t=='e')||(t=='i')||(t=='o')||(t=='u')||(t=='y'))continue;
        printf(".%c",t);
    }
}