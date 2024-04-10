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
const int maxn = 2020;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<62ll)-1ll)*2ll)+1ll;
const ld pi = acos(-1);
/// Prime Numbers:
// 2, 311, 331, 1009, 2011, 2027, 100003, 200003, 1000000007, 1000000021, 2000000099
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

int p[maxn], a[maxn], root, c[maxn], subt[maxn], n;
bool mk[maxn], flag;
vector<int> g[maxn];

void dfs(int u,int p){
    subt[u] = 1;
    int nxt = 1;
    for(int i=1; i<=n; i++)
        if( !mk[i] ){
            if( nxt - 1 == a[u] ){ c[u] = i; mk[i] = 1; break; }
                else nxt++;
        }
    for( auto v : g[u] ){
        if( v == p ) continue;
        dfs(v,u);
        subt[u] += subt[v];
    }
    if( a[u] >= subt[u] )
        flag = true;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> p[i] >> a[i];
        if( p[i] == 0 ) root = i;
            else g[p[i]].pb(i);
    }

    dfs(root,0);

    if( flag ){ cout << "NO" << enl; return 0; }
    cout << "YES" << enl;
    for(int i=1; i<=n; i++)
        cout << c[i] << ' ';

    return 0;
}