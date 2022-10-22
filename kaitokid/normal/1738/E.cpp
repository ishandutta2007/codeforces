#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
int fr[300009][2];
ll a[100009],pr[100009];
ll p[200009],inv[200009];
ll pw(ll x ,ll y)
{
    if(y==0)return 1;
    ll u=pw(x,y/2);
    u=(u*u)%mod;
    if(y%2)u=(u*x)%mod;
    return u;
}
ll c(ll x,ll y)
{
    ll r=(p[x]*inv[y])%mod;
    r=(r*inv[x-y])%mod;
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p[0]=1;
    for(int i=1;i<=200001;i++)p[i]=(p[i-1]*i)%mod;
    inv[200001]=pw(p[200001],mod-2);
    for(int i=200000;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mod;
    int t;
    cin>>t;
    while(t--)
    {
        map<ll,int>mp;
        int n;
        cin>>n;
        for(int i=0;i<3*n;i++)fr[i][0]=fr[i][1]=0;
        for(int i=0;i<n;i++)cin>>a[i];
        pr[0]=a[0];
        for(int i=1;i<n;i++)pr[i]=pr[i-1]+a[i];
        int d=0,gg=0;
        for(int i=0;i<n-1;i++)
        {
            if(pr[i]==pr[n-1]-pr[i]){d++;continue;}
            if(pr[i]<pr[n-1]-pr[i])
            {
                if(mp[pr[i]]==0)mp[pr[i]]=(++gg);
                fr[mp[pr[i]]][0]++;
                continue;
            }
             if(mp[pr[n-1]-pr[i]]==0)mp[pr[n-1]-pr[i]]=(++gg);
            fr[mp[pr[n-1]-pr[i]]][1]++;
        }
        ll res=1;
        for(int i=1;i<3*n;i++)
        {
            ll r=1;
            int u=fr[i][0],v=fr[i][1];
            for(int i=1;i<=min(u,v);i++){r+=c(u,i)*c(v,i);r%=mod;}
            res=(res*r)%mod;
        }
        for(int i=0;i<d;i++)res=(res*2)%mod;
        cout<<res<<endl;
    }
    return 0;
}