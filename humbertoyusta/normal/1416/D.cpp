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
const int maxn = 200010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll + mod + mod;
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

struct node{
    int val, lazy, l, r;
};

int n, tl[maxn], tr[maxn], par[maxn], ran[maxn], cnt, m, q, pt[maxn];
int lv[maxn], a[maxn], id[maxn], ind[maxn], tpid[maxn], used[300005], mk[maxn];
vector<int> vnod[maxn], g[maxn];
vector<node> st[maxn];
pair<ii,ii> edge[300005];
pair<int,ii> nedges[300005];
ii queries[500005];

int find_(int x){
    return ( par[x] == x ) ? ( x ) : ( find_( par[x] ) );
}

void union_(int u,int v,int id){
    int a = find_(u), b = find_(v);
    if( a == b ) return;
    if( ran[a] < ran[b] ){
        swap( a , b );
        swap( u , v );
    }
    par[b] = a;
    ran[a] += ran[b];
    g[a].pb(b);
    g[b].pb(a);
    nedges[id].s.f = a;
    nedges[id].s.s = b;
    used[id] = 1;
}

void dfs(int u,int p){
    tl[u] = tr[u] = ++cnt;
    vnod[u].pb(tl[u]);
    for( auto v : g[u] ){
        if( v == p ) continue;
        lv[v] = lv[u] + 1;
        pt[v] = u;
        dfs(v,u);
        //tl[u] = min( tl[u] , tl[v] );
        tr[u] = max( tr[u] , tr[v] );
        for( auto i : vnod[v] )
            vnod[u].pb(i);
    }
}

void dfs2(int u,int p,int r,int t){
    mk[u] = r;
    for( auto v : g[u] ){
        if( v == p ) continue;
        if( ind[v] < t ) continue;
        dfs2(v,u,r,t);
    }
}

void lazyp(int sgt,int nod,int l,int r){
    st[sgt][nod].val = st[sgt][nod].lazy;
    if( l != -1 || r != -1 ){
        st[sgt][l].lazy = st[sgt][nod].lazy;
        st[sgt][r].lazy = st[sgt][nod].lazy;
    }
    st[sgt][nod].lazy = 0;
}

void build(int SgT,int nod,int l,int r){

    if( l == r ){
        if( mk[tpid[vnod[SgT][l]]] == SgT )
            st[SgT][nod].val = a[tpid[vnod[SgT][l]]];
        return;
    }

    int mi = ( l + r ) >> 1;

        st[SgT].pb({0,0,-1,-1});
        st[SgT][nod].l = (int)st[SgT].size() - 1;
        build(SgT,st[SgT][nod].l,l,mi);

        st[SgT].pb({0,0,-1,-1});
        st[SgT][nod].r = (int)st[SgT].size() - 1;
        build(SgT,st[SgT][nod].r,mi+1,r);

    st[SgT][nod].val = max( st[SgT][st[SgT][nod].l].val , st[SgT][st[SgT][nod].r].val );
}

void update(int sgt,int nod,int l,int r,int x,int y,int val){

    if( st[sgt][nod].lazy ) lazyp(sgt,nod,st[sgt][nod].l,st[sgt][nod].r);

    if( l > y || r < x ) return;

    if( l >= x && r <= y ){
        st[sgt][nod].lazy = val;
        lazyp(sgt,nod,st[sgt][nod].l,st[sgt][nod].r);
        return;
    }

    int mi = ( l + r ) >> 1;
        update(sgt,st[sgt][nod].l,l,mi,x,y,val);
        update(sgt,st[sgt][nod].r,mi+1,r,x,y,val);

    st[sgt][nod].val = max( st[sgt][st[sgt][nod].l].val , st[sgt][st[sgt][nod].r].val );
}

int query(int sgt,int nod,int l,int r,int x,int y){

    if( st[sgt][nod].lazy ) lazyp(sgt,nod,st[sgt][nod].l,st[sgt][nod].r);

    if( l > y || r < x ) return 0;

    if( l >= x && r <= y ) return st[sgt][nod].val;

    int mi = ( l + r ) >> 1;
        int aa = query(sgt,st[sgt][nod].l,l,mi,x,y);
        int bb = query(sgt,st[sgt][nod].r,mi+1,r,x,y);

    return max( aa , bb );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> q;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        id[a[i]] = i;
    }

    for(int i=1; i<=m; i++){
        cin >> edge[i].s.f >> edge[i].s.s;
        edge[i].f.f = mod;
        edge[i].f.s = i;
    }

    for(int i=1; i<=q; i++){
        cin >> queries[i].f >> queries[i].s;
        if( queries[i].f == 2 ){
            edge[queries[i].s].f.f = i;
        }
    }

    for(int i=1; i<=m; i++)
        nedges[i] = { edge[i].f.f , { edge[i].s.f , edge[i].s.s } };

    sort(edge+1,edge+m+1);
    reverse(edge+1,edge+m+1);

    for(int i=1; i<=n; i++){
        ran[i] = 1;
        par[i] = i;
    }

    for(int i=1; i<=m; i++){
        union_(edge[i].s.f,edge[i].s.s,edge[i].f.s);
    }

    for(int i=1; i<=n; i++){
        if( !tl[i] ){
            lv[i] = 1;
            dfs(i,i);
        }
        tpid[tl[i]] = i;
    }

    for(int i=1; i<=n; i++){
        if( lv[i] == 1 ){
            st[i].pb({0,0,-1,-1});
            dfs2(i,i,i,0);
            build(i,0,0,(int)vnod[i].size()-1);
        }
    }

    for(int i=1; i<=m; i++){
        if( used[i] ){
            //db(nedges[i].s.f)db(lv[nedges[i].s.f])
            //db(nedges[i].s.s)db(lv[nedges[i].s.s])
            //db(nedges[i].f)
            if( lv[nedges[i].s.f] + 1 == lv[nedges[i].s.s] ){
                ind[nedges[i].s.s] = nedges[i].f;
            }
            if( lv[nedges[i].s.s] + 1 == lv[nedges[i].s.f] ){
                ind[nedges[i].s.f] = nedges[i].f;
            }
        }
    }

    //for(int i=1; i<=n; i++){
    //    db(ind[i])
    //}
    //for(int i=1; i<=n; i++){
    //    db(i)
    //    for( auto j : vnod[i])
    //        db(j)
    //}

    for(int i=1; i<=q; i++){
        if( queries[i].f == 1 ){
            int u = queries[i].s;
            while( ind[u] >= i && pt[u] > 0 )
                u = pt[u];
            //db(u)
            int qt = query(u,0,0,(int)vnod[u].size()-1,0,(int)vnod[u].size()-1);
            cout << qt << '\n';
            a[id[qt]] = 0;
            int nid = lower_bound(all(vnod[u]),tl[id[qt]]) - vnod[u].begin();
            update(u,0,0,(int)vnod[u].size()-1,nid,nid,0);
        }
        if( queries[i].f == 2 ){

            int u = nedges[queries[i].s].s.f;
            int v = nedges[queries[i].s].s.s;

            if( lv[u] > lv[v] ) swap(u,v);

            if( !used[queries[i].s] ) continue;

            while( ind[u] >= i && pt[u] > 0 )
                u = pt[u];
            int nid = lower_bound(all(vnod[u]),tl[v]) - vnod[u].begin();
            int nid2 = lower_bound(all(vnod[u]),tr[v]+1) - vnod[u].begin();
            //db(nid)db(nid2-1)db(v)db(tl[v])db(tr[v])

            update(u,0,0,(int)vnod[u].size()-1,nid,nid2-1,0);

            st[v].pb({0,0,-1-1});
            dfs2(v,pt[v],v,i);
            build(v,0,0,(int)vnod[v].size()-1);

        }
    }

    return 0;
}