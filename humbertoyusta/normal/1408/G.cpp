    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
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
const int maxn = 1505;
const int mod = 998244353;
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

int n, ady[maxn][maxn], par[maxn], ran[maxn], dsum[maxn], id[maxn], nid[maxn], cnt;
int mn[maxn], mx[maxn], dp[maxn][maxn];
ii edge[maxn*maxn];
vector<int> ind[maxn], g[maxn];

int find_(int x){
    return ( par[x] == x ) ? ( x ) : ( par[x] = find_( par[x] ) );
}

bool union_1(int u,int v){
    u = find_(u), v = find_(v);
    if( u == v ) return 0;
    if( ran[u] < ran[v] ) swap( u , v );
    for( auto i : ind[v] )
        ind[u].pb(i);
    par[v] = u;
    ran[u] += ran[v];
    return 1;
}

bool union_2(int u,int v){
    u = find_(u), v = find_(v);
    dsum[u]++;
    if( u == v &&  dsum[u] == ran[u] * ( ran[u] - 1 ) / 2 ){
        g[mx[u]].pb(mn[u]-1);cnt++;
    }
    if( u == v ) return 0;
    if( ran[u] < ran[v] ) swap( u , v );
    mn[u] = min( mn[u] , mn[v] );
    mx[u] = max( mx[u] , mx[v] );
    dsum[u] += dsum[v];
    par[v] = u;
    ran[u] += ran[v];
    if( dsum[u] == ran[u] * ( ran[u] - 1 ) / 2 ){
        g[mx[u]].pb(mn[u]-1);cnt++;
    }
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    if( n == 1 ){
        cout << 1 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            cin >> ady[i][j];
            edge[ady[i][j]] = { j , i };
        }

    for(int i=1; i<=n; i++){
        ind[i].pb(i);
        par[i] = i;
        ran[i] = 1;
        dsum[i] = 0;
    }

    for(int i=1; i<=n*(n-1)/2; i++){
        union_1(edge[i].f,edge[i].s);
    }

    for(int i=1; i<=n; i++){
        id[i] = ind[find_(1)][i-1];
        nid[id[i]] = i;
    }

    for(int i=1; i<=n; i++){
        ind[i].pb(i);
        par[i] = i;
        mn[i] = nid[i];
        mx[i] = nid[i];
        ran[i] = 1;
        dsum[i] = 0;
    }

    for(int i=1; i<=n*(n-1)/2; i++){
        union_2(edge[i].f,edge[i].s);
    }

    for(int i=1; i<=n; i++)
        g[i].pb(i-1);

    //if( n > 1000 ){ cout << cnt; return 0; }
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for( auto k : g[j] ){
                dp[i][j] = ( dp[i][j] + dp[i-1][k] );
                if( dp[i][j] >= mod ) dp[i][j] -= mod;
            }
        }
        cout << dp[i][n] << ' ';
    }cout << '\n';

    return 0;
}