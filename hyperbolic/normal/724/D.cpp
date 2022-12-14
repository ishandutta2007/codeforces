#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
struct str{
    char x0;
    int y0;
}ans[100010];
str Str(char a, int b)
{
    str A;
    A.x0 = a;
    A.y0 = b;
    return A;
}
bool operator<(str a, str b)
{
    if(a.x0==b.x0) return a.y0>b.y0;
    return a.x0<b.x0;
}
std::set<str> S;
char x[100010];
int check[100010];
int main()
{
    int a,b;
    scanf("%d%s",&b,x+1);
    a = strlen(x+1);

    for(int i=1;i<=26;i++)
    {
        int k = 1;
        for(int j=1;j<=a;j++)
        {
            if(x[j]==i+'a'-1)
            {
                k = k>j-b+1?k:j-b+1;
                for(;k<=j;k++) if(check[k]==0) check[k] = i;
            }
        }
        for(int j=1;j<=a-b+1;j++)
        {
            if(check[j]==0)
            {
                for(k=1;k<=a;k++) if(x[k]==i+'a'-1) printf("%c",i+'a'-1);
                goto u;
            }
        }
        for(int j=1;j<=a-b+1;j++)
        {
            if(check[j]==i)
            {
                for(int k=j+b-1;;k--)
                {
                    if(x[k]==i+'a'-1)
                    {
                        printf("%c",i+'a'-1);
                        j=k;
                        break;
                    }
                }
            }
        }
        return 0;
        u:;
    }
}