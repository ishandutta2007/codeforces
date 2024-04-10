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

int tc, n, m, a[maxn];
ii b[maxn], c[maxn];
vector<ii> qu[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> b[i].f >> b[i].s;

    for(int i=1; i<=m; i++)
        cin >> c[i].f >> c[i].s;

    sort(c+1,c+m+1);

    vector<ii> q;
    q.push_back({-1,mod});
    q.push_back(c[1]);
    for(int i=2; i<=m; i++){
        while( q.back().s <= c[i].s ) q.pop_back();
        q.push_back(c[i]);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<q.size(); j++){
            int x = q[j-1].f + 1 - b[i].f;
            int y = q[j].f - b[i].f;
            if( y < 0 ) continue;
            if( x < 0 ) x = 0;
            qu[x].pb({max( 0ll , q[j].s - b[i].s + 1 ),1});
            qu[y+1].pb({max( 0ll , q[j].s - b[i].s + 1 ),0});
        }
    }

    int ans = mod;
    multiset<int> s;
    for(int i=0; i<=1000000; i++){
        for( auto j : qu[i] ){
            if( j.s == 0 ) s.erase(s.lower_bound(-j.f));
                else s.insert(-j.f);
        }
        if( !s.empty() ){
            int x = -(*s.begin());
            ans = min( ans , x + i );
        }
        else{
            ans = min( ans , i );
        }
    }
    cout << ans << '\n';

    return 0;
}