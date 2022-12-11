#include <cstdio>
int main()
{
    int n,m,cnt=0;
    scanf("%d%d",&n,&m);
    do
    {
        cnt+=n/m*m;
        n=n/m+n%m;
    }while (n>=m);
    cnt+=n;
    printf("%d",cnt);
    return 0;
}