    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
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
const int maxn = 200010;
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
    if( e & 1 ) return qpow(b,e-1) * b;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int tc, n, k, pot[20];

int f(int x){
    int tot = INF;
    int res = n;
    int num = x;
    if( k == 0 ){
        num = 0;
        int cntt = 0;
        while( res >= 9 ){ res -= 9; num = 9 * pot[cntt++] + num; }
        num = res * pot[cntt] + num;
        return num;
    }
    bool b = 0;
    for(int i=x; i<=x+k; i++){
        if( i == 10 ) b = 1;
        res -= i % 10;
    }
    if( res < 0 ) return INF;
    if( res == 0 && !b ) return num;
    if( res == 0 && b ) return INF;

    //if(x==9)db(res)
    for(int i=0; i<=16; i++){
        if(i) num = num + 9 * pot[i];
        int f1 = min( ( 10 - x ) , (k+1) );
        int f2 = (k+1) - f1;
        int tmp = res;
        tmp -= i * 9 * f1;
        tmp -= i * 0 * f2;//if(x==9&&i==1)db(tmp)
        if( tmp < 0 ) break;
        if( tmp == 0 && f2 == 0 ) tot = min( tot , num );
        if( tmp == 0 && f2 != 0 ) tot = min( tot , INF );
        for(int j=0; j<=9; j++){
            int tmpnum = num + j * pot[i+1];
            int nxt = j + 1;
            if( nxt == 10 ) nxt = 1;
            int f3 = min( ( 10 - j ) , (k+1) );
            int f4 = (k+1) - f3;
            int tmpres = tmp - j * f1 - nxt * f2;
            if( tmpres < 0 ) break;
            if( tmpres == 0 ) tot = min( tot , tmpnum );
            if( tmpres % ( k + 1 ) == 0 ){
                int tmpnum2 = tmpnum;
                int tmpres2 = tmpres;
                int cnt = i + 1;
                while( tmpres2 ){
                    int m = 0;
                    for(int l=1; l<=9; l++)
                        if( tmpres2 - l * (k+1) >= 0 ) m = l;
                    tmpnum2 = tmpnum2 + (m) * pot[++cnt];
                    tmpres2 -= (k+1) * m;
                    if( tmpres2 < 0 ) break;
                    if( tmpres2 == 0 ){ tot = min( tot , tmpnum2 ); }
                }
            }
        }
    }
    return tot;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    pot[0] = 1;
    for(int i=1; i<20; i++)
        pot[i] = pot[i-1] * 10;

    cin >> tc;
    while( tc-- ){//db(tc)
        cin >> n >> k;
        int ans = INF;
        for(int i=0; i<=9; i++){
            ans = min( ans , f(i) );
            //db(f(i))
        }
        if( ans == INF ) cout << -1 << '\n';
            else cout << ans << '\n';
    }

    return 0;
}