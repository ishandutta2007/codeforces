#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
const ll DIM = 5E5+7;
const ll INF = 1E16;
const ll MOD = 998244353 ;
ll fact[DIM];
ll binpow(ll x,ll power){
    x%=MOD;
    ll base = x;
    x = 1;
    while(power>0){
        if (power&1)x=(x*base)%MOD;
        base = (base*base)%MOD;
        power/=2;
    }
    return x;
}
ll rev(ll x){
    return binpow(x,MOD-2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n,k;
    cin>>n>>k;
    if (k==1){
        cout<<n<<endl;
        return 0;
    }
    ll res = 0;
    fact[0] = 1;
    forn(i,n)fact[i] = (fact[i-1]*i)%MOD;
    forn(i,n){
        if (n/i<k)break;
        ll len = n/i;
        res = (res+(fact[len-1]*rev(fact[len-k]*fact[k-1]))%MOD)%MOD;
    }
    cout<<res<<endl;
    return 0;
}