#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    char s[20];
    scanf("%d%s",&x,s);
    scanf("%s",s);
    if (s[0]=='w')
    {
        if (x==5||x==6) printf("53");
        else printf("52");
    }
    else
    {
        if (x<=29) printf("12");
        else if (x==30) printf("11");
        else printf("7");
    }
    return 0;
}