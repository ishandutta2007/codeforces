#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 200010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ll INF = 1ll * mod * mod;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    ll pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

int cnt[maxn][20];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=1; i<maxn; i++){
        for(int j=0; j<20; j++){
            cnt[i][j] = cnt[i-1][j] + ( ( i & (1<<j) ) > 0 );
        }
    }

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i=0; i<20; i++){
            ans = max( ans , cnt[r][i] - cnt[l-1][i] );
        }
        cout << ( r - l + 1 ) - ans << '\n';
    }

    return 0;
}