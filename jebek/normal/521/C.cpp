#include <iostream>
#include<algorithm>

using namespace std;

const int MOD=1000000007;
typedef long long ll;
ll n,k,f[200000],p[200000],p1[200000],ans,sum;
char c[200000];

ll pow1(ll a,ll b)
{
    ll c=1;
    while(b)
    {
        if(b%2)
            c=(c*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return c;
}

int main()
{
    cin>>n>>k;
    f[0]=1;
    for(int i=1;i<=n;i++)
        f[i]=(f[i-1]*10)%MOD;
    for(int i=0;i<n;i++)
        cin>>c[i];
    p[k-1]=1;
    for(int i=k;i<=n;i++)
        p[i]=(((p[i-1]*i)%MOD)*pow1(i-k+1,MOD-2))%MOD;
    p1[k]=1;
    for(int i=k+1;i<=n;i++)
        p1[i]=(((p1[i-1]*i)%MOD)*pow1(i-k,MOD-2))%MOD;
    for(int i=n-2;i>-1;i--)
    {
        if(i+1>=k)
            sum=(sum+p[i]*f[n-i-2])%MOD;
        ans=(ans+sum*int(c[i]-'0'))%MOD;
    }
    for(int i=n-1;i>=k;i--)
        ans=(ans+(int(c[i]-'0'))*p1[i]*f[n-i-1])%MOD;
    cout<<ans<<endl;
}