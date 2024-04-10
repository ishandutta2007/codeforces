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
const int maxn = 1000010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1ll + mod + mod;
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

int n, m, a[maxn], b[maxn], p[maxn], ans, cnt;
vector<pair<int,ii>> edge;
vector<ii> vx[maxn], vy[maxn];
map<ii,int> mp;

int find_(int x){
    return ( p[x] == x ) ? ( x ) : ( p[x] = find_( p[x] ) );
}

bool union_(int u,int v){
    u = find_(u), v = find_(v);
    if( u == v ) return 0;
    p[v] = u;
    return 1;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int j=1; j<=m; j++)
        cin >> b[j];

    for(int i=1; i<=n; i++){
        int u;
        cin >> u;
        for(int j=1; j<=u; j++){
            int w;
            cin >> w;
            cnt++;
            vx[i].pb({w,cnt});
            vy[w].pb({i,cnt});
            edge.pb({mod+mod,{(cnt-1)*4+1,(cnt-1)*4+3}});
            edge.pb({mod+mod,{(cnt-1)*4+2,(cnt-1)*4+4}});
            edge.pb({a[i]+b[w],{(cnt-1)*4+1,(cnt-1)*4+2}});
        }
    }

    for(int i=1; i<=n; i++){
        sort(all(vx[i]));
        for(int j=0; j<vx[i].size(); j++){
            if( j ){
                edge.pb({mod+mod,{(vx[i][j].s-1)*4+1,(vx[i][j-1].s-1)*4+3}});
            }
        }
    }

    for(int i=1; i<=m; i++){
        sort(all(vy[i]));
        for(int j=0; j<vy[i].size(); j++){
            if( j ){
                edge.pb({mod+mod,{(vy[i][j].s-1)*4+2,(vy[i][j-1].s-1)*4+4}});
            }
        }
    }

    sort(all(edge));
    reverse(all(edge));

    for(int i=0; i<maxn; i++)
        p[i] = i;

    for( auto i : edge )
        if( !union_(i.s.f,i.s.s) )
            ans += i.f;

    cout << ans << '\n';

    return 0;
}