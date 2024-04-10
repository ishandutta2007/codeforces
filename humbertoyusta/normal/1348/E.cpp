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
const int maxn = 505;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1000000000000007ll;
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
/// My Code -------------------------------------------------

int n, m, ans, x, y, a, b, z, w, xam, zm, wmd, pra1, pra2, bo1, bo2;
ii dp[maxn][maxn], arr[maxn], arrmod[maxn], bym, wm;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> arr[i].f >> arr[i].s;
        arrmod[i].f = arr[i].f % m;
        arrmod[i].s = arr[i].s % m;
    }

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = { -INF , -INF };

    dp[0][0] = { 0 , 0 };

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            if( dp[i-1][j].f <= -INF / 1000ll ) continue;
            x = j, y = dp[i-1][j].s;
            a = arr[i].f, b = arr[i].s;
            xam = ( x + a ) % m;
            bym = { dp[i-1][j].f + ( x + a ) / m + ( b + y ) / m , ( b + y ) % m };
            if( bym > dp[i][xam] )
                dp[i][xam] = bym;
            //if( a + x < m && b + y < m ) continue;
            int pra1 = ( a + x - m ) / m;
            int bo1 = m - ( a + x - m ) % m;
            int pra2 = ( b + y - m ) / m;
            int bo2 = m - ( b + y - m ) % m;
            //db(bo1)
            for(int k=0; k<=m; k++){
                if( a >= k && b >= m - k ){
                    //db(m-k)db(pra2 + ( m - k <= m - bo2 ))db(( b + y - k ) / m)
                    z = pra1 + ( k <= m - bo1 );
                    w = pra2 + ( m - k <= m - bo2 );
                    zm = arrmod[i].f - k + x;
                    if( zm < 0 ) zm += m;
                    if( zm >= m ) zm -= m;
                    wmd = arrmod[i].s - ( m - k ) + y;
                    if( wmd < 0 ) wmd += m;
                    if( wmd >= m ) wmd -= m;
                    wm = { dp[i-1][j].f + 1 + z + w , wmd };
                    if( wm > dp[i][zm] )
                        dp[i][zm] = wm;
                }
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=m; i++)
        ans = max( ans , dp[n][i].f );
    cout << ans << '\n';

    return 0;
}