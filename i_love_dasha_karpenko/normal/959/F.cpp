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
//#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 1E5+7;
const ll MOD = 1e9+7;
const ll INF = 2E18;
const ld eps = 0.0000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
vector<pp> Q[DIM];
ll A[DIM],po[DIM],ans[DIM];
const ll LOG = 20;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    po[0] = 1;
    forn(i,DIM-1){
        po[i] = (po[i-1]*2)%MOD;
    }
    ll n,q;
    cin>>n>>q;
    forn(i,n){
        cin>>A[i];
    }
    forn(i,q){
        ll pos,num;
        cin>>pos>>num;
        Q[pos].pb({num,i});
    }
    vector<ll> base(LOG);
    for(ll i = 0;i<LOG;++i)base[i] = 0;
    ll sz = 0;
    forn(pos,n){
        ll x = A[pos];
        for(ll i = 0;i<LOG;++i){
            if (((x>>i)&1)==0)continue;
            if (!base[i]){
                base[i] = x;
                ++sz;
                break;
            }
            x^=base[i];
        }
        for(pp to:Q[pos]){
            x = to.fi;
            ll flag = 0;
            for(ll i = 0;i<LOG;++i){
                if (((x>>i)&1)==0)continue;
                if (!base[i]){
                    flag = 1;
                    break;
                }
                x^=base[i];
            }
            if (flag)ans[to.sc] = 0;
            else ans[to.sc] = po[pos-sz];
        }


    }
    forn(i,q)cout<<ans[i]<<endl;
    return 0;
}
// (i-1)%p
// l = A[i],r = A[i+1]
// 001011
// 001110
// 011010
// 110010
// 1110
// 11 - 8 11-8+1-3 = 1
// 11 10 8
// 1001100
// 4,3,2,6,