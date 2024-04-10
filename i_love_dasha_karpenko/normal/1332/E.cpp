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
const ll DIM = 2E5+7;
const ll INF = 10E7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;
//
ll binpow(ll x,ll power){
    if (power<0)return 0;
    x%=MOD;
    ll mult = x;
    x = 1;
    while(power>0){
        if (power&1)x = (x*mult)%MOD;
        mult = (mult*mult)%MOD;
        power/=2;
    }
    return x;
}
int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,l,r;
    cin>>n>>m>>l>>r;
    ll cnt = r-l+1;
    ll sz = (n*m);
    if ((m*n)%2!=0){
        ll res = binpow(cnt,n*m);
    cout<<res<<endl;
        return 0;
    }
    ll res = binpow(cnt,n*m);
    if (cnt%2!=0)
    res++;
    res*=binpow(2,MOD-2);
    res%=MOD;
    cout<<res<<endl;
    return 0;
}