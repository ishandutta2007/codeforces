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
const int maxn = 202;
const int mod = 1000000007;
const int mod2 = 998244353;
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

int n, x, y, req, md, prv, cc, cost[maxn], sum[1<<22], mk[maxn], dp[2][1<<22];

int has(int x_){
    if( x_ < 0 ) return 0;
        else return mk[x_];
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);


    cin >> n >> x >> y;

    if( x > y ) swap( x , y );

    req = x + y;

    prv = 0;
    md = 0;
    cc = 1;

    if( n <= x + y + x + y ){
        req = n;
        for(int i=1; i<=n; i++)
            cost[i] = 1;
    }
    else{

        prv = 0;
        md = ( n ) % ( x + y );
        cc = ( n ) / ( x + y );

        for(int i=prv+1; i<=req; i++)
            cost[i] += cc;
        for(int i=1; i<=prv+md; i++)
            cost[i] ++;

    }

    if( n <= x + y + x + y ){
        if( req < y )
            req = y;
        for(int i=0; i<(1<<y); i++){
            bool can = 1;
            for(int j=x; j<y; j++){
                if( !can ) break;
                if( ( i & (1<<j) ) != 0 && ( i & (1<<(j-x)) ) != 0 ){
                    can = 0;
                }
            }
            if( !can ) continue;
            int tcost = 0;
            for(int j=0; j<y; j++)
                tcost += cost[j+1] * ( ( i & (1<<j) ) != 0 );
            dp[(y)%2][i] = max( dp[(y)%2][i] , tcost );
        }

        int ans = 0;
        for(int i=y; i<req; i++){
            fill( dp[(i+1)&1] , dp[(i+1)&1] + (1<<(y)) , 0 );
            for(int j=0; j<(1<<(y)); j++){

                int nw1 = ( (j>>1) | (1<<(y-1)) );

                if( ( x == y || ( nw1 & (1<<(y-x-1)) ) == 0 ) && ( j & 1 ) == 0 ){
                    dp[(i+1)&1][nw1] = max( dp[(i+1)&1][nw1] , dp[i&1][j] + cost[i+1] );
                }

                int nw2 = (j>>1);

                dp[(i+1)&1][nw2] = max( dp[(i+1)&1][nw2] , dp[i&1][j] );

            }
        }

        for(int i=0; i<(1<<y); i++)
            ans = max( ans , dp[req&1][i] );

        cout << ans << '\n';
        return 0;
    }

    for(int i=0; i<(1<<x); i++){
        for(int j=0; j<x; j++)
            sum[i] += cost[j+1] * ( ( i & (1<<j) ) != 0 );
    }

    int ans = 0;
    for(int i=0; i<(1<<y); i++){

        bool can = 1;

        int ncost = 0;
        for(int j=0; j<y; j++)
            ncost += cost[x+j+1] * ( ( i & (1<<j) ) != 0 );

        for(int j=x; j<y; j++){
            if( !can ) break;
            if( ( i & (1<<j) ) != 0 && ( i & (1<<(j-x)) ) != 0 )
                can = 0;
        }
        if( !can ) continue;

        long long nx = ( ((1ll<<x)-1) | (i<<x) );
        for(int j=x+y-1; j>=x; j--){
            if( j - x < x && j - x >= 0 ){
                if( ( nx & (1ll<<j) ) && ( nx & (1ll<<(j-x)) ) ){
                    nx ^= (1ll<<(j-x));
                }
            }
            if( j - y < x && j - y >= 0 ){
                if( ( nx & (1ll<<j) ) && ( nx & (1ll<<(j-y)) ) ){
                    nx ^= (1ll<<(j-y));
                }
            }
        }

        for(int j=x-1; j>=0; j--){
            if( ( nx & (1ll<<j) ) && ( nx & (1ll<<(j-x+x+y)) ) ){
                nx ^= (1ll<<(j));
            }
            if( ( nx & (1ll<<j) ) && ( nx & (1ll<<(j-y+x+y)) ) ){
                nx ^= (1ll<<(j));
            }
        }

        ans = max( ans , ncost + sum[(nx&((1ll<<x)-1))] );
    }

    cout << ans << '\n';

    return 0;
}