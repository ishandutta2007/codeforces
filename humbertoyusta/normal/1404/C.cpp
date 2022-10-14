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
const int maxn = 300060;
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

int tc, n, q, val[maxn], a[maxn];
vector<int> v[maxn], abi2[maxn];
int st[maxn*4], lazy[maxn*4];

void lazyp(int nod,int l,int r){
    st[nod] += lazy[nod];
    if( l != r ){
        lazy[2*nod] += lazy[nod];
        lazy[2*nod+1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod,int l,int r,int x,int y,int val){
    if( lazy[nod] ) lazyp(nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[nod] = val;
        lazyp(nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);
    st[nod] = min( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r){
    if( lazy[nod] ) lazyp(nod,l,r);
    int mi = ( l + r ) >> 1;
    if( l != r ){
        if( lazy[2*nod] ) lazyp(2*nod,l,mi);
        if( lazy[2*nod+1] ) lazyp(2*nod+1,mi+1,r);
    }
    if( l == r ){
        if( st[nod] == 0 ) return l;
            else return -1;
    }
    if( st[2*nod+1] <= st[2*nod] ) return query(2*nod+1,mi+1,r);
        else return query(2*nod,l,mi);
}

void update2(int id,int val){
    for( ; id < maxn; id += ( id & -id ) )
        abi2[id].pb(val);
}

int query2(int id,int val){
    int res = 0;
    for( ; id > 0; id -= ( id & -id ) )
        res += ( abi2[id].end() - lower_bound(all(abi2[id]),val) );
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> q;

    for(int i=1; i<=n*4; i++) st[i] = INF;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] -= i;
        a[i] = -a[i];
        if( a[i] < 0 ) a[i] = INF;
        update(1,1,n,i,i,-(INF-a[i]));
    }

    int mn = INF;
    while( true ){
        int x = query(1,1,n);
        if( x == -1 ) break;
        mn = min( mn , x );
        val[x] = mn;
        if( x + 1 <= n )
            update(1,1,n,x+1,n,-1);
        update(1,1,n,x,x,INF);
        //db(x)db(val[x])
    }

    for(int i=1; i<=n; i++){
        update2(i,val[i]);
        //db(val[i])
    }

    for(int i=1; i<maxn; i++){
        //abi2[i].pb(-1);
        sort(all(abi2[i]));
    }

    for(int i=1; i<=q; i++){
        int u, v;
        cin >> u >> v;
        u = u + 1;
        v = n - v;
        cout << query2(v,u) - query2(u-1,u) << '\n';
    }

    return 0;
}