#include <cstdio>
#include <cstring>

int main()
{
    char table[50]={"qwertyuiopasdfghjkl;zxcvbnm,./"},str[110],req;
    scanf("%c%s",&req,str);
    int t=req=='R'?-1:1,l=strlen(str);
    for (int i=0;i<l;i++) 
    {
        int w;
        for (w=0;;w++) if (table[w]==str[i]) break;
        printf("%c",table[w+t]);
    }
    return 0;
}