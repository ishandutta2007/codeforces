    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const int maxn = 5005;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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

int c[maxn], n1, n2, n3, n, m, comp[maxn], c1, c2, dp[maxn][maxn], ans[maxn];
bool cdp[maxn][maxn];
vector<int> g[maxn], G[maxn];
ii edge[100010];
vector<pair<ii,int>> comps;

void dfs(int u,int col, int compu){
    comp[u] = compu;
    c[u] = col;
    c1 += ( col == 1 );
    c2 += ( col == 2 );
    for( auto v : g[u] )
        if( !c[v] )
            dfs(v,(c[u]==1)?(2):(1),compu);
}

void backtrack(int i,int j){
    if( i == 0 ) return;
    for(int k=1; k<=n; k++)
        if( comp[k] == i ){
            if( c[k] == cdp[i][j] + 1 ){
                ans[k] = 2;
            }
            else{
                if( n1 > 0 ){
                    ans[k] = 1;
                    n1--;
                }
                else{
                    ans[k] = 3;
                }
            }
        }
    backtrack(i-1,dp[i][j]);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> n1 >> n2 >> n3;

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        edge[i] = {u,v};
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        if( !c[i] ){
            c1 = c2 = 0;
            dfs(i,1,++cnt);
            comps.pb({{c1,c2},cnt});
        }
    }

    bool bp = 1;
    for(int i=1; i<=m; i++){
        if( c[edge[i].f] == c[edge[i].s] ){
            bp = 0;
        }
    }

    if( !bp ){ cout << "NO\n"; return 0; }
    else{db("pra")
        memset( dp , -1 , sizeof dp );
        dp[0][0] = 1;
        for(int i=1; i<=cnt; i++){//db(comps[i-1].f.f)db(comps[i-1].f.s)
            for(int j=0; j<=n; j++){
                if( j >= comps[i-1].f.f ){
                    if( dp[i-1][j-comps[i-1].f.f] != -1 ){
                        dp[i][j] = j - comps[i-1].f.f;
                        cdp[i][j] = 0;
                    }
                }
                if( j >= comps[i-1].f.s ){
                    if( dp[i-1][j-comps[i-1].f.s] != -1 ){
                        dp[i][j] = j - comps[i-1].f.s;
                        cdp[i][j] = 1;
                    }
                }
                //db(i)db(j)db(dp[i][j])
            }
        }
        if( dp[cnt][n2] == -1 ){ cout << "NO\n"; return 0; }
        backtrack(cnt,n2);

        cout << "YES\n";
        for(int i=1; i<=n; i++)
            cout << ans[i];
        cout << '\n';
    }

    return 0;
}