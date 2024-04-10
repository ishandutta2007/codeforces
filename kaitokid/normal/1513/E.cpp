#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;

ll a[200009];
ll p[200009];
ll inv[200009];
ll pw(ll a,ll b)
{
    if(b==0)return 1;
    if(b%2)return (a*pw(a,b-1))%mod;
    ll p= pw(a,b/2);
    return (p*p)%mod;
}
ll inn (ll x)
{
    return pw(x,mod-2);
}
ll c(ll x,ll y)
{
    return (((p[x]*inv[y])%mod)*inv[x-y])%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    p[0]=1;
    inv[0]=1;
    for(int i=1;i<=200003;i++)
        {p[i]=(p[i-1]*i)%mod;inv[i]=inn(p[i]);}

    ll sum=0,n,ans=1;
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
    sort(a,a+n);
    ll fr=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1]){ans=(ans*inv[fr])%mod;fr=1;}
        else fr++;
    }
    ans=(ans*inv[fr])%mod;
    if(sum%n){cout<<0<<endl;return 0;}
    sum/=n;
    ll ls=0,gr=0;
    for(int i=0;i<n;i++)
    {if(a[i]<sum)ls++;
    if(a[i]>sum)gr++;}
    if(ls<=1||gr<=1){cout<<(ans*p[n])%mod<<endl;return 0;}
    ans=(ans*p[ls])%mod;
    ans=(ans*p[gr])%mod;
    ans=(ans*p[n-ls-gr])%mod;
    ans=(ans*c(n,n-ls-gr))%mod;
    ans=(2*ans)%mod;
    cout<<ans;



    return 0;
}