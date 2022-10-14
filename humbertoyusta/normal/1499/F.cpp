    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
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
typedef long long ll;
/// Constraints:
const int maxn = 5050;
const int mod2 = 1000000007;
const int mod = 998244353;
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

int n, k, dp[maxn][maxn], subt[maxn], ac[maxn][maxn], l[maxn], r[maxn];
vector<int> g[maxn];

void dfs(int u,int p){
    subt[u] = 1;
    for( auto v : g[u] )
        if( v != p ){
            dfs(v,u);
            subt[u] += subt[v];
        }

    if( g[u].size() == 1 && u != 1 ){
        dp[u][0] = 1;
        for(int i=0; i<=n; i++)
            ac[u][i] = 1;
        return;
    }

    dp[u][0] = 1;
    for( auto v : g[u] ){
        if ( v == p ) continue;
        dp[u][0] = ( (ll)dp[u][0] * ac[v][k] ) % mod;
    }
    ac[u][0] = dp[u][0];

    for(int j=0; j<=(int)g[u].size()+1; j++)
        l[j] = r[j] = 0;
    l[0] = 1;
    r[g[u].size()+1] = 1;
    for(int j=0; j<g[u].size(); j++){
        if( g[u][j] != p ) l[j+1] = ( (ll)l[j] * ( ac[g[u][j]][k] ) ) % mod;
            else l[j+1] = l[j];
    }
    for(int j=(int)g[u].size()-1; j>=0; j--){
        if( g[u][j] != p ) r[j+1] = ( (ll)r[j+2] * ( ac[g[u][j]][k] ) ) % mod;
            else r[j+1] = r[j+2];
    }
    for(int j=0; j<g[u].size(); j++){
        if( g[u][j] != p ){
            dp[u][k] = ( (ll)dp[u][k] + ( (ll)dp[g[u][j]][k-1] * l[j] % mod * r[j+2] ) ) % mod;
        }
    }

    for(int i=0; i<k; i++){
        if( i + 1 + i + 1 <= k ){
            dp[u][i+1] = 1;
            for( auto v : g[u] ){
                if( v == p ) continue;
                dp[u][i+1] = ( (ll)dp[u][i+1] * ( ac[v][i] + ac[v][k] ) ) % mod;
            }
            dp[u][i+1] = ( (ll)dp[u][i+1] - ac[u][i] + mod ) % mod;
        }
        else{
            if( k - i - 2 >= 0 ){
                for(int j=0; j<=(int)g[u].size()+1; j++)
                    l[j] = r[j] = 0;
                l[0] = 1;
                r[g[u].size()+1] = 1;
                for(int j=0; j<g[u].size(); j++){
                    if( g[u][j] != p ) l[j+1] = ( (ll)l[j] * ( (ll)ac[g[u][j]][k] + ac[g[u][j]][k-i-2] ) ) % mod;
                        else l[j+1] = l[j];
                }
                for(int j=(int)g[u].size()-1; j>=0; j--){
                    if( g[u][j] != p ) r[j+1] = ( (ll)r[j+2] * ( (ll)ac[g[u][j]][k] + ac[g[u][j]][k-i-2] ) ) % mod;
                        else r[j+1] = r[j+2];
                }
                for(int j=0; j<g[u].size(); j++){
                    if( g[u][j] != p ) dp[u][i+1] = ( (ll)dp[u][i+1] + ( (ll)dp[g[u][j]][i] * l[j] % mod * r[j+2] ) ) % mod;
                }
            }
        }
        ac[u][i+1] = ( (ll)ac[u][i] + dp[u][i+1] ) % mod;
        //cout << u << ' ' << i << ' ' << dp[u][i] << '\n';
    }
    //cout << u << ' ' << k << ' ' << dp[u][k] << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> k;

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,1);

    cout << ac[1][k] << '\n';

    return 0;
}