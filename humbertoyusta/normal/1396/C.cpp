    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
/// Macros:
#define int long long
#define f first
#define s second
#define db(x) cerr << #x << ": " << (x) << '\n';
#define pb push_back
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/// Functions:
#define lg2(x) 31 - __builtin_clz(x)
#define lgx(x,b) ( log(x) / log(b) )
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Pow------------------------------------------------
int qpow(int b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, dp[maxn], app[maxn], pmin, a[maxn], b[maxn], sa[maxn], sb[maxn], arr[maxn], r1, r2, r3, d;
int dp2[maxn], app2[maxn], smin, ans, isa[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> r1 >> r2 >> r3 >> d;

    for(int i=1; i<=n; i++){
        cin >> arr[i];
        b[i] = r1 * arr[i] + r3;
        a[i] = min( r2 + r1 , r1 * ( arr[i] + 2 ) );
        if( a[i] > b[i] ) a[i] = b[i];
        sa[i] = sa[i-1] + a[i];
        sb[i] = sb[i-1] + b[i];
    }

    for(int i=1; i<=n; i++)
        dp[i] = INF;
    dp[0] = 0;
    app[0] = 0;
    pmin = INF;

    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1] + b[i];
        dp[i] = min( dp[i] , pmin + sa[i] + ( i - 1 ) * 2ll * d );
        app[i] = dp[i] - sa[i] - i * 2ll * d;
        pmin = min( pmin , app[i-1] );
    }

    for(int i=n; i>=1; i--)
        isa[i] = isa[i+1] + a[i];

    for(int i=1; i<=n; i++)
        dp2[i] = INF;
    dp2[n+1] = 0;
    app2[n+1] = dp2[n+1] - isa[n+1] + n * 2ll * d;
    smin = INF;

    for(int i=n; i>=1; i--){
        dp2[i] = dp2[i+1] + b[i];
        dp2[i] = min( dp2[i] , smin + isa[i] - ( i ) * 2ll * d );
        app2[i] = dp2[i] - isa[i] + ( i - 1 ) * 2ll * d;
        smin = min( smin , app2[i+1] );
    }

    ans = dp[n] + ( n - 1 ) * d;
    for(int i=1; i<=n; i++)
        ans = min( ans , dp[i-1] + dp2[i] + ( i - 1 ) * d + ( n - i ) * d );

    for(int i=1; i<=n; i++){
        ans = min( ans , dp[i-1] + ( i - 1 ) * d + 2ll * d * ( n - i ) + b[n] + sa[n-1] - sa[i-1] );
    }

    cout << ans << '\n';

    return 0;
}