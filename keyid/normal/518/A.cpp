#include <cstdio>
#include <cstring>

const int MAXL=105;

int main()
{
    char s[MAXL],t[MAXL];
    scanf("%s%s",s,t);
    int l=strlen(s);
    for (int i=l-1;i>=0;i--)
        if (s[i]!='z')
        {
            s[i]++;
            for (int j=i+1;j<l;j++) s[j]='a';
            break;
        }
    if (strcmp(s,t)) printf("%s",s);else printf("No such string");
    return 0;
}