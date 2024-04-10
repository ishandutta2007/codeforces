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
const ll DIM = 500009+7;
const ll INF = 1e8;
const ll MOD = 1E9+123;
typedef unsigned long long ull;
typedef pair<ull,ll> upp;
const ll base = DIM;
ll A[DIM];
vector<ll> G[DIM];
upp H[DIM];
map<upp,ll> M;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        forn(i,n){
            cin>>A[i];
        }
        forn(i,m){
            ll x,y;
            cin>>x>>y;
            G[x].pb(y);
        }
        forn(i,n){
            for(ll to:G[i]){
                H[to].fi=H[to].fi+base+i;
                H[to].sc = (H[to].sc*base+i)%MOD;
            }
        }
        forn(i,n){
            if (H[i].fi==H[i].sc && H[i].fi==0)continue;
            M[H[i]]+=A[i];
            H[i].fi=H[i].sc = 0;
        }
        ll g = 0;
        for(pair<upp,ll> to:M){
            g = __gcd(to.sc,g);
        }
        cout<<g<<endl;
        M.clear();
        forn(i,n)G[i].clear();
    }
    return 0;
}