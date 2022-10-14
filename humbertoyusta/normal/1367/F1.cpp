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

int tc, n, m, a[maxn], st[maxn*4], dp[maxn];
vector<int> v[maxn];

void build(int nod,int l,int r){
    if( l == r ){ st[nod] = 0; return; }
    int mi = ( l + r ) >> 1;
        build(2*nod,l,mi);
        build(2*nod+1,mi+1,r);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

void update(int nod,int l,int r,int id,int val){
    if( l == r ){ st[nod] = val; return; }
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update(2*nod,l,mi,id,val);
        else update(2*nod+1,mi+1,r,id,val);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){
    if( l > y || r < x ) return 0;
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
        int aa = query(2*nod,l,mi,x,y);
        int bb = query(2*nod+1,mi+1,r,x,y);
    return max( aa , bb );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n;

        vector<ii> compress;
        compress.pb({-1,-1});
        for(int i=1; i<=n; i++){
            cin >> a[i];
            compress.pb({a[i],i});
        }
        sort(all(compress));

        int counter = 0;
        for(int i=1; i<=n; i++){
            if( compress[i].f != compress[i-1].f ) counter++;
            a[compress[i].s] = counter;
        }

        for(int i=0; i<=n; i++){
            v[i].clear();
            dp[i] = 1;
        }
        for(int i=1; i<=n; i++){
            v[a[i]].pb(i);
        }

        build(1,1,n);

        int ans = 0;
        for(int i=1; i<=counter; i++){

            if( i - 2 >= 0 ) for( auto j : v[i-2] ) update(1,1,n,j,0);

            for(int j=0; j<v[i].size(); j++){
                //ans = max( ans , query(1,1,n,1,v[i][j]-1) + ( (int)v[i].size() - j ) );
                //db(i)db(j)db(ans)
                //update(1,1,n,v[i][j],dp[v[i][j]]);
            }

            for(int j=0; j<(int)v[i-1].size(); j++){
                update(1,1,n,v[i-1][j],0);
            }
            if( !v[i-1].empty() ) update(1,1,n,v[i-1].back(),dp[v[i-1].front()]+(int)v[i-1].size()-1);

            for(int j=0; j<(int)v[i-1].size()-1; j++){
                update(1,1,n,v[i-1][j],j+1);
            }

            for( auto j : v[i] ){
                dp[j] = max( dp[j] , query(1,1,n,1,j-1) + 1 );
                //db(i)db(j)db(dp[j])
                ans = max( ans , dp[j] );
                update(1,1,n,j,dp[j]);
            }
        }

        //for(int i=1; i<=n; i++)db(dp[i])

        cout << n - ans << '\n';
    }

    return 0;
}