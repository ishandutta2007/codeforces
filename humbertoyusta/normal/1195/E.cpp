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
const int maxn = 3003;
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

int n, m, a, b, h[maxn][maxn], g0, x, y, z, g[maxn*maxn], row[maxn][maxn];
int ans;
deque<ii> q;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m >> a >> b;

    cin >> g0 >> x >> y >> z;

    swap(a,b);
    //swap(n,m);

    g[0] = g0;
    for(int i=1; i<=n*m; i++){
        g[i] = ( g[i-1] * x + y ) % z;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            h[i][j] = ( g[(i-1)*m+j-1] );
        }
    }

    for(int i=1; i<=n; i++){
        while( !q.empty() ) q.pop_back();
        for(int j=1; j<=m; j++){
            while( !q.empty() && q.front().s <= j - a )
                q.pop_front();
            while( !q.empty() && q.back().f >= h[i][j] )
                q.pop_back();
            q.push_back({h[i][j],j});
            row[i][j] = min( q.front().f , q.back().f );
        }
    }

    for(int i=1; i<=m; i++){
        while( !q.empty() ) q.pop_back();
        for(int j=1; j<=n; j++){
            while( !q.empty() && q.front().s <= j - b )
                q.pop_front();
            while( !q.empty() && q.back().f >= row[j][i] )
                q.pop_back();
            q.push_back({row[j][i],j});
            if( j - b + 1 >= 1 && i - a + 1 >= 1 )
                ans += min( q.front().f , q.back().f );
        }
    }

    cout << ans << '\n';

    return 0;
}