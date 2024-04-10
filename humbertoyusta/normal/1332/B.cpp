    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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

int a[maxn], mp[maxn], color[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    //2, 3, 5, 7, 11, 13, 17, 19 , 23, 29, 31, 33;

    int tc; cin >> tc;
    while( tc-- ){
        int n, m;
        cin >> n; m = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            if( a[i] % 2 == 0 ) color[i] = 1;
            if( a[i] % 3 == 0 ) color[i] = 2;
            if( a[i] % 5 == 0 ) color[i] = 3;
            if( a[i] % 7 == 0 ) color[i] = 4;
            if( a[i] % 11 == 0 ) color[i] = 5;
            if( a[i] % 13 == 0 ) color[i] = 6;
            if( a[i] % 17 == 0 ) color[i] = 7;
            if( a[i] % 19 == 0 ) color[i] = 8;
            if( a[i] % 23 == 0 ) color[i] = 9;
            if( a[i] % 29 == 0 ) color[i] = 10;
            if( a[i] % 31 == 0 ) color[i] = 11;
        }
        for(int i=1; i<=11; i++)
            mp[i] = 0;
        for(int i=1; i<=n; i++)
            if( !mp[color[i]] )
                mp[color[i]] = ++m;
        cout << m << '\n';
        for(int i=1; i<=n; i++){
            cout << mp[color[i]];
            if( i < n ) cout << ' ';
                else cout << '\n';
        }
    }


    return 0;
}