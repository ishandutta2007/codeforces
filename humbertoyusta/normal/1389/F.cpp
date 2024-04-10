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
const int maxn = 400010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
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
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, ac[2][maxn], dp[maxn];
ii st[maxn*4], lazy[maxn*4];
pair<ii,int> a[maxn];
vector<ii> compress;
vector<int> g1[maxn], g2[maxn];

void lazyp(int nod,int l,int r){
    st[nod].f += lazy[nod].f;
    st[nod].s += lazy[nod].s;
    if( l != r ){
        lazy[2*nod].f += lazy[nod].f;
        lazy[2*nod].s += lazy[nod].s;
        lazy[2*nod+1].f += lazy[nod].f;
        lazy[2*nod+1].s += lazy[nod].s;
    }
    lazy[nod] = { 0 , 0 };
}

ii join(ii a,ii b){
    return (ii){ max( a.f , b.f ) , max( a.s , b.s ) };
}

void update(int nod,int l,int r,int x,int y,ii val){
    lazyp(nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[nod] = val;
        lazyp(nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);
    st[nod] = join( st[2*nod] , st[2*nod+1] );
}

ii query(int nod,int l,int r,int x,int y){
    lazyp(nod,l,r);
    if( l > y || r < x ) return {-1,-1};
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return join( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    compress.pb({-1,0});
    for(int i=1; i<=n; i++){
        cin >> a[i].f.f >> a[i].f.s >> a[i].s;
        compress.pb({a[i].f.f,2*i});
        compress.pb({a[i].f.s,2*i+1});
    }

    sort(all(compress));
    int compress_count = 0;
    for(int i=1; i<compress.size(); i++){
        if( compress[i].f != compress[i-1].f )
            compress_count ++;
        if( compress[i].s % 2 == 0 ) a[compress[i].s/2].f.f = compress_count;
            else a[compress[i].s/2].f.s = compress_count;
    }

    for(int i=1; i<=n; i++){
        if( a[i].s == 1 ){
            g1[a[i].f.s].pb(a[i].f.f);
        }
        else{
            g2[a[i].f.s].pb(a[i].f.f);
        }
    }

    for(int i=1; i<=2*n; i++){
        for( auto j : g1[i] ){
            update(1,0,2*n,0,j-1,{1,0});
        }
        for( auto j : g2[i] ){
            update(1,0,2*n,0,j-1,{0,1});
        }
        ii ths = query(1,0,2*n,0,i-1);
        dp[i] = max( ths.f , ths.s );//db(dp[i])
        update(1,0,2*n,i,i,{dp[i],dp[i]});
    }

    cout << dp[2*n] << '\n';

    return 0;
}