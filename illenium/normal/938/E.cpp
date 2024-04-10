#include<stdio.h>  
#include<algorithm>  
#define mod 1000000007  
using namespace std;

typedef long long ll;  
ll a[1000005];

ll qmi(ll a,ll b)  
{  
    ll ans=1;  
    while(b)  
    {  
        if(b%2)ans=(ans*a)%mod;  
        a=(a*a)%mod;  
        b/=2;  
    }  
    return ans;  
}

int main()  
{  
    ll n;  
    scanf("%lld",&n);  
    ll Ann=1;  
    for(ll i=1;i<=n;i++)  
        Ann=Ann*i%mod;  
    for(ll i=1;i<=n;i++)  
        scanf("%lld",&a[i]);  
    sort(a+1,a+1+n);  
    ll ans=0,now;  
    for(ll i=1;i<=n;i=now)  
    {  
        now=i;  
        while(a[i]==a[now]&&now<=n)now++;  
        if(now<=n)ans=(ans+Ann*qmi(n-i+1,mod-2)%mod*(now-i)%mod*a[i]%mod)%mod;  
    }  
    printf("%lld\n",ans);  
}