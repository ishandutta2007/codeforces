    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = (1<<18) + 10;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
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

int tc, n, st[4*maxn], flag[22], a[maxn], lv[maxn*4], m;

void build(int nod,int l,int r){
    if( l == r ){ st[nod] = a[l]; return; }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    st[nod] = ( st[2*nod] + st[2*nod+1] );
}

void update(int nod,int l,int r,int id,int val){
    if( l == r ){ st[nod] = val; return; }
    int mi = ( l + r ) >> 1;
    if( id <= mi ){
        if( !flag[lv[nod]] ) update(2*nod,l,mi,id,val);
            else update(2*nod+1,l,mi,id,val);
    }
    else{
        if( !flag[lv[nod]] ) update(2*nod+1,mi+1,r,id,val);
            else update(2*nod,mi+1,r,id,val);
    }
    st[nod] = ( st[2*nod] + st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){
    if( l > y || r < x ) return 0;
    if( l >= x && r <= y ){ return st[nod]; }
    int mi = ( l + r ) >> 1;
        int aa = 0;
        if( !flag[lv[nod]] ) aa = query(2*nod,l,mi,x,y);
            else aa = query(2*nod+1,l,mi,x,y);
        int bb = 0;
        if( !flag[lv[nod]] ) bb = query(2*nod+1,mi+1,r,x,y);
            else bb = query(2*nod,mi+1,r,x,y);
    return aa + bb;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=1; i<maxn*4; i++)
        lv[i] = lv[i-1] + ( __builtin_popcountll(i) == 1 );

    cin >> n >> m;

    for(int i=1; i<=(1<<n); i++){
        cin >> a[i];
    }

    build(1,1,(1<<n));

    for(int i=1; i<=m; i++){
        int op;
        cin >> op;
        if( op == 1 ){
            int id, val;
            cin >> id >> val;
            update(1,1,(1<<n),id,val);
        }
        if( op == 2 ){
            int k;
            cin >> k;
            for(int i=n; i>n-k; i--)
                flag[i] ^= 1;
        }
        if( op == 3 ){
            int k;
            cin >> k;
            flag[n-k] ^= 1;
        }
        if( op == 4 ){
            int x, y;
            cin >> x >> y;
            cout << query(1,1,(1<<n),x,y) << '\n';
        }
    }

    //for(int i=1; i<=(1<<n); i++)db(query(1,1,(1<<n),i,i))

    return 0;
}