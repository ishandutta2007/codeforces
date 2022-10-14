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
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
/// Constraints:
const int maxn = 100010;
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
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
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
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

vector<int> g[maxn], vx[maxn];
int mk[maxn], val[maxn], used[maxn], ans[maxn], col[maxn];
queue<int> q;

void push(int node){
    for( auto nwn : g[node] ){
        vx[nwn].pb(val[node]);
        if( !mk[nwn] && vx[nwn].size() == 2 )
            q.push(nwn);
    }
}

void bfs(int start){
    mk[start] = 1;
    val[start] = 0;
    used[0] = 1;

    int curr = 1;
    for( auto u : g[start] ){
        mk[u] = 1;
        val[u] = curr;
        used[curr] = 1;
        push(u);
        curr *= 2;
    }

    while( !q.empty() ){

        int u = q.front();
        q.pop();
        if( mk[u] ) continue;

        int o1 = ( vx[u][0] & vx[u][1] );
        int o2 = ( ( vx[u][0] & vx[u][1] ) | ( vx[u][0] ^ vx[u][1] ) );
        if( !used[o1] ){
            val[u] = o1;
            used[o1] = 1;
            mk[u] = 1;
            push(u);
            continue;
        }
        if( !used[o2] ){
            val[u] = o2;
            used[o2] = 1;
            mk[u] = 1;
            push(u);
            continue;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=0; i<4; i++)
        col[i] = ( ( i & 2 ) > 0 );

    int p = 4;
    for(int i=4; i<(1<<16); i*=i){
        for(int j=1; j<i; j++){
            for(int k=0; k<i; k++){
                if( __builtin_popcount(j) & 1 ){
                    col[j*i+k] = ( p - 1 ) - col[k^j];
                }
                else{
                    col[j*i+k] = col[k^j];
                }
            }
        }
        p += p;
    }

//    for(int i=0; i<16*16; i++)
//        db(col[i])

    int tc;
    cin >> tc;
    //tc = 1;
    while( tc-- ){
        int n;
        cin >> n;

        for(int i=0; i<(1<<n); i++){
            g[i].clear();
            vx[i].clear();
            mk[i] = 0;
            val[i] = 0;
            used[i] = 0;
            ans[i] = 0;
        }

        for(int i=0; i<n*(1<<(n-1)); i++){
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        bfs(0);

        for(int i=0; i<(1<<n); i++){
            //db(used[i])
            ans[val[i]] = i;
        }

        for(int i=0; i<(1<<n); i++)
            cout << ans[i] << " \n"[i+1==(1<<n)];

        if( __builtin_popcount(n) != 1 ){
            cout << -1 << '\n';
            continue;
        }

        for(int i=0; i<(1<<n); i++)
            cout << col[val[i]] << " \n"[i+1==(1<<n)];
    }

    return 0;
}