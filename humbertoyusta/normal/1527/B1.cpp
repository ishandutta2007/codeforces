    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03") // Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero=upper") // Enable AVX
//#pragma GCC target("avx2") // Enable AVX
//#pragma comment(linker, "/STACK:1024000000,1024000000") // Increase stack limit
//#pragma GCC target("sse,sse2,sse,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") // I don't know what it is
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
const int maxn = 1000010;
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
int modinv(int x){ return qpow(x,mod-2); }
bool isprime(int x){
    for(int i=2; i*i<=x; i++)
        if( x % i == 0 )
            return false;
    return true;
}
/// My Code -------------------------------------------------

int tc, dp[2][1010][2020][2][2];

int f(int t,int e,int o,int m,int p){
    if( t + e + o == 0 ) return 0;
    if( dp[t][e][o][m][p] != -mod )
        return dp[t][e][o][m][p];

    int o1 = -mod * ( p == 1 ) + mod * ( p == 0 );

    if( t ) o1 = f(t-1,e,o,(o!=0),(p+1)%2) + ( p == 0 ) - ( p == 1 );

    int o2 = -mod * ( p == 1 ) + mod * ( p == 0 );

    if( e ) o2 = f(t,e-1,o+1,1,(p+1)%2) + ( p == 0 ) - ( p == 1 );

    int o3 = -mod * ( p == 1 ) + mod * ( p == 0 );

    if( o ) o3 = f(t,e,o-1,(o-1!=0),(p+1)%2) + ( p == 0 ) - ( p == 1 );

    int o4 = -mod * ( p == 1 ) + mod * ( p == 0 );

    if( m ) o4 = f(t,e,o,0,(p+1)%2);

//    cerr << t << ' ';
//    cerr << e << ' ';
//    cerr << o << ' ';
//    cerr << m << ' ';
//    cerr << p << ' ';
//    db(o1)
//    db(o2)
//    db(o3)
//    db(o4)
//    if( p == 0 ) cerr << min( min( o1 , o4 ) , min( o2 , o3 ) ) << '\n';
//        else cerr << max( max( o1 , o4 ) , max( o2 , o3 ) ) << '\n';
    if( p == 0 ) return dp[t][e][o][m][p] = min( min( o1 , o4 ) , min( o2 , o3 ) );
        else return dp[t][e][o][m][p] = max( max( o1 , o4 ) , max( o2 , o3 ) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

        for(int i=0; i<2; i++)
            for(int j=0; j<1010; j++)
                for(int k=0; k<2020; k++)
                    for(int l=0; l<2; l++)
                        for(int m=0; m<2; m++)
                            dp[i][j][k][l][m] = -mod;
    cin >> tc;
    while( tc -- ){

        int n;
        cin >> n;
        string s;
        cin >> s;


        int token = 0, even = 0, odd = 0;
        for(int i=0; i<n; i++){
            if( s[i] == '0' ){
                if( s[n-i-1] == '0' ){
                    if( i == n / 2 && ( n % 2 == 1 ) ){
                        token = 1;
                    }
                    else{
                        even ++;
                    }
                }
                else
                    odd ++;
            }
        }
        even /= 2;

        //db(token)
        //db(even)
        //db(odd)
        int ans = f(token,even,odd,(odd!=0),0);
        db(ans)
        if( ans < 0 ) cout << "ALICE\n";
        if( ans == 0 ) cout << "DRAW\n";
        if( ans > 0 ) cout << "BOB\n";

    }

    return 0;
}