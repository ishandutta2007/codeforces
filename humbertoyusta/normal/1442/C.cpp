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
const int maxn = 200010;
const int maxm = 21;
const int mod = 998244353;
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

int n, m, pot[maxn];
ii dp2[maxn*2];
vector<ii> edge;
vector<pair<int,ii>> g2[maxn*2];
priority_queue<pair<ii,int>> q;
priority_queue<ii> q2;
int dp[maxn*maxm];
vector<ii> g[maxn*maxm];

int encode(int flips,int node){
    return flips * ( n + 1 ) + node;
}

void dijkstra2(int start){
    dp2[start] = { 0 , 0 };
    q.push({{0,0},start});
    while( !q.empty() ){
        int u = q.top().s;
        q.pop();
        for( auto v : g2[u] ){
            ii nwc = { dp2[u].f + v.s.f , dp2[u].s + v.s.s };
            if( dp2[v.f] > nwc ){
                dp2[v.f] = nwc;
                q.push({{-dp2[v.f].f,-dp2[v.f].s},v.f});
            }
        }
    }
}

void dijkstra(int start){
    dp[start] = 0;
    q2.push({0,start});
    while( !q2.empty() ){
        int u = q2.top().s;
        q2.pop();
        for( auto v : g[u] ){//db(v.f)
            int nwc = { dp[u] + v.s };
            if( dp[v.f] > nwc ){
                dp[v.f] = nwc;
                q2.push({{-dp[v.f]},v.f});
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    pot[0] = 1;
    for(int i=1; i<maxn; i++)
        pot[i] = pot[i-1] * 2;

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        edge.pb({u,v});
    }

    for(int i=0; i<m; i++){
        g2[encode(0,edge[i].f)].pb({encode(0,edge[i].s),{0,1}});
        g2[encode(1,edge[i].s)].pb({encode(1,edge[i].f),{0,1}});
    }

    for(int i=1; i<=n; i++){
        g2[encode(0,i)].pb({encode(1,i),{1,0}});
        g2[encode(1,i)].pb({encode(0,i),{1,0}});
    }

    for(int i=1; i<maxn*2; i++)
        dp2[i] = {mod,mod};

    dijkstra2(encode(0,1));

    ii res = min( dp2[encode(0,n)] , dp2[encode(1,n)] );

    int ans = ( ( qpow(2,res.f) + mod - 1 ) % mod + res.s ) % mod;

    //cout << ans << '\n';

    for(int i=0; i<maxn*maxm; i++)
        dp[i] = INF;

    for(int i=0; i<m; i++){
        for(int j=0; j<maxm; j++){
            if( j % 2 == 0 ) g[encode(j,edge[i].f)].pb({encode(j,edge[i].s),1});
                else g[encode(j,edge[i].s)].pb({encode(j,edge[i].f),1});
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<maxm-1; j++){
            g[encode(j,i)].pb({encode(j+1,i),pot[j]});
        }
    }

    dijkstra(encode(0,1));

    int ans2 = INF;
    for(int i=0; i<maxm; i++){
        if( dp[encode(i,n)] < INF ){
            ans2 = min( ans2 , dp[encode(i,n)] );
        }
    }

    if( ans2 != INF ) cout << ans2 % mod << '\n';
        else cout << ans << '\n';

    return 0;
}