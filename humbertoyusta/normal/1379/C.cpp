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
const int maxn = 1000010;
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

int tc, n, m, mx[maxn], sum[maxn];
ii a[maxn];

int f(int x,int id){
    if( x < 0 || x + 1 > n ) return -1;
    int res = ( n - x - 1 ) * a[id].s + a[id].f;
    if( x < id ) res += sum[x];
        else res += sum[x+1] - a[id].f;
    return res;
}

int solve(int id){
    int res = 0;
    int l = 1, r = m - 1;
    while( l < r ){
        int mi = ( l + r ) >> 1;
        if( f(mi,id) < f(mi+1,id) ) l = mi + 1;
            else r = mi;
    }
    res = max( res , f(l-2,id) );
    res = max( res , f(l-1,id) );
    res = max( res , f(l,id) );
    res = max( res , f(l+1,id) );
    res = max( res , f(l+2,id) );
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n >> m;

        for(int i=1; i<=m; i++){
            cin >> a[i].f >> a[i].s;
        }

        sort(a+1,a+m+1);
        reverse(a+1,a+m+1);

        for(int i=1; i<=m+10; i++){
            sum[i] = sum[i-1];
            if( i <= m ) sum[i] += a[i].f;
        }

        int ans = 0;
        for(int i=1; i<=m; i++){
            ans = max( ans , solve(i) );
        }
        cout << ans << '\n';
    }

    return 0;
}