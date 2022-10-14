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
const int maxn = 200010;
const int mod2 = 1000000007;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
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

int fact[maxn], ifact[maxn], mu[maxn];
int f[maxn], g[maxn];

int comb(int n,int k){
    return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;

    fact[0] = ifact[0] = 1;
    for(int i=1; i<=m; i++){
        fact[i] = fact[i-1] * i % mod;
        ifact[i] = modinv( fact[i] );
    }

    vector<int> l(n+2), r(n+2);
    for(int i=1; i<=n; i++)
        cin >> l[i] >> r[i];

    mu[1] = 1;
    for(int i=2; i<=m; i++){
        mu[i] = 1;
        int curr = i;
        for(int j=2; j*j<=curr; j++){
            if( curr % j == 0 ){
                int cnt = 0;
                while( curr % j == 0 ){
                    cnt ++;
                    curr /= j;
                }
                if( cnt == 1 ) mu[i] *= -1;
                if( cnt >= 2 ) mu[i] = 0;
            }
        }
        if( curr > 1 )
            mu[i] *= -1;
    }

    vector<int> b(n+2), c(n+2);
    int ans = 0;
    for(int i=1; i<=m; i++){

        if( mu[i] == 0 ) continue;

        int sum = m;
        for(int j=1; j<=n; j++){
            b[j] = l[j];
            if( b[j] % i )
                b[j] += ( i - b[j] % i );
            sum -= b[j];//db(b[j])
        }

        if( sum < 0 ) continue;
        bool bad = 0;
        for(int j=1; j<=n; j++){
            c[j] = ( r[j] - b[j] ) / i;
            if( c[j] < 0 ) bad = 1;
        }
        if( bad ) continue;

        int tot = sum / i;
        fill(f,f+2*tot+5,0);
        fill(g,g+2*tot+5,0);
        f[0] = 1;
        int sf = 0;
        for(int j=1; j<=n; j++){
            int sz = min( tot , max( sf , c[j] ) ) * 2;
            int val = 0;
            for(int k=0; k<=sz; k++){
                val += f[k];
                if( k > c[j] )
                    val -= f[k-c[j]-1];
                val += mod;
                val %= mod;
                g[k] = val;
            }
            sf = min( sz , tot );

            for(int t=0; t<2*tot+5; t++)
                f[t] = g[t];
            fill(g,g+2*tot+5,0);
        }
        for(int k=0; k<=tot; k++)
            ans = ( ans + f[k] * mu[i] + mod ) % mod;
    }

    cout << ans << '\n';

    return 0;
}