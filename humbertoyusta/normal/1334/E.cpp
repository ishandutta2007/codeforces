    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const int maxn = 100010;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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
/// My Code -------------------------------------------------

int n, fact[maxn], inv[maxn], s1, s2, q, u, v, d;
vector<int> f, f1, f2;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    fact[0] = 1;
    for(int i=1; i<maxn; i++){
        fact[i] = ( fact[i-1] * i ) % mod;
        inv[i] = qpow(fact[i],mod-2);
    }

    cin >> d;

    f.pb(-1);
    for(int i=2; i<=sqrt(d); i++){
        while( d % i == 0 ){
            if( i != f.back() )
                f.pb(i);
            d /= i;
        }
    }
    if( d != 1 && d != f.back() )
        f.pb(d);

    cin >> q;
    for(int i=1; i<=q; i++){
        cin >> v >> u;
        s1 = 0;
        s2 = 0;
        f1.clear();
        f2.clear();
        for(int j=1; j<f.size(); j++){
            int a = 0, b = 0;
            while( u % f[j] == 0 ){ a++, u /= f[j]; }
            while( v % f[j] == 0 ){ b++, v /= f[j]; }
            if( a > b ){
                s1 += a - b;
                f1.pb( a - b );
            }
            if( a < b ){
                s2 += b - a;
                f2.pb( b - a );
            }
        }
        int ans1 = fact[s1];
        int ans2 = fact[s2];
        for( auto j : f1 )
            ans1 = ( ans1 * inv[j] ) % mod;
        for( auto j : f2 )
            ans2 = ( ans2 * inv[j] ) % mod;
        cout << ans1 * ans2 % mod << '\n';
    }

    return 0;
}