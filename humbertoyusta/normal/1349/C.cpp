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
const int INF = 1000000000000000007ll;
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

int n, m, q, a[maxn][maxn], dist[2][maxn][maxn];
deque<ii> q0, q1;

void bfs0(){
    while( !q0.empty() ){
        ii u = q0.front(); q0.pop_front();
        if( u.f == 0 || u.f == n+1 ) continue;
        if( u.s == 0 || u.s == m+1 ) continue;

            ii v = {u.f-1,u.s};
        if( dist[0][v.f][v.s] > dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[0][v.f][v.s] = dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q0.push_front(v);
                else q0.push_back(v);
        }

            v = {u.f+1,u.s};
        if( dist[0][v.f][v.s] > dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[0][v.f][v.s] = dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q0.push_front(v);
                else q0.push_back(v);
        }
            v = {u.f,u.s-1};
        if( dist[0][v.f][v.s] > dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[0][v.f][v.s] = dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q0.push_front(v);
                else q0.push_back(v);
        }
            v = {u.f,u.s+1};
        if( dist[0][v.f][v.s] > dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[0][v.f][v.s] = dist[0][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q0.push_front(v);
                else q0.push_back(v);
        }
    }
}

void bfs1(){
    while( !q1.empty() ){
        ii u = q1.front(); q1.pop_front();
        if( u.f == 0 || u.f == n+1 ) continue;
        if( u.s == 0 || u.s == m+1 ) continue;

            ii v = {u.f-1,u.s};
        if( dist[1][v.f][v.s] > dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[1][v.f][v.s] = dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q1.push_front(v);
                else q1.push_back(v);
        }

            v = {u.f+1,u.s};
        if( dist[1][v.f][v.s] > dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[1][v.f][v.s] = dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q1.push_front(v);
                else q1.push_back(v);
        }
            v = {u.f,u.s-1};
        if( dist[1][v.f][v.s] > dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[1][v.f][v.s] = dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q1.push_front(v);
                else q1.push_back(v);
        }
            v = {u.f,u.s+1};
        if( dist[1][v.f][v.s] > dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] ) ){
            dist[1][v.f][v.s] = dist[1][u.f][u.s] + ( a[u.f][u.s] != a[v.f][v.s] );
            if( ( a[u.f][u.s] == a[v.f][v.s] ) ) q1.push_front(v);
                else q1.push_back(v);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m >> q;

    for(int i=0; i<2; i++)
        for(int k=0; k<maxn; k++)
            for(int j=0; j<maxn; j++)
                dist[i][k][j] = INF;

    for(int i=1; i<=n; i++){
        string pra;
        cin >> pra;
        for(int j=1; j<=m; j++){
            if( pra[j-1] == '1' ) a[i][j] = 1;
                else a[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            vector<int> v;
            bool swp = 0;
            if( i > 1 ) v.pb(a[i-1][j]);
            if( i < n ) v.pb(a[i+1][j]);
            if( j > 1 ) v.pb(a[i][j-1]);
            if( j < m ) v.pb(a[i][j+1]);
            for( auto k : v )
                if( k == a[i][j] )
                    swp = 1;
            if( swp ){
                if( a[i][j] == 0 ){ q0.pb({i,j}); dist[0][i][j] = 1; }
                if( a[i][j] == 1 ){ q1.pb({i,j}); dist[1][i][j] = 1; }
            }
        }
    }

    bfs0();
    bfs1();

    for(int i=1; i<=q; i++){
        int u, v, w;
        cin >> u >> v >> w;
        //db(dist[1][u][v])
        if( dist[0][u][v] > w && dist[1][u][v] > w ){
            cout << a[u][v] << '\n';
            continue;
        }
        if( dist[0][u][v] < dist[1][u][v] ){
            cout << ( a[u][v] ^ ( ( w - dist[0][u][v] + 1 ) % 2 ) ) << '\n';
            continue;
        }
        if( dist[0][u][v] >= dist[1][u][v] ){
            int p = ( dist[1][u][v] ) % 2;
            cout << ( a[u][v] ^ ( ( w - dist[1][u][v] + 1 ) % 2 ) ) << '\n';
            continue;
        }
    }

    return 0;
}