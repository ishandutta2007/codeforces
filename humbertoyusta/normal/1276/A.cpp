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
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
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
/// Red-Black Tree Template ---------------------------------
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
/// Quick Functions------------------------------------------
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
mt19937_64 r(time(0));
int rng (int a, int b){
    return uniform_int_distribution<int>(a,b)(r);
}
/// My Code -------------------------------------------------

int dp[maxn][5], p[maxn][5];
vector<int> res;

void backtrack(int x,int y){
    if( p[x][y] == -1 ) return;
    if( dp[x-1][p[x][y]] == dp[x][y] ) res.pb(x);
    backtrack(x-1,p[x][y]);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //tc = 1;
    cin >> tc;
    while( tc-- ){

        string s;
        cin >> s;
        int n = s.size();
        s = '&' + s;

        for(int i=0; i<=n; i++){
            fill( dp[i] , dp[i] + 5 , -mod );
            fill( p[i] , p[i] + 5 , -1 );
        }

        string t = "onetwo";
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<5; j++){
                dp[i][j] = dp[i-1][j];
                p[i][j] = j;
            }

            int cnt = 0;
            for( auto j : t )
                if( s[i] == j )
                    cnt ++;
            if( cnt == 0 ){
                for(int j=0; j<5; j++){
                    if( dp[i][0] < dp[i-1][j] + 1 ){
                        dp[i][0] = dp[i-1][j] + 1;
                        p[i][0] = j;
                    }
                }
            }

            if( s[i] == 'o' ){
                for(int j=0; j<4; j++){
                    if( dp[i][1] < dp[i-1][j] + 1 ){
                        dp[i][1] = dp[i-1][j] + 1;
                        p[i][1] = j;
                    }
                }
            }

            if( s[i] == 'n' ){
                for(int j=1; j<2; j++){
                    if( dp[i][2] < dp[i-1][j] + 1 ){
                        dp[i][2] = dp[i-1][j] + 1;
                        p[i][2] = j;
                    }
                }
                for(int j=0; j<5; j++){
                    if( j == 1 ) continue;
                    if( dp[i][0] < dp[i-1][j] + 1 ){
                        dp[i][0] = dp[i-1][j] + 1;
                        p[i][0] = j;
                    }
                }
            }

            if( s[i] == 'e' ){
                for(int j=0; j<5; j++){
                    if( j == 2 ) continue;
                    if( dp[i][0] < dp[i-1][j] + 1 ){
                        dp[i][0] = dp[i-1][j] + 1;
                        p[i][0] = j;
                    }
                }
            }

            if( s[i] == 't' ){
                for(int j=0; j<5; j++){
                    if( dp[i][3] < dp[i-1][j] + 1 ){
                        dp[i][3] = dp[i-1][j] + 1;
                        p[i][3] = j;
                    }
                }
            }

            if( s[i] == 'w' ){
                for(int j=3; j<4; j++){
                    if( dp[i][4] < dp[i-1][j] + 1 ){
                        dp[i][4] = dp[i-1][j] + 1;
                        p[i][4] = j;
                    }
                }
                for(int j=0; j<5; j++){
                    if( j == 3 ) continue;
                    if( dp[i][0] < dp[i-1][j] + 1 ){
                        dp[i][0] = dp[i-1][j] + 1;
                        p[i][0] = j;
                    }
                }
            }
        }

        ii ans = { -1 , -1 };
        for(int i=0; i<5; i++)
            if( dp[n][i] > ans.f )
                ans = { dp[n][i] , i };

        cout << n - ans.f << '\n';
        res.clear();
        backtrack(n,ans.s);
        sort(all(res));
        for( auto i : res ) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}