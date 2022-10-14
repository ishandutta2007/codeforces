    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll * mod * mod;
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

int tc, n, m, mk[maxn], lv[maxn], cnt, rmk[maxn];
priority_queue<ii> q;
vector<int> g[maxn], g2[maxn];

void dfs(int u){
    cnt ++;
    q.push({-lv[u],u});
    for( auto v : g[u] ){
        if( lv[v] ) continue;
        lv[v] = lv[u] + 1;
        dfs(v);
    }
}

void dfs2(int u){
    cnt ++;
    //q.pb({-lv[u],u});
    for( auto v : g2[u] ){
        if( lv[v] ) continue;
        lv[v] = lv[u] + 1;
        dfs2(v);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc -- ){

        cin >> n >> m;

        while( !q.empty() ) q.pop();
        for(int i=1; i<=n; i++){
            g[i].clear();
            g2[i].clear();
            lv[i] = mk[i] = rmk[i] = 0;
        }

        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        cnt = 0;
        lv[1] = 1;
        dfs(1);

        if( cnt < n ){
            cout << "NO\n";
            continue;
        }

        while( !q.empty() ){
            int u = q.top().s;
            q.pop();
            if( mk[u] ) continue;
            mk[u] = 1;
            rmk[u] = 1;
            for( auto v : g[u] )
                mk[v] = 1;
        }

        for(int i=1; i<=n; i++)
            for(auto j : g[i])
                if( rmk[j] || rmk[i] ){
                    g2[i].pb(j);
                }

        for(int i=1; i<=n; i++)
            lv[i] = 0;
        cnt = 0;
        lv[1] = 1;
        dfs2(1);

        if( cnt < n ){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            vector<int> ans;
            for(int i=1; i<=n; i++)
                if( rmk[i] ) ans.pb(i);
            cout << ans.size() << '\n';
            for( auto i : ans ) cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}