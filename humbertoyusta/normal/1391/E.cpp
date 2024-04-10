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

int n, m, lv[maxn], subt[maxn], mk[maxn], parent[maxn], cnt;
vector<int> g[maxn], v[maxn], t[maxn], it[maxn];

void dfs_1(int u,int p){
    subt[u] = 1;
    for( auto v : g[u] ){
        if( v != p && !subt[v] ){
            lv[v] = lv[u] + 1;
            dfs_1(v,u);
            subt[u] += subt[v];
            t[u].pb(v);
            it[v].pb(u);
        }
    }
}

void dfs_2(int u,int p,int c){
    v[c].pb(u);
    for( auto v : t[u] )
        if( v != p && subt[v] <= n / 2 )
            dfs_2(v,u,c);
}

int find_(int u,int p){
    ii mark = {-1,0};
    for( auto v : t[u] ){
        if( v != p ){
            mark = max( mark , { subt[v] , v } );
        }
    }
    if( n - lv[u] - 1 < ( n + 1 ) / 2 )
    mark = {0,0};
    for( auto v : t[u] ){
        if( v != p && v != mark.s ){
             dfs_2(v,u,++cnt);
        }
    }
    if( !mark.s ) return u;
    return find_(mark.s,u);
}

ii dfs_3(int u,int p){
    if( t[u].size() == 0 )
        return {lv[u],u};
    ii res = {-1,0};
    for( auto v : t[u] )
        res = max( res , dfs_3(v,u) );
    return res;
}

ii dfs_4(int u,int p,int dist){
    parent[u] = p;
    if( it[u].size() + t[u].size() == 1 && u != p )
        return {dist,u};
    ii res = {-1,0};
    for( auto v : t[u] )
        if( v != p )
            res = max( res , dfs_4(v,u,dist+1) );
    for( auto v : it[u] )
        if( v != p )
            res = max( res , dfs_4(v,u,dist+1) );
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){

        cin >> n >> m;

        for(int i=1; i<=n; i++){
            g[i].clear();
            v[i].clear();
            t[i].clear();
            it[i].clear();
            lv[i] = 0;
            subt[i] = 0;
            parent[i] = 0;
        }

        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        if( n == 2 ){
            cout << "PATH\n";
            cout << 2 << '\n';
            cout << 1 << ' ' << 2 << '\n';
            continue;
        }

        lv[1] = 1;
        dfs_1(1,1);

        //db(n)db(m)

        ii u1 = dfs_3(1,1);
        ii u2 = dfs_4(u1.s,u1.s,1);
        if( u2.f >= ( 1 + n ) / 2 ){
            cout << "PATH\n";
            cout << u2.f << '\n';
            int pp = u2.s;
            while( u2.s != u1.s ){
                cout << u2.s << ' ';
                u2.s = parent[u2.s];
            }
            cout << u2.s << '\n';
            continue;
        }

        cnt = 0;

        int centroid = find_(1,1);

        //for( auto v : t[centroid] ){
        //    dfs_2(v,centroid,++cnt);
        //}
        //for( auto v : t[1] ){
        //    if( subt[v] <= n / 2 ){
        //        dfs_2(v,1,++cnt);
        //    }
        //}

        int sum = 0;
        for(int i=1; i<=cnt; i++)
            sum += v[i].size();

        vector<int> vx;
        for(int i=1; i<=cnt; i++){
            for(int j=0; j<min((int)v[i].size(),sum-(int)v[i].size()); j++)
                vx.pb(v[i][j]);
        }
        if( vx.size() % 2 ) vx.pop_back();

        vector<ii> ans;
        for(int i=0; i<vx.size()/2; i++)
            ans.pb({vx[i],vx[i+vx.size()/2]});

        cout << "PAIRING\n";
        cout << ans.size() << '\n';
        for( auto pk : ans ){
            cout << pk.f << ' ' << pk.s << '\n';
        }
    }

    return 0;
}