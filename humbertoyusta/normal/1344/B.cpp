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
const int maxn = 1010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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

int mnx(mod), mny(mod), mxx, mxy;
int n, m, comp[maxn][maxn], minrow[maxn], maxrow[maxn], mincol[maxn], maxcol[maxn], cntr[maxn], cntc[maxn];
bool a[maxn][maxn];
set<int> row[maxn], col[maxn];

void dfs(int x,int y,int c){
    comp[x][y] = c;
    cntr[x]++;
    cntc[y]++;
    row[x].insert(c);
    col[y].insert(c);
    if( comp[x+1][y] == 0 && a[x+1][y] == 1 )
        dfs(x+1,y,c);
    if( comp[x][y+1] == 0 && a[x][y+1] == 1 )
        dfs(x,y+1,c);
    if( comp[x-1][y] == 0 && a[x-1][y] == 1 )
        dfs(x-1,y,c);
    if( comp[x][y-1] == 0 && a[x][y-1] == 1 )
        dfs(x,y-1,c);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    int sum = 0;

    for(int i=0; i<=max(n,m+1); i++)
        mincol[i] = minrow[i] = mod, maxrow[i] = maxcol[i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char u;
            cin >> u;
            if( u == '#' ){
                sum++;
                a[i][j] = 1;
                minrow[i] = min( minrow[i] , j );
                maxrow[i] = max( maxrow[i] , j );
                mincol[j] = min( mincol[j] , i );
                maxcol[j] = max( maxcol[j] , i );
            }
            if( u == '.' ) a[i][j] = 0;
        }
    }

    if( sum == 0 ){
        cout << 0;
        return 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if( maxrow[i] < minrow[i] && maxcol[j] < mincol[j] ){
                row[i].insert(-1);
                col[j].insert(-1);
            }
        }
    }

    int cc = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if( !comp[i][j] && a[i][j] == 1 )
                dfs(i,j,++cc);

    for(int i=1; i<=n; i++)
        if( row[i].size() != 1 ){
            cout << -1;
            return 0;
        }

    for(int i=1; i<=m; i++)
        if( col[i].size() != 1 ){
            cout << -1;
            return 0;
        }

    for(int i=1; i<=n; i++){
        if( minrow[i] > maxrow[i] ) continue;
        if( cntr[i] != maxrow[i] - minrow[i] + 1 ){
            cout << -1;
            return 0;
        }
    }

    for(int i=1; i<=m; i++){
        if( mincol[i] > maxcol[i] ) continue;
        if( cntc[i] != maxcol[i] - mincol[i] + 1 ){
            cout << -1;
            return 0;
        }
    }

    cout << cc << '\n';

    return 0;
}