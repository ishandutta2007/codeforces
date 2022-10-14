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
#define int long long
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
const int maxn = 200010;
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

int sum[maxn][18], dp[1<<18];

int f(int x,int n,int k){
    vector<int> v[k];
    for(int i=0; i<k; i++)
        for(int j=1; j+x-1<=n; j++){
            if( sum[j+x-1][i] - sum[j-1][i] == (j+x-1) - (j-1) ){
                v[i].pb(j);
            }
        }
    for(int i=0; i<k; i++)
        v[i].pb(INF);

    fill(dp,dp+(1<<k),n+1);
    dp[0] = -INF;

    for(int i=0; i<(1<<k); i++){

        for(int j=0; j<k; j++){

            if( ( i & (1<<j) ) == 0 ){

                int id = lower_bound(all(v[j]),dp[i]+x) - v[j].begin();
                int y = v[j][id];

                dp[i^(1<<j)] = min( dp[i^(1<<j)] , y );
            }
        }
    }
//    if(x==2){
//        for( int i=0; i<(1<<k); i++)db(dp[i])
//    }

    return dp[(1<<k)-1] < ( n + 1 );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    //cin >> tc;
    tc = 1;
    while( tc-- ){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        s = '&' + s;

        for(int i=0; i<k; i++)
            for(int j=1; j<=n; j++)
                sum[j][i] = sum[j-1][i] + ( s[j] == char('a'+i) || s[j] == '?' );

        int l = 1, r = n - 1;
        while( l < r ){
            int mi = ( l + r ) >> 1;
            if( f(mi,n,k) ) l = mi + 1;
                else r = mi;
        }
        if( f(l+1,n,k) ) l++;
        if( !f(l,n,k) ) l--;
        cout << l << '\n';
    }

    return 0;
}