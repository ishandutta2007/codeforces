#include <cstdio>

int main()
{
    int c[200],wh=0,bl=0;
    c['q']=9;c['r']=5;c['b']=3;c['n']=3;c['p']=1;c['k']=0;
    for (int j=0;j<8;j++)
    {
        char s[10];
        scanf("%s",s);
        for (int i=0;i<8;i++)
            if (s[i]!='.')
                if (s[i]>='a') bl+=c[s[i]];
                else wh+=c[s[i]+32];
    }
    if (wh>bl) printf("White");
    else if (bl>wh) printf("Black");
    else printf("Draw");
    return 0;
}