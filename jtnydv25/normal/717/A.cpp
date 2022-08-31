#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

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

const int maxn = 1e6+10;
const ll mod = 1e9+7;

struct num
{
    ll x,y;
    num(){}
    num(ll _x, ll _y){x = _x,y = _y;}
    num operator + (num a) {return num((x+a.x)%mod,(y+a.y)%mod);}
    num operator - (num a) {return num((x-a.x+mod)%mod,(y-a.y+mod)%mod);}
    num operator *(num  a) { return num(((x*a.x)%mod+5*((y*a.y)%mod))%mod,((x*a.y)%mod+(y*a.x)%mod)%mod);}
    num operator / (num  b)
    {
        num a = (*this);
        num c = num(b.x,(mod-b.y)%mod);
        num d = a*c;
        ll _inv = inv((b*c).x,mod);
        d.x = (d.x*_inv)%mod;
        d.y = (d.y*_inv)%mod;
        return d;
    }
    num powr(ll n)
    {
        num a = num(1,0),b = (*this);
        while(n)
        {
            if(n&1)
                a = a*b;
            b = b*b;
            n>>=1;
        }
        return a;
    }
    num gp(ll n)// (a^(n+1)-1)/(a-1)
    {
        if(x==1 && y== 0)
            return num((n+1)%mod,0);
        num p = num(1,0);
        return (powr(n+1)-p)/((*this)-p);
    }
    void _print()
    {
        cerr<<"("<<x<<","<<y<<")\n";
    }
};
num phi,iphi,sq5;
ll fib(ll n)
{
    return ((phi.powr(n) - iphi.powr(n))/sq5).x;
}

const int N = 205;
ll C[N][N],s[N][N],fact[N];
    
ll fibpowsum(ll n, int k)
{
    num ret = num(0,0);
    num den = sq5.powr(k);
    for(int r = 0;r<=k;r++)
    {
        ll mul = C[k][r];
        if(r&1) mul=mod-mul;
        num NUM = iphi.powr(r)*phi.powr(k-r);
        NUM = NUM.gp(n);
        ret = ret + num((NUM.x*mul)%mod,(NUM.y*mul)%mod);
    }
    ret = ret/den;
    return ret.x;
}
ll fibonacci[maxn];
ll brutefibsum(ll n, int k)
{
    ll ret = 0;
    for(int i = 0;i<=n;i++)
        ret = (ret+powr(fibonacci[i],k,mod))%mod;
    return ret;
}

int main()
{
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for(int i = 2;i<maxn;i++)
        fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%mod;
    phi = num(inv(2,mod),inv(2,mod));
    iphi = num(phi.x,mod-phi.y);
    sq5 = num(0,1);
    fact[0] = 1;
    for(int i = 1;i<N;i++) fact[i] = (fact[i-1]*i)%mod;
    for(int i = 0;i<N;i++)
    {
        C[i][0] = 1;
        s[i][0] = 0;
        s[0][0] = 1;
        rep(j,1,i+1)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%mod,s[i][j] = ((s[i-1][j-1]-(i-1)*s[i-1][j])%mod+mod)%mod;
    }
    ll a, b, k;
    cin>>k>>a>>b;
    ll ans1 = 0;
    for(int i = 1;i<=k;i++){
        ans1 = (ans1 + s[k][i]*(fibpowsum(b+2,i)-fibpowsum(a+1,i)))%mod;
    }
    ans1 = (ans1+mod)%mod;
    ans1 = (ans1*inv(fact[k],mod))%mod;
    cout<<ans1;
}