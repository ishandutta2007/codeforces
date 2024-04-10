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
const int maxn = 200010;
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

int tc, n, m, mk[maxn], c1, c2, a[maxn], b[maxn];
vector<pair<ii,int>> g[maxn];
vector<int> ans;

int dfs(int u,int p,int root){
    if( u == root && p != root ) return 0;
    for( auto v : g[u] ){
        if( v.f.f == p ) continue;
        return v.f.s + dfs(v.f.f,u,root);
    }
    return 0;
}

void to_ans(int u,int p,int root){
    if( mk[u] ) return;
    mk[u] = 1;
    for( auto v : g[u] ){
        if( v.f.f == p ) continue;
        if( v.f.s == 1 ) ans.pb(v.s);
        to_ans(v.f.f,u,root);
    }
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
            mk[i] = 0;
        }

        for(int i=1; i<=n; i++)
            cin >> a[i];
        for(int i=1; i<=n; i++)
            cin >> b[i];

        for(int i=1; i<=n; i++){
            int u = a[i], v = b[i];
            g[u].pb({{v,0},i});
            g[v].pb({{u,1},i});
        }

        bool can = 1;
        for(int i=1; i<=n; i++){
            if( g[i].size() != 2 ){
                can = 0;
            }
        }

        if( !can ){ cout << -1 << '\n'; }
        else{

            ans.clear();
            for(int i=1; i<=n; i++){
                if( !mk[i] && g[i][0].f.f != i ){
                    if( g[i][0].f.f == g[i][1].f.f ){
                        mk[i] = 1;
                        mk[g[i][0].f.f] = 1;
                        if( g[i][0].f.s == g[i][1].f.s )
                            ans.pb(g[i][0].s);
                        continue;
                    }
                    c1 = g[i][0].f.s + dfs(g[i][0].f.f,i,i);
                    c2 = g[i][1].f.s + dfs(g[i][1].f.f,i,i);
                    if( c1 < c2 ){
                        to_ans(i,g[i][1].f.f,i);
                    }
                    else{
                        to_ans(i,g[i][0].f.f,i);;
                    }
                    mk[i] = 1;
                }
            }

            cout << ans.size() << '\n';
            for( auto i : ans )
                cout << i << ' ';
            cout << '\n';
        }
    }

    return 0;
}