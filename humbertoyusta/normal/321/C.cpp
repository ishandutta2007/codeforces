    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
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
const int maxn = 100002;
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

typedef vector<vector<int>> graph;
struct centroid{
    graph G, T;
    vector<int> subt;
    vector<bool> mk;
    int size_subt, n, root;

    centroid(graph _G) {
        G = _G; n = G.size();
        subt.resize(n); mk.resize(n); T.resize(n);
        for(int i=1; i<n; i++)
            if( !mk[i] )
                build_centroid(i,0);
    }

    void dfs_prec(int u,int p){
        subt[u] = 1;
        for( auto v : G[u] )
            if( !mk[v] && v != p ){
                dfs_prec(v,u);
                subt[u] += subt[v];
            }
    }

    int find_centroid(int u,int p){
        for( auto v : G[u] )
            if( !mk[v] && subt[v] > size_subt / 2 && v != p )
                return find_centroid(v,u);
        return u;
    }

    void build_centroid(int nod,int p){
        dfs_prec(nod,nod);
        size_subt = subt[nod];
        int centroid = find_centroid(nod,nod);
        T[p].push_back(centroid);
        mk[centroid] = 1;
        for( auto u : G[centroid] ){
            if( !mk[u] ){
                build_centroid(u,centroid);
            }
        }
    }
};

vector<vector<int>> VV;
centroid C = centroid(VV);
int f[maxn];

void dfs(int u){
    for( auto v : C.T[u] ){
        f[v] = f[u] + 1;
        dfs(v);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    int n;
    cin >> n;
    vector<vector<int>> g(n+1);

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    C = centroid(g);

    dfs(0);

    for(int i=1; i<=n; i++)
        cout << char('A' + f[i] - 1 ) << " \n"[i==n];

    return 0;
}