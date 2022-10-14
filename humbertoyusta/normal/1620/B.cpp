#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
typedef long double ld;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000030;
const int modd = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * modd * modd;
const double eps = 1e-9;
// Quick Functions------------------------------------------
__int128 qpow(__int128 b,ll e,ll mod){
    if( !e ) return 1ll;
    if( e & 1ll ) return qpow(b,e-1ll,mod) * b % mod;
    __int128 pwur = qpow(b,e>>1ll,mod);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        ll w, h;
        cin >> w >> h;
        ll ans = 0;
        for(int i=0; i<4; i++){
            vector<ll> v;
            int k;
            cin >> k;
            for(int i=0; i<k; i++){
                int u;
                cin >> u;
                v.push_back(u);
            }
            if( i < 2 ) ans = max( ans , ( v[v.size()-1] - v[0] ) * h );
                else ans = max( ans , ( v[v.size()-1] - v[0] ) * w );
        }
        cout << ans << '\n';
    }

    return 0;
}