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
//#define int long long
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
const int maxn = 88;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll + mod + mod;
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

int dp[2][maxn*maxn][maxn][maxn], a[maxn], one[maxn], zero[maxn], n, c1, c0, cnt[2][maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( a[i] == 0 ){ c0++; zero[c0] = i; }
            else{ c1++; one[c1] = i; }
        cnt[0][i] = cnt[0][i-1] + ( a[i] == 0 );
        cnt[1][i] = cnt[1][i-1] + ( a[i] == 1 );
    }

    for(int i=0; i<=n*n; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=n; k++){
                dp[0][i][j][k] = -mod;
            }
        }
    }
    dp[0][0][0][0] = 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=min(i*n,n*(n+1)/2); j++)
            for(int k=0; k<=n; k++)
                for(int l=0; l<=n; l++)
                    dp[i&1][j][k][l] = -mod;
        for(int j=0; j<=min(i*n,n*(n+1)/2); j++){
            for(int k=0; k<i; k++){
                for(int l=0; l<=k; l++){
                    int z0 = k;
                    int z1 = i - 1 - k;
                    /// case 0:
                    if( cnt[0][n] >= z0 + 1 ){
                        int id = zero[z0+1];
                        int cost = max( 0 , cnt[1][id] - z1 );
                        dp[i&1][j+cost][k+1][l+1] = max( dp[i&1][j+cost][k+1][l+1] , dp[(i+1)&1][j][k][l] );
                    }
                    /// case 1:
                    if( cnt[1][n] >= z1 + 1 ){
                        int id = one[z1+1];
                        int cost = max( 0 , cnt[0][id] - z0 );
                        dp[i&1][j+cost][k][0] = max( dp[i&1][j+cost][k][0] , dp[(i+1)&1][j][k][l] + l * ( cnt[0][n] - k ) );
                    //if( i == 2 && j == 0 && k == 1 && l == 1 ){
                    //    db(dp[i&1][j][k][l])
                    //}
                    }
                }
            }
        }
    }

    int prev = 0;
    for(int i=0; i<=(n)*(n-1)/2; i++){
        int res = 0;
        for(int j=0; j<=n; j++){
            for(int k=0; k<=j; k++){
                res = max( res , dp[n&1][i][j][k] );
            }
        }
        res = max( res , prev );
        cout << res << ' ';
        prev = res;
    }
    cout << '\n';

    return 0;
 }