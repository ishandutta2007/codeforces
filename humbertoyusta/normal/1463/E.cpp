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
const int maxn = 600005;
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

int tc, n, m, comp[maxn], in[maxn], out[maxn], a[maxn], has[maxn], mk[maxn], sz[maxn], can, id[maxn];
vector<int> fre[maxn], cc[maxn];
vector<int> g[maxn], ans;
queue<int> q;

void dfs(int u,int col){
    if( comp[u] ){ can = 0; return; }
    comp[u] = col;
    cc[col].pb(u);
    sz[col] ++;
    id[u] = cc[col].size();
    for( auto v : g[u] )
        dfs(v,col);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    can = 1;

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        fre[a[i]].pb(i);
    }

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        in[v] ++;
        out[u] ++;
        if( in[u] > 1 || out[u] > 1 ){
            cout << 0 << '\n';
            return 0;
        }
        if( in[v] > 1 || out[v] > 1 ){
            cout << 0 << '\n';
            return 0;
        }
        g[u].pb(v);
    }

    int cntc = 0;
    for(int i=1; i<=n; i++){
        if( !can ) break;
        if( !in[i] ){
            dfs(i,++cntc);
        }
    }

    if( !can ){
        cout << 0 << '\n';
        return 0;
    }

    for(int i=1; i<=n; i++){
        if( comp[a[i]] == comp[i] ){
            if( id[i] > id[a[i]] ){
                has[comp[i]] ++;
            }
            else{
                cout << 0 << '\n';
                return 0;
            }
        }
    }

    q.push(0);
    cc[0].pb(0);
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        if( mk[u] ) continue;
        mk[u] = 1;
        for( auto v : cc[u] ){
            ans.pb(v);
            for( auto w : fre[v] ){
                has[comp[w]] ++;
                if( has[comp[w]] == sz[comp[w]] ){
                    q.push(comp[w]);
                }
            }
        }
    }

    if( ans.size() == n + 1 ){
        for(int i=1; i<=n; i++)
            cout << ans[i] << " \n"[i==n];
    }
    else{
        cout << 0 << '\n';
    }

    return 0;
}