/**   Created by: Humberto Yusta
      Codeforces User: humbertoyusta
      Country: Cuba
      Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const int mod = 10000000007;
const ld eps = 1e-9;
const int inf = 10000000007;
const int INF = (((1ll<<60ll)-1ll)*2ll)+1ll;
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
    int pwur = qpow(b,e>>1);
    return ( pwur * pwur ) % mod * ( b * ( e & 1 ) ) % mod;
}
/// My Code -------------------------------------------------

int n, m, p, dp[maxn], st[maxn*5], lazy[maxn*5];
ii a[maxn];
vector<ii> q[maxn];

void lazyp(int nod,int l,int r){
    st[nod] += lazy[nod];
    if( l != r ){
        lazy[2*nod] += lazy[nod];
        lazy[2*nod+1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void build(int nod,int l,int r){
    if( l == r ){
        st[nod] = -dp[l];
        return;
    }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

void update(int nod,int l,int r,int x,int y,int val){
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
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> p;
    fill( dp , dp + maxn , inf );

    for(int i=1; i<=n; i++)
        cin >> a[i].f >> a[i].s;
    stable_sort( a + 1 , a + n + 1 );
    dp[maxn-1] = inf;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        dp[u] = min(dp[u],v);
    }
    for(int i=maxn-2; i>=1; i--)
        dp[i] = min( dp[i+1] , dp[i] );

    build(1,1,maxn-1);

    for(int i=1; i<=p; i++){
        int u, v, w;
        cin >> u >> v >> w;
        q[u].pb({v,w});
    }

    int ans = -(inf*2);
    for(int i=1; i<=n; i++){
        for(int j=a[i-1].f; j<=a[i].f-1; j++)
            for( auto k : q[j] )
                update(1,1,maxn-1,k.f+1,maxn-1,k.s);
        lazyp(1,1,maxn-1);
        ans = max( ans , st[1] - a[i].s );
    }
    cout << ans << '\n';

    return 0;
}