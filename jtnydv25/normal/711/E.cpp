#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll powr(ll a, ll b, ll mod)
{
    ll x = 1%mod;
    a %= mod;
    while(b)
    {
        if(b&1)
            x = (x*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return x;
}
ll inv(ll a, ll mod)
{
    return powr(a,mod-2,mod);
}
const int maxn = 1e6+3;
const ll mod = 1e6+3;
ll fact[maxn],invfact[maxn];
ll C(int n,int k)
{
    if(k>n || k <0)
        return 0;
    return (fact[n]*((invfact[k]*invfact[n-k])%mod))%mod;
}
ll mulmod(ll n, ll m, ll md)
{
    ll x = 0;
    while(m)
    {
        if(m&1)
            x = (x+n)%md;
        n = (n+n)%md;
        m>>=1;
    }
    return x;
}
ll powermod(ll a, ll b, ll md)
{
    ll x= 1;
    while(b)
    {
        if(b&1)
        {
            x = mulmod(x,a,md);
        }
        a = mulmod(a,a,md);
        b>>=1;
    }
    return x;
}
ll C2(ll n,ll k)
{   
    if(n<=60)
    {
        if((1LL<<n) < k)
            return 0;
    }
    n = powermod(2,n,mod*mod*mod);
    ll res= 1;
    while(k)
    {
        int a = n%mod,b = k%mod;
        n/=mod;
        k/=mod;
        res = (res*C(a,b))%mod; 
    }
    return res;
}
ll exp2(ll k,ll n)
{
    if(n<=60)
    {
        if((1LL<<n) < k)
            return 0;
    }
    ll res = 0;
    ll p = 2;
    int i = 1;
    while(k>=p && i <= n)
    {
        if(k%p !=0)
            res++;
        p<<=1;
        i++;
    }
    res += n-i+1;
    return res;
}

ll findfact(ll n)
{
    if(n<mod)
        return fact[n];
    return 0;
}
ll findp2(ll n)
{
    n>>=1;
    ll res = 0;
    while(n)
    {
        res+=n;
        n>>=1;
    }
    return res;
}
int main()
{
    ll n,k;
    fact[0] = invfact[0] = 1;
    for(int i = 1;i<maxn;i++)
        fact[i]=(fact[i-1]*i)%mod,invfact[i]=inv(fact[i],mod);
    cin>>n>>k;
    if(n<61)
    {
        if((1LL<<n) < k)
        {
            cout<<1<<" "<<1<<endl;
            return 0;
        }
    }
    ll a = (findfact(k)*C2(n,k))%mod,b = powr(powr(2,n,mod),k,mod);
    ll p2 = exp2(k,n)+findp2(k);
    ll _inv = inv(powr(2,p2,mod),mod);
    a = (a*_inv)%mod;
    b = (b*_inv)%mod;
    a = b-a;
    if(a < 0)
        a+=mod;
    cout<<a<<" "<<b<<endl;
}