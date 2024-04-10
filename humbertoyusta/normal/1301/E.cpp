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
const int maxn = 503;
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

int n, m, q, dp[maxn][maxn][maxn], ac[maxn][maxn][4], f[maxn][maxn];
char a[maxn][maxn];

bool queryk(int i1,int j1,int i2,int j2,int ff){
    if( i2 < i1 || j2 < j1 ) return 0;
    return ( dp[i2][j2][ff] - dp[i2][j1-1][ff] - dp[i1-1][j2][ff] + dp[i1-1][j1-1][ff] != 0 );
}

int query(int i1,int j1,int i2,int j2,int ff){
    return ac[i2][j2][ff] - ac[i2][j1-1][ff] - ac[i1-1][j2][ff] + ac[i1-1][j1-1][ff];
}

bool check(int i,int j,int sz){
    int sz2 = sz >> 1;
    //if( i == 1 && j == 1 && sz == 4 ) db(query(i,j,i+sz2-1,j+sz2-1,0))
    bool b1 = ( query(i,j,i+sz2-1,j+sz2-1,0) == ( (sz2) * (sz2) ) );
    bool b2 = ( query(i+sz2,j,i+sz-1,j+sz2-1,2) == ( (sz2) * (sz2) ) );
    bool b3 = ( query(i,j+sz2,i+sz2-1,j+sz-1,1) == ( (sz2) * (sz2) ) );
    bool b4 = ( query(i+sz2,j+sz2,i+sz-1,j+sz-1,3) == ( (sz2) * (sz2) ) );
    return ( ( b1 && b2 ) && ( b3 && b4 ) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m >> q;

    for(int i=1; i<=n; i++){
        cin >> ( a[i] + 1 );
        for(int j=1; j<=m; j++){
            ac[i][j][0] = ac[i][j-1][0] + ac[i-1][j][0] - ac[i-1][j-1][0] + ( a[i][j] == 'R' );
            ac[i][j][1] = ac[i][j-1][1] + ac[i-1][j][1] - ac[i-1][j-1][1] + ( a[i][j] == 'G' );
            ac[i][j][2] = ac[i][j-1][2] + ac[i-1][j][2] - ac[i-1][j-1][2] + ( a[i][j] == 'Y' );
            ac[i][j][3] = ac[i][j-1][3] + ac[i-1][j][3] - ac[i-1][j-1][3] + ( a[i][j] == 'B' );
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=2; i+k-1<=n && j+k-1<=m; k+=2){
                if( check(i,j,k) ) f[i][j] = k;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=min(n,m); k++){
                dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k] + ( f[i][j] == 2 * k );
                //dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k] + ( f[i][j] == k );
                //dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k] + ( f[i][j] == k );
                //dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k] + ( f[i][j] == k );
            }
        }
    }

    //db(dp[2][0][2])
    //db(queryk(2,2,2,2,1))
    for(int i=1; i<=q; i++){
        int u, v, w, y;
        cin >> u >> v >> w >> y;
        int l=0, r = 1000;//( min(w-u+1,y-v+1) + 1 ) / 2;
        while( l < r ){
            int mi = ( l + r ) >> 1;
            //if( i == 3 ){ db(u)db(v)db(w-2*l+1)db(y-2*l+1) }
            if( queryk(u,v,w-2*mi+1,y-2*mi+1,mi) ) l = mi + 1;
                else r = mi;
        }
        if( !queryk(u,v,w-2*l+1,y-2*l+1,l) ) l--;
        if( queryk(u,v,w-2*(l+1)+1,y-2*(l+1)+1,l+1) ) l++;
        //db(l)
        if( l < 0 ) l = 0;
        cout << l * 2 * l * 2 << '\n';
    }

    return 0;
}