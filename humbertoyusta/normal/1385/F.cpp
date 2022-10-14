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
const int maxn = 200010;
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

int tc, n, k;
ii st[maxn*4];
set<int> g[maxn];

void build(int nod,int l,int r){
    if( l == r ){
        st[nod] = { 0 , l };
        return;
    }
    int mid = ( l + r ) >> 1;
        build(2*nod,l,mid);
        build(2*nod+1,mid+1,r);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

void update(int nod,int l,int r,int id,int val){
    if( l == r ){
        st[nod].f += val;
        return;
    }
    int mid = ( l + r ) >> 1;
    if( id <= mid ) update(2*nod,l,mid,id,val);
        else update(2*nod+1,mid+1,r,id,val);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

ii query(int nod,int l,int r,int x,int y){
    if( l > y || r < x ) return {-1,-1};
    if( l >= x && r <= y ) return st[nod];
    int mid = ( l + r ) >> 1;
    return max( query(2*nod,l,mid,x,y) , query(2*nod+1,mid+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n >> k;

        for(int i=1; i<=n; i++){
            g[i].clear();
        }

        build(1,1,n);

        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            g[u].insert(v);
            g[v].insert(u);
        }

        for(int i=1; i<=n; i++)
            if( g[i].size() == 1 ){
                update(1,1,n,*g[i].begin(),1);
            }

        int ans = 0;
        int sz = n;
        for(int t=1; t<=n; t++){
            ii nxt = query(1,1,n,1,n);
            if( nxt.f < k ) break;
            if( sz - k == 0 ) break;
            queue<int> q;
            int cnt = 0;
            for( auto i : g[nxt.s] )
                if( g[i].size() == 1 ){
                    q.push(i);
                    cnt++;
                    if( cnt == k ) break;
                }
            while( !q.empty() ){
                int u = q.front();
                q.pop();
                g[u].erase(nxt.s);
                g[nxt.s].erase(u);
            }
            sz -= k;
            update(1,1,n,nxt.s,-k);
            if( g[nxt.s].size() == 1 ){
                update(1,1,n,*g[nxt.s].begin(),1);
            }
            ans ++;
        }
        cout << ans << '\n';
    }

    return 0;
}