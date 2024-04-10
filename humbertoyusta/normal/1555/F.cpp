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
const int maxn = 500010;
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

int p[maxn], col[maxn], sz[maxn], dirp[maxn], lv[maxn], l[maxn], r[maxn], lca[maxn][20];
int mk[maxn], cnt, par[maxn], abi[maxn];
string ans[maxn];
pair<ii,int> e[maxn];
vector<int> g[maxn];
map<ii,int> mp;

int find_(int x){
    return ( p[x] == x ) ? ( x ) : ( p[x] = find_( p[x] ) );
}

void dfs(int u,int p){
    col[u] ^= 1;
    for( auto v : g[u] ){
        if( v != p )
            dfs(v,u);
    }
}

bool union_(int u,int v,int w){
    int a = find_(u), b = find_(v);
    if( a == b ){
        if( w == 0 && col[u] == col[v] )
            return false;
        if( w == 1 && col[u] != col[v] )
            return false;
        return true;
    }
    if( sz[a] < sz[b] ){
        swap(a,b);
        swap(u,v);
    }
    p[b] = a;
    sz[a] += sz[b];
    if( col[u] == col[v] && w == 1 )
        dfs(v,u);
    if( col[u] != col[v] && w == 0 )
        dfs(v,u);
    g[u].pb(v);
    g[v].pb(u);
    mp[{min(u,v),max(u,v)}] = true;
    return true;
}

void dfs_t(int u,int p){

    l[u] = r[u] = ++cnt;
    mk[u] = 1;
    if( u != p ) par[u] = p;

    for( auto v : g[u] ){
        if( v != p ){

            lv[v] = lv[u] + 1;

            lca[v][0] = u;
            for(int j=1; j<20; j++)
                lca[v][j] = lca[lca[v][j-1]][j-1];

            dfs_t(v,u);

            r[u] = max( r[u] , r[v] );
        }
    }
}

int LCA(int a,int b){
    if( lv[a] < lv[b] ) swap( a , b );
    for(int i=19; i>=0; i--)
        if( lv[a] - (1<<i) >= lv[b] && lca[a][i] )
            a = lca[a][i];
    if( a == b ) return a;
    for(int i=19; i>=0; i--)
        if( lca[a][i] != lca[b][i] && lca[a][i] && lca[b][i] )
            a = lca[a][i], b = lca[b][i];
    return lca[a][0];
}

void update(int id,int val){
    for( ; id < maxn; id += ( id & -id ) )
        abi[id] += val;
}

int query(int id){
    int ret = 0;
    for( ; id > 0; id -= ( id & -id ) )
        ret += abi[id];
    return ret;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        p[i] = i;
        col[i] = 0;
        sz[i] = 1;
    }

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = { { u , v } , w };
        if( union_(u,v,w) ) ans[i] = "YES";
            else ans[i] = "NO";
    }

    for(int i=1; i<=n; i++){
        if( !mk[i] ){
            lv[i] = 1;
            dfs_t(i,i);
        }
    }

    for(int i=1; i<=m; i++){
        int u = e[i].f.f, v = e[i].f.s;
        if( ans[i] == "YES" && !mp[{min(u,v),max(u,v)}] ){
            int x = LCA(u,v);
            int sum = query(l[u]) + query(l[v]) - 2 * query(l[x]);
            if( sum == 0 ){
                while( u != x || v != x ){
                    if( lv[u] < lv[v] )
                        swap( u , v );
                    update(l[u],1);
                    update(r[u]+1,-1);
                    u = par[u];
                }
            }
            else{
                ans[i] = "NO";
            }
        }
    }

    for(int i=1; i<=m; i++)
        cout << ans[i] << '\n';

    return 0;
}