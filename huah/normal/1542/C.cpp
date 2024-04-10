#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int N=2e5+5,mod=1e9+7;
ll n;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll sum=1,m=n,ans=0;
        for(ll i=2;sum<=n;i++)
        {
            ll nsum=sum/__gcd(i,sum)*i;
            ans=(ans+(n/sum-n/nsum)%mod*i%mod)%mod;
            sum=nsum;
        }
        printf("%lld\n",ans);
    }
}