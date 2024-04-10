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
const int maxn = 100010;
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

int n, color[maxn], res[maxn], ans[maxn], cnt;
vector<int> g[maxn], w[maxn];
queue<int> q;

void dfs_color(int u,int c){
    color[u] = c;
    for( auto v : g[u] )
        if( !color[v] )
            dfs_color(v,c%2+1);
}

void dfs(int u,int p){
    for( auto v : g[u] )
        if( v != p )
            dfs(v,u);
    for( auto v : g[u] )
        if( v != p )
            if( color[u] != color[v] && ( res[u] == 0 && res[v] == 0 ) ){
                res[u] = res[v] = ++cnt;
                q.push(u);
                q.push(v);
            }
}

void bfs(){
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        for( auto v : g[u] ){
            if( !res[v] ){
                res[v] = res[u];
                q.push(v);
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs_color(1,1);

    dfs(1,1);

    bfs();

    for(int i=1; i<=n; i++)
        w[res[i]].pb(i);

    int min_ans = 0;
    for(int i=1; i<=cnt; i++){
            min_ans += ( ( (int)w[i].size() - 1 ) * 2 );
        for(int j=0; j<w[i].size(); j++){
            ans[w[i][j]] = w[i][(j+1)%w[i].size()];
        }
    }

    cout << min_ans << '\n';
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}