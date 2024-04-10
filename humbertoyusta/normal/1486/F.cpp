    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
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

int n, m, l[maxn], r[maxn], lca[maxn][20], tcnt, abi[maxn], lv[maxn], vsum[maxn], esum[maxn], ans, acc;
pair<ii,int> q[maxn];
vector<int> g[maxn], upd[maxn];
vector<ii> vx[maxn];

bool fcmp1(int a,int b){
    return l[a] < l[b];
}

bool fcmp2(ii a,ii b){
    if( l[a.f] != l[b.f] ) return l[a.f] < l[b.f];
        else return l[a.s] < l[b.s];
}

void dfs(int u,int p){
    l[u] = r[u] = ++ tcnt;
    for( auto v : g[u] )
        if( v != p ){
            lca[v][0] = u;
            lv[v] = lv[u] + 1;
            dfs(v,u);
            r[u] = max( r[u] , r[v] );
        }
}

int LCA(int a,int b){
    if( lv[a] < lv[b] ) swap(a,b);
    for(int i=19; i>=0; i--)
        if( lv[a] - (1<<i) >= lv[b] )
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

int query_abi(int id){
    int ret = 0;
    for( ; id > 0; id -= ( id & -id ) )
        ret += abi[id];
    return ret;
}

int query(int xl,int xr){
    return query_abi(xr) - query_abi(xl-1);
}

void dfs2(int u,int p){

    for( auto v : upd[u] ){
        int x = v;
        if( lv[x] == lv[u] ) continue;
        for(int i=19; i>=0; i--)
            if( lv[x] - (1<<i) > lv[u] ) x = lca[x][i];
        ans -= query(l[x],r[x]);
    }

    for( auto v : upd[u] ){
        int x = v;
        if( lv[x] == lv[u] ) continue;
        update(l[x],1);
    }

    for( auto v : g[u] ){
        if( v == p ) continue;
        dfs2(v,u);
        vsum[u] += vsum[v];
        esum[u] += esum[v];
    }
//    db(u)
//    db(vsum[u])
//    db(esum[u])
    acc -= ans;
    ans += ( vsum[u] * ( vsum[u] - 1 ) ) / 2;
    ans -= ( esum[u] * ( esum[u] - 1 ) ) / 2;
    acc += ans;

    map<int,int> cnt1;
    map<ii,int> cnt2;

    int tmp = 0;
    for( auto v : vx[u] ){
        int x = v.f, y = v.s;
        for(int i=19; i>=0; i--){
            if( lv[x] - (1<<i) > lv[u] ) x = lca[x][i];
            if( lv[y] - (1<<i) > lv[u] ) y = lca[y][i];
        }
        if( l[x] > l[y] ) swap(x,y);
        //db(u)db(v.f)db(v.s)db(x)db(y)
        if( x != u ) cnt1[x] ++;
        if( y != u ) cnt1[y] ++;
        if( x != u && y != u ) cnt2[{x,y}] ++;
    }

    for( auto i : cnt1 ){ ans -= i.s * (i.s-1) / 2; }
    for( auto i : cnt2 ){ ans += i.s * (i.s-1) / 2; }

    cnt1.clear();
    cnt2.clear();
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    lv[1] = 1;
    dfs(1,1);

    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++)
            lca[j][i] = lca[lca[j][i-1]][i-1];

    cin >> m;

    for(int i=1; i<=m; i++){

        cin >> q[i].f.f >> q[i].f.s;
        if( l[q[i].f.f] > l[q[i].f.s] )
            swap( q[i].f.f , q[i].f.s );
        q[i].s = LCA(q[i].f.f, q[i].f.s);

        esum[q[i].f.f] ++;
        esum[q[i].f.s] ++;
        esum[q[i].s] --;
        esum[q[i].s] --;

        vsum[q[i].f.f] ++;
        vsum[q[i].f.s] ++;
        vsum[q[i].s] --;
        vsum[lca[q[i].s][0]]--;

        vx[q[i].s].pb({q[i].f.f,q[i].f.s});

        upd[q[i].s].pb(q[i].f.f);
        upd[q[i].s].pb(q[i].f.s);
    }

    for(int i=1; i<=n; i++){
        sort(all(upd[i]),fcmp1);
        sort(all(vx[i]),fcmp2);
    }

    dfs2(1,1);

//    for(int i=1; i<=n; i++){
//        db(vsum[i])
//        db(esum[i])
//    }
    cout << ans << '\n';

    return 0;
}