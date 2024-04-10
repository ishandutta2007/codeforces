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
const int maxn = 300010;
const int maxm = 23;
const int mod = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
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

int n, m, k(1), F[maxn], dp[maxm][2*maxm], mk[maxn], id[maxn], cont[maxm], T[maxm][maxm], M, sz[maxm], ans, fact[maxn], invfact[maxn];
ii A[maxn];
vector<int> G[maxn], v;
vector<int> P[maxm][maxn];

int C(int a,int b){
    return fact[a] * invfact[b] % mod * invfact[a-b] % mod;
}

void dfs(int u){
    mk[u] = 1;
    M++;
    sz[k]++;
    for( auto w : G[u] )
        if( !mk[w] )
            dfs(w);
    v.pb(u);
    id[u] = v.size() - 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    fact[0] = 1;
    invfact[0] = 1;
    for(int i=1; i<maxn; i++){
        fact[i] = fact[i-1] * i % mod;
        invfact[i] = modinv(fact[i]);
    }

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> A[i].f >> A[i].s;
    }

    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    for(int i=1; i<=n; i++){
        if( !mk[i] ){
            if( G[i].size() == 0 ){
                F[A[i].f]++;
                F[A[i].s+1]--;
            }
            else{
                ++k;
                v.clear();
                dfs(i);
                for(int j=0; j<v.size(); j++){
                    cont[j] = 0;
                    for( auto w : G[v[j]] )
                        cont[j] |= (1ll<<(id[w]));
                }
                int p = v.size();
                for(int mask=0; mask<(1<<p); mask++){
                    bool can = 1;
                    for(int j=0; j<p; j++)
                        if( mask & ( 1 << j ) )
                            if( mask & cont[j] )
                                can = 0;
                    if( can ){
                        int l = 0, r = n+1;
                        for(int j=0; j<p; j++)
                            if( mask & ( 1 << j ) )
                                l = max( l , A[v[j]].f ), r = min( r , A[v[j]].s );
                        if( l <= r ){
                            P[k][l].pb(__builtin_popcountll(mask));
                            P[k][r+1].pb(-(__builtin_popcountll(mask)));
                        }
                    }
                }
            }
        }
    }

    for(int i=0; i<=n+1; i++){
        if(i) F[i] += F[i-1];
        for(int j=1; j<=k; j++){
            for( auto l : P[j][i] ){
                if( l >= 0 ) T[j][l] ++;
                    else T[j][-l] --;
            }
        }
        if( i >= 1 && i <= n ){
            memset( dp , 0 , sizeof dp );
            dp[k+1][0] = 1;
            for(int j=k; j>=2; j--){
                for(int l=0; l<=M; l++){
                    for(int t=0; t<=min(sz[j],l); t++){
                        dp[j][l] = ( dp[j][l] + dp[j+1][l-t] * T[j][t] );
                    }
                    dp[j][l] %= mod;
                    //db(dp[j][l])
                }
            }
            for(int j=0; j<=M; j++){
                if( i >= j && i - j <= F[i] ){
                    ans = ( ans + C(F[i],i-j) * dp[2][j] ) % mod;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}