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
const int maxn = 1000010;
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        vector<vector<int>> v(2,vector<int>(2));
        for(int i=0; i<n; i++){
            t[i] = char( '0' + ( s[i] != t[i] ) );
            v[t[i]-'0'][s[i]-'0'] ++;

        }
        int ans = mod;

        if( ( v[0][0] + v[0][1] ) % 2 == 1 ){
            if( v[0][1] == v[0][0] || v[0][1] == v[0][0] + 1 )
                ans = min( ans , v[0][0] + v[0][1] );
        }

        if( ( v[1][0] + v[1][1] ) % 2 == 0 ){
            if( v[1][1] == v[1][0] || v[1][1] == v[1][0] + 1 )
                ans = min( ans , v[1][0] + v[1][1] );
        }

        if( ans == mod )
            ans = -1;

        cout << ans << '\n';
    }

    return 0;
}