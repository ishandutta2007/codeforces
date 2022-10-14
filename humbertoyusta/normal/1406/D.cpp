    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize ("Ofast")
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
const int maxn = 100010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 10000000000000007ll;
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

int n, a[maxn], df[maxn], sp, q;

int f(int x){
    return max( x , a[1] - x + sp );
}

int query(){
    int l = -INF, r = INF;
    int res = INF;
    while( l < r ){
        if( abs( r - l ) <= 20 ){
            for(int i=l; i<=r; i++)
                res = min( res , f(i) );
            break;
        }
        int p1 = l + ( r - l ) / 3;
        int p2 = r - ( r - l ) / 2;
        if( f(p1) >= f(p2) ) l = p1;
            else r = p2;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        df[i] = a[i] - a[i-1];
        if( i > 1 && df[i] > 0 ){
            sp += df[i];
        }
    }

    cin >> q;

    cout << query() << '\n';

    for(int i=1; i<=q; i++){

        int l, r, x;
        cin >> l >> r >> x;

        if( l == 1 ){
            a[1] += x;
        }

        r ++;

        if(l > 1 && df[l] > 0 ) sp -= df[l];
        df[l] += x;
        if(l > 1 && df[l] > 0 ) sp += df[l];

        if( r <= n ){
            if(r > 1 && df[r] > 0 ) sp -= df[r];
            df[r] -= x;
            if(r > 1 && df[r] > 0 ) sp += df[r];
        }

        cout << query() << '\n';
    }

    return 0;
}