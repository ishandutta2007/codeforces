    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2") //Enable AVX
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
const int maxn = 3030;
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

int tc, n, k, sz, dp[2][maxn][maxn];
vector<ii> v[maxn], best[maxn];
priority_queue<ii> q;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> sz;
        for(int j=1; j<=sz; j++){
            int u;
            cin >> u;//db(u)
            if( j <= k ){
                v[i].pb({u,0});
                if( j >= 2 ) v[i][j-1].s = v[i][j-2].s + v[i][j-1].f;
                    else v[i][j-1].s = v[i][j-1].f;
                best[j].pb({v[i].back().s,i});//db(v[i][j-1].s)
            }
        }
    }

    for(int i=0; i<2; i++)
        for(int j=0; j<maxn; j++)
            fill( dp[i][j] , dp[i][j] + maxn , -INF );

    dp[0][0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[0][i][j] = dp[0][i-1][j];
            if( j ) dp[0][i][j] = max( dp[0][i][j] , dp[0][i][j-1] );
            if( j - (int)v[i].size() >= 0 )
                dp[0][i][j] = max( dp[0][i][j] , dp[0][i-1][j-(int)v[i].size()] + v[i].back().s );
        }
    }

    dp[1][n+1][0] = 0;
    for(int i=n; i>=1; i--){
        for(int j=0; j<=k; j++){
            dp[1][i][j] = dp[1][i+1][j];
            if( j ) dp[1][i][j] = max( dp[1][i][j] , dp[1][i][j-1] );
            if( j - (int)v[i].size() >= 0 )
                dp[1][i][j] = max( dp[1][i][j] , dp[1][i+1][j-(int)v[i].size()] + v[i].back().s );
        }
    }

    int ans = dp[0][n][k];
    for(int i=1; i<=k; i++){
        sort(all(best[i]));
        reverse(all(best[i]));
        bool need = 1;
        for(int j=0; j<best[i].size(); j++){
            if( !need ) break;
            int res = 0;
            for(int l=0; l<=k-i; l++){
                res = max( res , dp[0][best[i][j].s-1][l] + dp[1][best[i][j].s+1][(k-i)-l] );
            }
            if( res == dp[0][n][k-i] ) need = 0;
            res += best[i][j].f;
            ans = max( ans , res );
        }
    }

    cout << ans << '\n';

    return 0;
}