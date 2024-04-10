    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
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
const int maxn = 200010;
const int maxm = 10000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1 * mod;
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
    if( e & 1 ) return qpow(b,e-1) * b;
    int pwur = qpow(b,e>>1);
    return pwur * pwur;
}
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int tc, n, k, a[maxn], pr[maxm], cnt[maxm], f[maxm], prv[maxn][21], dp[maxn][21];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=1; i<maxm; i++)
        pr[i] = i, cnt[i] = 1;

    for(int i=2; i*i<maxm; i++){
        if( pr[i] == i ){
            for(int j=i*i; j<maxm; j+=i){
                if( pr[j] > i ){
                    pr[j] = i;
                    if( pr[j/i] == pr[j] ) cnt[j] = cnt[j/i] + 1;
                        else cnt[j] = 1;
                }
            }
        }
    }

    cin >> tc;
    while( tc-- ){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            int u;
            cin >> u;
            int v = 1;
            while( u > 1 ){
                if( cnt[u] % 2 )v *= pr[u];
                u /= qpow(pr[u],cnt[u]);
            }
            a[i] = v;
            //cout << a[i] << ' ';
        }//cout << '\n';
        for(int i=0; i<=k; i++){//db(i)
            int r = 1, curr = 0;
            f[a[1]]++;
            prv[1][i] = 1;
            for(int l=1; l<=n; l++){
                //db(l)db(r)db(f[a[r+1]])db(curr)
                while( r + 1 <= n && curr + ( f[a[r+1]] > 0 ) <= i ){
                    r++;
                    curr += ( f[a[r]] > 0 );
                    f[a[r]]++;
                    prv[r][i] = l;
                    //db(prv[r][i])
                }
                curr -= ( f[a[l]] >= 2 );
                f[a[l]]--;
            }
        }
        for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                dp[i][j] = INF;
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                for(int l=0; l<=j; l++){
                    if( j - l >= 0 )
                        dp[i][j] = min( dp[i][j] , dp[prv[i][l]-1][j-l] + 1 );
                }
            }
        }
        cout << dp[n][k] << '\n';
    }

    return 0;
}