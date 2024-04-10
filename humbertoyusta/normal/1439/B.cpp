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

int tc, n, m, k, dg[maxn], lft[maxn], edge[2000][2000], nid[maxn];
ii st[maxn];
vector<int> g[maxn];
map<ii,bool> mp;

void update(int nod,int l,int r,int id,int val){
    if( l == r ){
        st[nod] = {val,l};
        return;
    }
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update(2*nod,l,mi,id,val);
        else update(2*nod+1,mi+1,r,id,val);
    st[nod] = min( st[2*nod] , st[2*nod+1] );
}

ii query(int nod,int l,int r,int x,int y){
    if( l > y || r < x ) return {mod,-1};
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return min( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

bool clique(int nod){
    vector<int> w;
    w.pb(nod);
    for(auto v : g[nod]){
        if( lft[v] )
            w.pb(v);
    }
    sort(all(w));
    bool cl = 1;
    for(int i=0; i<(int)w.size()-1; i++){
        if( !cl ) break;
        for(int j=i+1; j<w.size(); j++){
            //db(w[i])db(w[j])
            //db(nid[w[i]])db(nid[w[j]])
            if( nid[w[i]] <= 0 || nid[w[i]] >= 2000 ){ cl = 0; break; }
            if( nid[w[j]] <= 0 || nid[w[j]] >= 2000 ){ cl = 0; break; }
            if( edge[nid[w[i]]][nid[w[j]]] == 0 ){
                cl = 0;
                break;
            }
        }
    }
    return cl;
}

bool clique2(int nod){
    vector<int> w;
    w.pb(nod);
    for(auto v : g[nod]){
        if( lft[v] )
            w.pb(v);
    }
    sort(all(w));
    bool cl = 1;
    for(int i=0; i<(int)w.size()-1; i++){
        if( !cl ) break;
        for(int j=i+1; j<w.size(); j++){
            //db(w[i])db(w[j])
            //db(nid[w[i]])db(nid[w[j]])
            if( mp[{min(w[i],w[j]),max(w[i],w[j])}] == 0 ){
                cl = 0;
                break;
            }
        }
    }
    return cl;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){
        mp.clear();
        cin >> n >> m >> k;
        for(int i=0; i<=3*sqrt(n+m); i++)
            for(int j=0; j<=3*sqrt(n+m); j++){
                if( i < 2000 && j < 2000 ) edge[i][j] = 0;
            }
        int cnt = 0;
        for(int i=1; i<=4*n; i++){
            st[i] = {mod,-1};
            dg[i] = 0;
            g[i].clear();
            nid[i] = 0;
            if( i <= n ) lft[i] = 1;
        }
        for(int i=1; i<=m; i++){
            int u, v;
            cin >> u >> v;
            dg[u]++;
            dg[v]++;
            g[u].pb(v);
            g[v].pb(u);
            mp[{min(u,v),max(u,v)}] = 1;
        }

        for(int i=1; i<=n; i++)
            update(1,1,n,i,dg[i]);

        bool bb = 0, ny = 1;
        for(int i=n; i>=k; i--){
            ii nxt = query(1,1,n,1,n);
            if( nxt.f >= k ){
                cout << 1 << ' ' << i << '\n';
                for(int j=1; j<=n; j++){
                    if( lft[j] )
                        cout << j << ' ';}
                cout << '\n';
                bb = 1;
                break;
            }
            if( nxt.f == k - 1 ){
                if( k > 50 ){
                if( ny == 1 ){
                    vector<int> vx;
                    vx.pb(-1);
                    for(int j=1; j<=n; j++){
                        if( lft[j] ){
                            nid[j] = ++cnt;
                            vx.pb(j);
                        }
                    }
                    for(int j=1; j<=n; j++){
                        if( lft[j] ){
                            for(int k : g[j]){
                                if( lft[k] ){
                                    edge[nid[j]][nid[k]] = 1;
                                    edge[nid[k]][nid[j]] = 1;
                                }
                            }
                        }
                    }
                    ny = 0;
                }
                if( clique(nxt.s) ){
                    cout << 2 << '\n';
                    vector<int> w;
                    w.pb(nxt.s);
                    for(auto v : g[nxt.s]){
                        if( lft[v] )
                            w.pb(v);
                    }
                    for( auto j : w )
                        cout << j << ' ';
                    cout << '\n';
                    bb = 1;
                    break;
                }
                }
                else{
                if( clique2(nxt.s) ){
                    cout << 2 << '\n';
                    vector<int> w;
                    w.pb(nxt.s);
                    for(auto v : g[nxt.s]){
                        if( lft[v] )
                            w.pb(v);
                    }
                    for( auto j : w )
                        cout << j << ' ';
                    cout << '\n';
                    bb = 1;
                    break;
                }
                }
            }
            update(1,1,n,nxt.s,mod);
            dg[nxt.s] = mod;
            lft[nxt.s] = 0;
            for( auto j : g[nxt.s] ){
                dg[j] --;
                update(1,1,n,j,dg[j]);
            }
        }
        if( !bb ) cout << -1 << '\n';
    }

    return 0;
}