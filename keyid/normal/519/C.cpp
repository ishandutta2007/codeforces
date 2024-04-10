#include <cstdio>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if (m>=n*2) printf("%d",n);
    else if (n>=m*2) printf("%d",m);
    else printf("%d",(n+m)/3);
    return 0;
}