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
const ll DIM = 2E5+7;
const ll INF = 1e19;
const ll MOD = 998244353;
ll fact[DIM],n,k;
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
ll rev(ll x){
    return binpow(x,MOD-2);
}
void init(){
    fact[0] = 1;
    forn(i,n){
        fact[i] =(fact[i-1]*i)%MOD;
    }
}
ll C(ll n,ll k){
    return (fact[n]*rev(fact[k]*fact[n-k]))%MOD;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    init();
    ll c = n-k;
    if (c<=0){
        cout<<0<<endl;
        return 0;
    }
    ll res = 0;
    forn(i,c){
        if (i%2==c%2)res=(res+binpow(i,n)*C(c,i))%MOD;
        else{
            ll g = (binpow(i,n)*C(c,i))%MOD;
            res = (res-g)%MOD;
            if (res<0)res+=MOD;
        }
    }
    if (c!=n)
    res = (res*C(n,c)*2)%MOD;
    cout<<res<<endl;
    return 0;
}