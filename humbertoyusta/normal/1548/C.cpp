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
const int maxn = 3000010;
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
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int fact[maxn*3], ifact[maxn*3], a[maxn*3][3], inv3;

int Comb(int N,int K){
    return fact[N] * ifact[K] % mod * ifact[N-K] % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    fact[0] = ifact[0] = 1;
    inv3 = modinv(3);
    for(int i=1; i<=3*n+3; i++){
        fact[i] = fact[i-1] * i % mod;
    }
    ifact[3*n+3] = modinv( fact[3*n+3] );
    for(int i=3*n+2; i>=1; i--){
        ifact[i] = ifact[i+1] * (i+1) % mod;
    }

    a[0][0] = n + 1;
    a[0][1] = n;
    a[0][2] = n;
    for(int i=1; i<=3*n; i++){
        int sum = Comb(3*n+1,i+1);
        a[i][1] = ( sum - a[i-1][2] - a[i-1][1] * 2 + 3 * mod ) % mod;
        a[i][1] = a[i][1] * inv3 % mod;
        a[i][2] = ( a[i-1][1] + a[i][1] ) % mod;
        a[i][0] = ( a[i-1][2] + a[i][2] ) % mod;
//        db(a[i][0])
//        db(a[i][1])
//        db(a[i][2])
    }

    int q;
    cin >> q;
    for(int i=1; i<=q; i++){
        int u;
        cin >> u;
        cout << a[u][0] << '\n';
    }

    return 0;
}