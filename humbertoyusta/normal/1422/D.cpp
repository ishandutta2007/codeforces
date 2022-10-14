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
const int maxn = 1000010;
const int mod = 1000000007;
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

int n, m, d[maxn];
pair<ii,int> a[maxn];
vector<ii> g[maxn];
priority_queue<ii> q;

void dijkstra(){
    d[0] = 0;
    q.push({0,0});
    while( !q.empty() ){
        int u = q.top().s;
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

    cin >> a[0].f.f >> a[0].f.s;
    cin >> a[m+1].f.f >> a[m+1].f.s;
    a[0].s = 0;
    a[m+1].s = m + 1;

    for(int i=1; i<=m; i++){
        cin >> a[i].f.f >> a[i].f.s;
        a[i].s = i;
        g[0].pb({i,min(abs(a[0].f.f-a[i].f.f),abs(a[0].f.s-a[i].f.s))});
        g[i].pb({m+1,abs(a[m+1].f.f-a[i].f.f)+abs(a[m+1].f.s-a[i].f.s)});
    }

    sort(a+1,a+m+1);

    for(int i=1; i<m; i++){
        int u = a[i].s;
        int v = a[i+1].s;
        g[u].pb({v,min(abs(a[i].f.f-a[i+1].f.f),abs(a[i].f.s-a[i+1].f.s))});
        g[v].pb({u,min(abs(a[i].f.f-a[i+1].f.f),abs(a[i].f.s-a[i+1].f.s))});
    }

    for(int i=1; i<=m; i++){
        swap(a[i].f.f,a[i].f.s);
    }

    sort(a+1,a+m+1);

    for(int i=1; i<m; i++){
        int u = a[i].s;
        int v = a[i+1].s;
        g[u].pb({v,min(abs(a[i].f.f-a[i+1].f.f),abs(a[i].f.s-a[i+1].f.s))});
        g[v].pb({u,min(abs(a[i].f.f-a[i+1].f.f),abs(a[i].f.s-a[i+1].f.s))});
    }

    for(int i=0; i<=m+1; i++)
        d[i] = INF;

    d[m+1] = abs( a[0].f.f - a[m+1].f.f ) + abs( a[0].f.s - a[m+1].f.s );
    dijkstra();

    cout << d[m+1] << '\n';

    return 0;
}