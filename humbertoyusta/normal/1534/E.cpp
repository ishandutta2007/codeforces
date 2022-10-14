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

int query(vector<int> vx){
    int ret = 0;
    cout << "? ";
    for(int i=0; i<vx.size(); i++)
        cout << vx[i] << " \n"[i+1==vx.size()];
    cout.flush();
    cin >> ret;
    return ret;
}

int dp[maxn];
ii p[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n, k;
    cin >> n >> k;
    int N = n;

    for(int i=1; i<=n; i++)
        dp[i] = INF;
    dp[0] = 0;

    for(int i=1; i<=n; i++){
        if( i >= k ){
            dp[i] = dp[i-k] + 1;
            p[i] = { i - k , 1 };
        }
        for(int j=2; j<=min(i,2*k); j+=2){
            if( j + ( k - j / 2 ) <= n ){
                if( dp[i] > dp[i-j] + 2 ){
                    dp[i] = dp[i-j] + 2;
                    p[i] = { i - j , 2 };
                }
            }
        }
    }

    if( dp[n] >= INF ){
        cout << -1;
        return 0;
    }

    int ans = 0;
    while( n > 0 ){
        if( p[n].s == 1 ){
            vector<int> a;
            while( a.size() < k ){
                a.pb(n);
                n--;
            }
            ans ^= query(a);
            continue;
        }
        if( p[n].s == 2 ){
            int i = n - p[n].f;
                vector<int> a, b;
                vector<int> mk(N+1);
                while( a.size() < i / 2 ){
                    a.pb(n);
                    mk[n] = 1;
                    n --;
                }
                while( b.size() < i / 2 ){
                    b.pb(n);
                    mk[n] = 1;
                    n --;
                }
                for(int j=1; j<=N; j++){
                    if( !mk[j] ){
                        if( a.size() < k && b.size() < k ){
                            mk[j] = 1;
                            a.pb(j);
                            b.pb(j);
                        }
                    }
                }
                ans ^= query(a);
                ans ^= query(b);
            continue;
        }
    }

    cout << "! " << ans << '\n';
    cout.flush();

    return 0;
}