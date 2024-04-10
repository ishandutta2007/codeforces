#include <cstdio>
const int MOD=1000000007;

int main()
{
    long long a,b,ans=0;
    scanf("%I64d%I64d",&a,&b);
    for (long long i=1;i<b;i++)
    {
        long long t1=b*((1+a)*a/2%MOD*i%MOD)%MOD,t2=i*a%MOD;
        ans=(ans+t1+t2)%MOD;
    }
    printf("%I64d",ans);
    return 0;
}