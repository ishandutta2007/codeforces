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

int tc, ans[maxn], l[maxn], r[maxn], subt[maxn], cnt, n;
vector<int> g[maxn];

void dfs(int u,int p){
    l[u] = r[u] = ++cnt;
    subt[u] = 1;
    for( auto v : g[u] ){
        if( v != p ){
            dfs(v,u);
            subt[u] += subt[v];
            r[u] = max( r[u] , r[v] );
        }
    }
}

bool son(int x,int y){
    if( y == -1 ) return true;
    return ( l[x] >= l[y] ) && ( r[x] <= r[y] );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

  cin >> tc;
  while( tc-- ){
    cin >> n;
    for(int i=0; i<=n; i++){
        g[i].clear();
        l[i] = r[i] = subt[i] = ans[i] = 0;
    }
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        u++, v++;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1,1);

    int curr = 1;
    for( auto v : g[1] ){//db(subt[v])
        ans[0] += subt[v] * ( subt[v] - 1 ) / 2;
        ans[1] += subt[v] * curr;
        curr += subt[v];
    }

    vector<ii> vx;
    vx.pb({-1,-1});
    vx.pb({-1,-1});
    int bad = 1;
    for(int i=2; i<=n; i++){
        int lft = 1;
        for(int j=0; j<2; j++){
            if( son( vx[j].f , i ) ){
                //ans[i] += ans[i-1];
                lft = 0;
            }
        }
        for(int j=0; j<2; j++){
            if( son( i , vx[j].f ) && lft ){
                vx[j].f = i;
                if( vx[j].s == -1 ){
                    for(auto k : g[1] ){
                        if( son( i, k ) ){
                            vx[j].s = k;
                        }
                    }
                }
                //db(i)db(vx[j].f)db(vx[j].s)
                lft = 0;
            }
        }
        //db(lft)

        if( lft == 1 || vx[0].s == vx[1].s ) bad = 0; //db(bad)
        if( bad ){
            if( vx[1].f == -1 ){
                ans[i] += subt[vx[0].f] * ( n - subt[vx[0].s] );
            }
            else{
                ans[i] += subt[vx[0].f] * subt[vx[1].f];
            }
        }
        //db(ans[i])
        //ans[i-1] -= ans[i];
    }

    int sum = 0;
    for(int i=n; i>=1; i--){
        ans[i] -= sum;
        sum += ans[i];
    }

    for(int i=0; i<=n; i++)
        cout << ans[i] << " \n"[i==n];
  }

    return 0;
}