#include <cstdio>?

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",(n&1)?0:(n-1)/4);
    return 0;
}