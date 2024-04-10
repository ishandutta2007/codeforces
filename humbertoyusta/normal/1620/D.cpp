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
const int maxn = 55050;
const int mod = 1000000007;
const int mod2 = 998244353;
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

int solve(int c1,int c2,vector<int> a){
    int c3 = 0;
    for( auto i : a ){
        int nc3 = mod + mod;
        for(int j=0; j<=c1; j++){
            for(int k=0; k<=c2; k++){
                int ni = i - j * 1 - k * 2;
                if( ni >= 0 && ni % 3 == 0 )
                    nc3 = min( nc3 , ni / 3 );
            }
        }
        c3 = max( c3 , nc3 );//db(nc3)
    }
    return c1 + c2 + c3;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n;
        cin >> n;

        vector<int> a(n);
        for( auto &i : a )
            cin >> i;

        int ans = mod + mod;
        for(int i=0; i<=6; i++){
            for(int j=0; j<=3; j++){
                ans = min( ans , solve(i,j,a) );
            }
        }
        cout << ans << '\n';
    }

    return 0;
}