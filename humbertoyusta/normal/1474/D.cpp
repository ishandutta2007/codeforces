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
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
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

int tc, n, f[maxn], sf[maxn], pr[maxn], a[maxn], fn;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc -- ){

        cin >> n;

        for(int i=0; i<=n+10; i++){
            f[i] = sf[i] = a[i] = pr[i] = 0;
        }

        pr[0] = INF;
        int sum = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            sum += a[i];
            f[i] = a[i] - f[i-1];
            pr[i] = min( pr[i-1] , f[i] );
        }
        if( sum % 2 ){
            cout << "NO\n";
            continue;
        }

        for(int i=n+2; i>=1; i--){
            if( i <= n ) sf[i] = min( sf[i+2] , f[i] );
                else sf[i] = INF;
        }

        bool can = ( ( pr[n] >= 0 ) && ( f[n] == 0 ) );

        for(int i=1; i<n; i++){
            if( pr[i-1] >= 0 ){

                //db(a[i])
                //db(a[i+1])

                f[i] -= a[i];
                f[i] += a[i+1];

                if( i + 2 <= n ){
                    sf[i+2] -= a[i];
                    sf[i+2] += a[i+1];

                    sf[i+2] -= a[i];
                    sf[i+2] += a[i+1];
                }

                sf[i+1] -= a[i+1];
                sf[i+1] += a[i];

                sf[i+1] -= a[i+1];
                sf[i+1] += a[i];

                if( n % 2 == i % 2 ){
                    f[n] -= a[i];
                    f[n] += a[i+1];

                    if( i + 2 <= n ){
                        f[n] -= a[i];
                        f[n] += a[i+1];
                    }
                }
                else{
                    f[n] -= a[i+1];
                    f[n] += a[i];

                    f[n] -= a[i+1];
                    f[n] += a[i];
                }

                if( i + 2 <= n ){
                    if( ( f[i] >= 0 && sf[i+1] >= 0 ) && ( f[n] == 0 && sf[i+2] >= 0 ) )
                        can = true;
                }
                else{
                    if( ( f[i] >= 0 && sf[i+1] >= 0 ) && f[n] == 0 )
                        can = true;
                }

                if( n % 2 == i % 2 ){
                    f[n] -= a[i+1];
                    f[n] += a[i];

                    if( i + 2 <= n ){
                        f[n] -= a[i+1];
                        f[n] += a[i];
                    }
                }
                else{
                    f[n] -= a[i];
                    f[n] += a[i+1];

                    f[n] -= a[i];
                    f[n] += a[i+1];
                }

                f[i] -= a[i+1];
                f[i] += a[i];

                if( i + 2 <= n ){
                    sf[i+2] -= a[i+1];
                    sf[i+2] += a[i];

                    sf[i+2] -= a[i+1];
                    sf[i+2] += a[i];
                }

                sf[i+1] -= a[i];
                sf[i+1] += a[i+1];

                sf[i+1] -= a[i];
                sf[i+1] += a[i+1];
            }
        }

        if( can ) cout << "YES\n";
            else cout << "NO\n";
    }

    return 0;
}