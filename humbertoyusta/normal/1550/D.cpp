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

int fact[maxn], ifact[maxn];

int C(int n,int k){
    if( n < k || k < 0 ) return 0;
    return fact[n] * ifact[n-k] % mod * ifact[k] % mod;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    fact[0] = 1;
    ifact[0] = 1;
    for(int i=1; i<maxn; i++){
        fact[i] = fact[i-1] * i % mod;
        ifact[i] = modinv( fact[i] );
    }

    int tc;
    cin >> tc;
    //tc = 1;
    while( tc-- ){

        int n, l, r;
        cin >> n >> l >> r;

        int lx = 1, rx = INF;
        while( lx < rx ){
            int mix = ( lx + rx ) >> 1;
            if( 1 - mix >= l && n + mix <= r ) lx = mix + 1;
                else rx = mix;
        }
        if( 1 - lx >= l && n + lx <= r ) ;
            else lx --;

        int ans = lx % mod * ( C(n,n/2) ) % mod;
        if( n & 1 ) ans = ( ans + lx % mod * ( C(n,(n+1)/2) ) % mod ) % mod;
        int fst = 0, lst = n+1;
        for(int i=lx+1; i<=lx+2*n; i++){
            while( fst <= lst && fst + 1 - i < l ) fst ++;
            while( fst <= lst && lst - 1 + i > r ) lst --;
            if( lst <= fst ) break;

            int tlast = n + 1 - lst;
            set<int> to_try;
            set<int> to_try2;
            to_try.insert(n/2-fst);
            to_try.insert(n/2-tlast);
            to_try.insert((n+1)/2-fst);
            to_try.insert((n+1)/2-tlast);

            for( auto i : to_try )
                to_try2.insert(i-1);
            for( auto i : to_try )
                to_try2.insert(i+1);
            for( auto i : to_try2 )
                to_try.insert(i);
//            for( auto i : to_try )
//                to_try2.insert(i-1);
//            for( auto i : to_try )
//                to_try2.insert(i+1);
//            for( auto i : to_try2 )
//                to_try.insert(i);

            if( ( n & 1 ) == 0 ){
                for( auto x : to_try ){
                    if( fst + x == n / 2 || fst + x == ( n + 1 ) / 2 ){
                        if( tlast + ( lst - fst - 1 ) - x == n / 2 || tlast + ( lst - fst - 1 ) - x == ( n + 1 ) / 2 ){
                            ans = ( ans + C(lst-fst-1,x) ) % mod;
                        }
                    }
                }
            }
            else{
                for( auto x : to_try ){
                    if( fst + x == n / 2 || fst + x == ( n + 1 ) / 2 ){
                        if( tlast + ( lst - fst - 1 ) - x == n / 2 || tlast + ( lst - fst - 1 ) - x == ( n + 1 ) / 2 ){
                            ans = ( ans + C(lst-fst-1,x) ) % mod;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}