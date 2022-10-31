#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 2*10E4+7;
const ll INF = 10E17;
const ll MOD = 998244353;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll fact[DIM];
ll binpow(ll x,ll power){
    ll mult = x%MOD;
    x = 1;
    while(power>0){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll mx = max(n,m);
    fact[0] = 1;
    forn(i,mx){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    ll cnt = fact[m];
    ll div = (fact[m-n+1]*fact[n-1])%MOD;
    div = binpow(div,MOD-2);
    cnt = (cnt*div)%MOD;
    ll res = 0;
    for(ll i = 2;i<=n-1;++i){
        ll p = (fact[n-2]*cnt)%MOD;
        ll x = i;
        p = (p*(x-1))%MOD;
        div = (fact[x-1]*fact[n-x-1])%MOD;

        div = binpow(div,MOD-2);
        p = (p*div)%MOD;
       // p = (p*cnt)%MOD;
        res = (res+p)%MOD;
    }
    cout<<res<<endl;
    return 0;
}