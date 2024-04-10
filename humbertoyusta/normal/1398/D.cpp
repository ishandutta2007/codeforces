    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = 202;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 173, 179, 181, 197, 311, 331, 737, 1009, 2011, 2027, 3079, 4001, 10037, 10079, 20011, 20089;
// 100003, 100019, 100043, 200003, 200017, 1000003, 1000033, 1000037, 1000081;
// 2000003, 2000029, 2000039, 1000000007, 1000000021, 2000000099;
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

int n, m, q, dp[2][maxn][maxn], a[maxn], b[maxn], c[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m >> q;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=m; i++)
        cin >> b[i];
    for(int i=1; i<=q; i++)
        cin >> c[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    sort(c+1,c+q+1);
    reverse(a+1,a+n+1);
    reverse(b+1,b+m+1);
    reverse(c+1,c+q+1);

    int ans = 0;

    for(int i=n; i>=0; i--){
        for(int j=m; j>=0; j--){
            for(int k=q; k>=0; k--){
                if( i && j ){
                    dp[(i+1)%2][j-1][k] = max( dp[(i+1)%2][j-1][k] , dp[i%2][j][k] + a[i] * b[j] );
                }
                if( i && k ){
                    dp[(i+1)%2][j][k-1] = max( dp[(i+1)%2][j][k-1] , dp[i%2][j][k] + a[i] * c[k] );
                }
                if( j && k ){
                    dp[i%2][j-1][k-1] = max( dp[i%2][j-1][k-1] , dp[i%2][j][k] + b[j] * c[k] );
                }
            }
        }
        for(int j=0; j<=m; j++)
            for(int k=0; k<=q; k++){
                ans = max( ans , dp[i%2][j][k] );
                dp[i%2][j][k] = 0;
            }
    }

    cout << ans << '\n';

    return 0;
}