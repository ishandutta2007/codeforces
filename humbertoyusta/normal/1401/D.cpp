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

int tc, ans, subt[maxn], n, m;
vector<int> g[maxn], v1, v2;

void dfs(int u,int p){
    subt[u] = 1;
    for( auto v : g[u] ){
        if( v == p ) continue;
        dfs(v,u);
        subt[u] += subt[v];
    }
    v2.pb( ( subt[u] * ( n - subt[u] ) ) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n;

        for(int i=1; i<=n; i++){
            g[i].clear();
            v1.clear();
            v2.clear();
        }

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        cin >> m;

        for(int i=1; i<=m; i++){
            int u;
            cin >> u;
            v1.pb(u);
        }

        sort(all(v1));
        reverse(all(v1));

        dfs(1,1);

        sort(all(v2));
        reverse(all(v2));

        for(int i=0; i<v2.size(); i++)
            v2[i] %= mod;

        int pt1 = 0, pt2 = 0, p1 = v1[0], p2 = v2[0];
        //while( v1.size() < v2.size() ) v1.pb(1);
        while( (int)v1.size() - pt1 > (int)v2.size() - ( pt2 + 1 ) ){
            pt1 ++;
            p1 = ( p1 * v1[pt1] ) % mod;
        }
        ans = ( p1 * p2 ) % mod;
        pt1++;
        pt2++;
        p1 = 0;
        p2 = 0;
        while( pt1 < v1.size() ){
            p1 = v1[pt1];
            p2 = v2[pt2];
            ans = ( ans + p1 * p2 ) % mod;
            pt1++;
            pt2++;
        }

        while( pt2 < v2.size() ){
            ans = ( ans + v2[pt2] ) % mod;
            pt2++;
        }

        cout << ans << '\n';
    }

    return 0;
}