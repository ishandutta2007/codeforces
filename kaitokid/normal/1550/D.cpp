#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll p[400009],inv[400009];
ll pw(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2)return (x*pw(x,y-1))%mod;
    ll q=pw(x,y/2);
    return (q*q)%mod;
}
ll inn(ll x)
{
    return pw(x,mod-2);
}
ll c(ll x,ll y)
{
    if(x<0||y<0)return 0;
    if(y>x)return 0;
    ll ans=p[x];
    ans=(ans*inv[y])%mod;
    ans=(ans*inv[x-y])%mod;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p[0]=inv[0]=1;
    for(ll i=1;i<200002;i++)
    {
        p[i]=(p[i-1]*i)%mod;
        inv[i]=inn(p[i]);
    }
    int t;
    cin>>t;
    while(t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        ll ans=c(n,n/2);

        ans*=min(abs(l-1),abs(r-n));
        ans%=mod;
        if(n%2)ans*=2;
        ans%=mod;
        ll u=min(abs(l-1),abs(r-n)),v=max(abs(l-1),abs(r-n));
        ll d=n,w1=0,w2=0,st=1,en=n;
        for(ll i=u+1;i<=u+n-1;i++)
        {
            if(en<st)break;
            if(i+st>r||i+st<l||(-i+st)>r||(-i+st)<l){st++,w1++;}
            if(i+en>r||i+en<l||(-i+en)>r||(-i+en)<l){en--;w2++;}
            ll rs=c(n-w1-w2,n/2-w1);
            if(n%2)rs+=c(n-w1-w2,((n+1)/2)-w1);
            rs%=mod;
            ans+=rs;
            ans%=mod;

        }
        cout<<ans<<endl;

    }
return 0;
}