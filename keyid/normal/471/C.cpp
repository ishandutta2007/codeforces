#include <cstdio>
#include <cmath>

int main()
{
    long long n;
    scanf("%I64d",&n);
    int h=sqrt(n)*2,ans=0;
    for (long long i=1;i<=h;i++) 
    {
        long long t=n+i-(1+i)*i/2*3;
        if (t<0) break;
        else if (!(t%3)) ans++;
    }
    printf("%d",ans);
    return 0;
}