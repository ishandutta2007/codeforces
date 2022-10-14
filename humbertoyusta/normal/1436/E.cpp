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
const int maxn = 100010;
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

int a[maxn], n, prv[maxn], l[maxn], r[maxn], last[maxn];
vector<pair<ii,int>> st[maxn*4];
vector<int> v[maxn];
bool mk[maxn];

void update_abi(int nod,int id){
    id ++;
    for( ; id <= st[nod].size(); id += ( id & -id ) )
        st[nod][id-1].s ++;
}

int query_abi(int nod,int id){
    id ++;
    int res = 0;
    for( ; id > 0; id -= ( id & -id ) )
        res += st[nod][id-1].s;
    return res;
}

void build(int nod,int l,int r){
    if( l == r ){
        st[nod].pb({{prv[l],0},0});
        return;
    }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    for( auto i : st[2*nod] ) st[nod].pb(i);
    for( auto i : st[2*nod+1] ) st[nod].pb(i);
    sort(all(st[nod]));
}

void update(int nod,int l,int r,int id,int val){
    int nid = lower_bound(all(st[nod]),pair<ii,int>{(ii){val,0ll},mod}) - st[nod].begin();
    nid--;
    if( nid >= 0 ) update_abi(nod,nid);
    if( l == r ) return;
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update(2*nod,l,mi,id,val);
        else update(2*nod+1,mi+1,r,id,val);
}

int query(int nod,int l,int r,int x,int y,int val){
    if( l > y || r < x ) return 0;
    if( l >= x && r <= y ){
        int nid = lower_bound(all(st[nod]),pair<ii,int>{(ii){val,0},0}) - st[nod].begin();
        nid--;
        if( nid < 0 ) return 0;
        return query_abi(nod,nid);
    }
    int mi = ( l + r ) >> 1;
    return query(2*nod,l,mi,x,y,val) + query(2*nod+1,mi+1,r,x,y,val);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        if( a[i] != 1 ) mk[1] = 1;
        prv[i] = last[a[i]];
        last[a[i]] = i;
        v[a[i]].pb(i);
    }

    for(int i=1; i<=n+1; i++){
        v[i].pb(0);
        v[i].pb(n+1);
        sort(all(v[i]));
    }

    build(1,1,n);

    for(int i=1; i<=n+1; i++){
        int tl = 1, tr = 1;
        for( auto j : v[i] ){
            tr = j - 1;
            //db(tl)db(tr)db(i)
            //if( i == 3 && tl <= tr ) db( query(1,1,n,tl,tr,tl))
            if( tl <= tr && query(1,1,n,tl,tr,tl) >= i - 1 ) mk[i] = 1;
            tl = j + 1;
        }
        for( auto j : v[i] ){
            if( j >= 1 && j <= n ) update(1,1,n,j,prv[j]);
        }
    }

    int mex = 1;
    while( mk[mex] ) mex++;
    cout << mex << '\n';

    return 0;
}