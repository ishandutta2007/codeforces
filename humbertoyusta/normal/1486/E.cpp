    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
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
typedef unsigned long long ull;
/// Constraints:
const int maxn = 100010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2 * mod;
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

int n, m, mk[maxn*55], d[maxn*55];
pair<ii,int> edge[maxn*2];
vector<ii> g[maxn*55];

int encode(int i,int j){
    return i * 51 + j;
}

void dijkstra(int start){
    priority_queue<ii> q;
    q.push({0,start});
    d[start] = 0;
    while( !q.empty() ){
        int u = q.top().s;
        if( -q.top().f > d[u] ){
            q.pop();
            continue;
        }
        q.pop();

        for( auto v : g[u] ){
            if( d[v.f] > d[u] + v.s ){
                d[v.f] = d[u] + v.s;
                q.push({-d[v.f],v.f});
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

    cin >> n >> m;

    for(int i=1; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[encode(u,w)].pb({encode(v,0),0});
        g[encode(v,w)].pb({encode(u,0),0});
        mk[encode(u,w)] = 1;
        mk[encode(v,w)] = 1;
        edge[i] = { { u , v } , w };
    }

    for(int i=1; i<=m; i++){
        int u, v, w;
        u = edge[i].f.f;
        v = edge[i].f.s;
        w = edge[i].s;
        for(int j=1; j<=50; j++){
            if( !mk[encode(v,j)] ) continue;
            g[encode(u,0)].pb({encode(v,j),w*w+j*j+2*w*j});
        }
        for(int j=1; j<=50; j++){
            if( !mk[encode(u,j)] ) continue;
            g[encode(v,0)].pb({encode(u,j),w*w+j*j+2*w*j});
        }
    }

    for(int i=0; i<maxn*55; i++)
        d[i] = INF;

    dijkstra(encode(1,0));
    for(int i=1; i<=n; i++){
        if( d[encode(i,0)] >= INF ) d[encode(i,0)] = -1;
        cout << d[encode(i,0)] << " \n"[i==n];
    }

    return 0;
}