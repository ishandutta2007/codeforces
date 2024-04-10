#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;
typedef long long  ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> multi_set;
#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 80+7;
const ll INF = 1e18;
const ll MOD = 998244353;
ll binpow(ll x,ll power){
    x%=MOD;
    ll mult = x;
    x = 1;
    while(power>0){
        if (power&1) x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
ll rev(ll x){
    return binpow(x,MOD-2);
}
ll fact[DIM];
vector<ll> vec;
ll F(ll x){
    vector<pp> V;
    ll sum = 0;
    for(ll i:vec){
        if (i>sqrt(x))break;
        if (x%i!=0)continue;
        ll cnt = 0;
        while(x%i==0){
            x/=i;
            cnt++;
        }
        V.pb({i,cnt});
        sum+=cnt;
    }
    if (x!=1){
        sum++;
        V.pb({x,1});
    }
    ll res = 1;
    ll rres = 1;
    for(pp to:V){
        ll mult = fact[sum];
        rres=((fact[sum-to.sc]*fact[to.sc])%MOD*rres)%MOD;
        sum-=to.sc;
        res = (res*mult)%MOD;
    }
    res = (res*rev(rres))%MOD;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    fact[0] = 1;
    forn(i,DIM-1)fact[i] = (fact[i-1]*i)%MOD;
    ll D;
    cin>>D;
    for(ll i = 2;i<=sqrt(D);++i){
        if (D%i!=0)continue;
        while(D%i==0)D/=i;
        vec.pb(i);
    }
    if (D!=1)vec.pb(D);
    ll q;
    cin>>q;
    while(q--){
        ll a,b;
        cin>>a>>b;
        ll g = __gcd(a,b);
        ll ans = 1;
        ans = (ans*F(a/g))%MOD;
        ans = (ans*F(b/g))%MOD;
        cout<<ans<<endl;
    }
    return 0;
}