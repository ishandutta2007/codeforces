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
const int maxn = 100010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = 1000000007;
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

int x, y, ax, bx, ay, by, t, x0, y0, tim;
int ans;
vector<pair<ull,ull>> v;

int dist(int a,int b){
    int a1 = v[a].f - v[b].f;
    if( a1 < 0ll ) a1 *= -1ll;
    int a2 = v[a].s - v[b].s;
    if( a2 < 0ll ) a2 *= -1ll;
    return a1 + a2;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> x >> y >> ax >> ay >> bx >> by;

    cin >> x0 >> y0 >> tim;

    while( x <= x0 + 10000000000000000ll && y <= y0 + 10000000000000000ll ){
        v.push_back({x,y});
        x = ax * x + bx;
        y = ay * y + by;
    }

    stable_sort(all(v));
    v.push_back({x0,y0});

    for(int i=0; i<v.size()-1; i++){
        for(int j=i; j<v.size()-1; j++){
            if( dist( v.size()-1 , i ) + dist( i , j ) <= tim ){
                ans = max( ans , j - i + 1 );
            }
            if( dist( v.size()-1 , j ) + dist( i , j ) <= tim ){
                ans = max( ans , j - i + 1 );
            }
        }
    }

    cout << ans << '\n';

    return 0;
}