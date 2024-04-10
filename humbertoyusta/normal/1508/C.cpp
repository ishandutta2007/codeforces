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
const int maxn = 400010;
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

int tc, comp[maxn], p[maxn], xtra, nedge, p2[maxn];
set<int> g[maxn], s;

int find_(int x){
    return ( p[x] == x ) ? ( x ) : ( p[x] = find_( p[x] ) );
}

int find_2(int x){
    return ( p2[x] == x ) ? ( x ) : ( p2[x] = find_2( p2[x] ) );
}

void bfs(int nod,int c){
    queue<int> q;
    q.push(nod);
    comp[nod] = c;
    s.erase(nod);
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        stack<int> p;

        for( auto v : s ){
            if( *g[u].lower_bound(v) != v ){
                q.push(v);
                p.push(v);
                comp[v] = c;
            }
        }

        while( !p.empty() ){
            s.erase(p.top());
            nedge ++;
            p.pop();
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    tc = 1;
    while( tc-- ){

        int n, m;
        cin >> n >> m;
        s.clear();
        nedge = 0;
        for(int i=1; i<=n; i++){
            g[i].clear();
            g[i].insert(inf);
        }
        vector<pair<ii,int>> e;

        for(int i=1; i<=m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].insert(v);
            g[v].insert(u);
            e.pb({{u,v},w});
            xtra ^= w;
        }
        for(int i=1; i<=n; i++){
            s.insert(i);
        }

        int cc = 0;
        while( !s.empty() )
            bfs( *s.begin() , ++cc );

        if( nedge < ( n ) * ( n - 1 ) / 2 - m ) xtra = 0;

        vector<pair<int,ii>> edge;
        vector<pair<int,ii>> edge2;
        for(int i=1; i<=n; i++){
            p[comp[i]] = comp[i];
            p2[i] = i;
        }
        for(auto i : e){
            if( comp[i.f.f] == comp[i.f.s] ){
                xtra = min( xtra , i.s );
            }
            else{
                edge.pb({i.s,{comp[i.f.f],comp[i.f.s]}});
                edge2.pb({i.s,{i.f.f,i.f.s}});
            }
        }
        //sort(all(edge));
        sort(all(edge2));
        int ans = 0;
        for( auto i : edge2 ){
            int x = find_(comp[i.s.f]), y = find_(comp[i.s.s]);
            int nx = find_2(i.s.f), ny = find_2(i.s.s);
            if( x == y ){
                if( nx == ny )
                    continue;
                xtra = min( xtra , i.f );
                //p2[nx] = ny;
                continue;
            }
            if( nx != ny )
                p2[nx] = ny;
            p[x] = y;
            ans += i.f;
        }
        cout << ans + xtra << '\n';
    }

    return 0;
}