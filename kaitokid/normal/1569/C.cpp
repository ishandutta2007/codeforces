#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll p[200009], inn[200009];
int a[200009];
ll c(ll x,ll y)
{
    ll res=(p[x]*inn[y])%mod;
    res=(res*inn[x-y])%mod;
    return res;
}
ll pw(ll a,ll b)
{
    if(b==0)
        return 1;
    ll g=pw(a,b/2);
    g=(g*g)%mod;
    if(b%2)g=(g*a)%mod;
    return g;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p[0]=1;
    for(int i=1;i<=200002;i++)
        p[i]=(p[i-1]*i)%mod;
    inn[200001]=pw(p[200001],mod-2);
    for(int i=200000;i>=0;i--)
        inn[i]=(inn[i+1]*(i+1))%mod;
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    if(a[n-1]>a[n-2]+1){cout<<0<<endl;continue;}
    if(a[n-1]==a[n-2]){cout<<p[n]<<endl;continue;}
    int fr=1,i=n-3;
    while(i>=0 && a[i]==a[n-2]){fr++;i--;}
    ll ans=(p[fr]*fr)%mod;
    ans*=p[n-fr-1];
    ans%=mod;
    fr++;
    ans*=c(n,fr);
    ans%=mod;
    cout<<ans<<endl;


}

    return 0;
}