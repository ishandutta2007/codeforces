#include <cstdio>

int main()
{
    long long x,ans=0,i;
    scanf("%I64d",&x);
    for (i=1;x>=10;i*=10)
    {
        int t=x%10;
        ans+=i*(t>=5?9-t:t);
        x/=10;
    }
    if (x<9) ans+=i*(x>=5?9-x:x);else ans+=i*x;
    printf("%I64d",ans);
    return 0;
}