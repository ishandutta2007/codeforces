#include <cstdio>

typedef long long LL;

int main()
{
    int n;
    LL k,fib[55]={1,1};
    scanf("%d%I64d",&n,&k);
    for (int i=2;i<=n;i++) fib[i]=fib[i-1]+fib[i-2];
    for (int i=1;i<=n;i++)
    {
        if (k<=fib[n-i]) printf("%d ",i);
        else
        {
            printf("%d %d ",i+1,i);
            k-=fib[n-i];
            i++;
        }
    }
    return 0;
}