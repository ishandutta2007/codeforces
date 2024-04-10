#include<cstdio>
using namespace std;
const long long mod = 998244353;
int n,t;
long long a[100005],f[100005],ans,Now;
long long Upper(long long x,long long y)
{
    if(x%y==0) return x/y;
    else return x/y+1;
}
long long Lower(long long x,long long y)
{
    return x/y;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=Now=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            for(int j=i-1;j>=1;j--)
            {
                if(Upper(a[j],f[j]+1)<=Lower(a[j+1],f[j+1]+1)) break;
                long long delta=(Upper(a[j],Lower(a[j+1],f[j+1]+1))-1)-f[j];
                f[j]=Upper(a[j],Lower(a[j+1],f[j+1]+1))-1;
                Now=(Now+delta*j)%mod;
//                printf("modify %lld %lld -> %lld\n",i,j,f[j]+1);
            }
            ans=(ans+Now)%mod;
        }
        printf("%lld\n",ans);
    }
}