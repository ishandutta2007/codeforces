#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
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
set<int> s;
vi a;
int main()
{
    int n;
    sd(n);
    a.resize(n);
    int mx = 0;
    rep(i,0,n)
    sd(a[i]),s.insert(a[i]),mx = max(mx,a[i]);
    sort(all(a));
    ll ans = 0;
    vi vec = a;
    for(int p:s)
    {
        ll ret = 0;
        for(int i = 1;i*p<=mx;i++){
            ret+=i*1ll*(upper_bound(vec.begin(),vec.end(),p*(i+1)-1) - upper_bound(vec.begin(),vec.end(),p*i - 1));
        }
        ans = max(ans,p*ret);
    }
    cout<<ans;
}