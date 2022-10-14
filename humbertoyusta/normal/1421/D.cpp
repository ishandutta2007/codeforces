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
const int INF = 1ll * mod * mod;
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

int tc, a, b, c[10];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc -- ){
        cin >> a >> b;
        for(int i=1; i<=6; i++){
            cin >> c[i];
        }
        for(int i=1; i<=6; i++){
            c[1] = min( c[1] , c[2] + c[6] );
            c[2] = min( c[2] , c[3] + c[1] );
            c[3] = min( c[3] , c[4] + c[2] );
            c[4] = min( c[4] , c[5] + c[3] );
            c[5] = min( c[5] , c[6] + c[4] );
            c[6] = min( c[6] , c[1] + c[5] );
        }
        c[7] = c[1] + c[6];
        c[8] = c[3] + c[4];
        int ans = 0;
        if( a >= 0 ){
            if( b >= 0 && b <= a ){
                ans = b * c[1] + ( a - b ) * c[6];
            }
            else{
                if( b < 0 ){
                    ans = a * c[6] + ( -b ) * c[5];
                }
                else{
                    ans = a * c[1] + ( b - a ) * c[2];
                }
            }
        }
        if( a < 0 ){
            swap(c[6],c[3]);
            swap(c[1],c[4]);
            swap(c[5],c[2]);
            a = -a;
            b = -b;
            if( b >= 0 && b <= a ){
                ans = b * c[1] + ( a - b ) * c[6];
            }
            else{
                if( b < 0 ){
                    ans = a * c[6] + ( -b ) * c[5];
                }
                else{
                    ans = a * c[1] + ( b - a ) * c[2];
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}