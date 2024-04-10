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
const int maxn = 500010;
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

int n, k, a[maxn], b[maxn], c[maxn], mk[maxn], st[maxn*4], dp[maxn];
vector<ii> v;
vector<int> h;

void update(int nod,int l,int r,int id,int val){
    if( l == r ){ st[nod] = val; return; }
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update(2*nod,l,mi,id,val);
        else update(2*nod+1,mi+1,r,id,val);
    st[nod] = min( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){//db(l)db(r)db(st[nod])
    if( l > y || r < x ) return mod;
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return min( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] -= i;
        v.pb({a[i],i});
    }

    v.pb({-mod,-mod});
    int cnt = 0;
    sort(all(v));
    for(int i=1; i<v.size(); i++){
        if( v[i].f != v[i-1].f ) cnt++;
        c[v[i].s] = cnt;
    }

    int mn = -mod;
    for(int i=1; i<=k; i++){
        cin >> b[i];
        mk[b[i]] = 1;
        //if( mn > a[i] ){
        //    cout << -1 << '\n';
        //    return 0;
        //}
        mn = max( mn , a[i] );
    }

    for(int i=1; i<=n; i++)
        update(1,0,n,i,mod);
    update(1,0,n,0,0);
    //db(query(1,0,n,0,0))
    h.pb(0);


    a[n+1] = mod;
    c[n+1] = n;
    mk[n+1] = 1;

    for(int i=1; i<=n+1; i++){

        dp[i] = i - 1 + query(1,0,n,0,c[i]);//db(dp[i])

        if( mk[i] ){
            while( !h.empty() ){
                update(1,0,n,h.back(),mod);
                h.pop_back();
            }
        }

        update(1,0,n,c[i],dp[i]-i);
        h.pb(c[i]);
    }

    if( dp[n+1] > n ) dp[n+1] = -1;
    cout << dp[n+1] << '\n';

    return 0;
}