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

int n, a[40][40], q;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    for(int i=2; i<2*n-1; i++){
        int x = min(n,i);
        int y = i - x + 1;
        int val1 = (1ll<<(i-2));
        int val2 = 0;
        int xmod = 1;
        while( x > 0 && y < n + 1 ){
            if( xmod ) a[x][y] = val1;
                else a[x][y] = val2;
            xmod = ( ( xmod + 1 ) & 1 );
            x--, y++;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j];
            if( j < n ) cout << ' ';
                else cout << '\n';
        }
    }

    cout.flush();
    cin >> q;

    for(int i=1; i<=q; i++){
        int s;
        cin >> s;
        int x = 1, y = 1;
        for(int i=1; i<=2*n-1; i++){
            cout << x << ' ' << y << '\n';
            if( i == 2 * n - 2 ){
                if( x < y ) x++;
                    else y++;
                continue;
            }
            if( i == 1 ){
                if( ( s & 1 ) ) x++;
                    else y++;
            }
            else{
                i--;
                if( ( s & (1ll<<(i-1)) ) ){
                    if( ( s & (1ll<<i) ) ){
                        if( i < n - 1 ) x++;
                            else y++;
                    }
                    else{
                        if( i < n - 1 ) y++;
                            else x++;
                    }
                }
                if( !( s & (1ll<<(i-1)) ) ){
                    if( ( s & (1ll<<i) ) ){
                        if( i < n - 1 ) y++;
                            else x++;
                    }
                    else{
                        if( i < n - 1 ) x++;
                            else y++;
                    }
                }
                i++;
            }
        }
        cout.flush();
    }

    return 0;
}