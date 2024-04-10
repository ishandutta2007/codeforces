#include<cstdio>
using namespace std;
int n;
long long f[4000005],sum1[4000005],sum2[4000005],m;
int main()
{
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        sum2[i]=(sum2[i]+sum2[i-1])%m;
        f[i]=(sum1[i-1]+sum2[i])%m;
        if(i==1) f[i]=1;
        sum1[i]=(sum1[i-1]+f[i])%m;
        for(int j=2;j*i<=n;j++)
        {
            sum2[i*j]=(sum2[i*j]+f[i]-f[i-1]+m)%m;
        }
    }
    printf("%lld\n",f[n]);
}