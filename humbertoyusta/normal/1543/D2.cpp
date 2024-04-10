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

bool ask(int x){
    cout << x << '\n';
    cout.flush();
    bool ret;
    cin >> ret;
    if( ret == -1 ) exit(0);
    return ret;
}

int invXoR(int a,int b,int k){

    vector<int> ka;
    while( a ){
        ka.pb(a%k);
        a /= k;
    }

    vector<int> kb;
    while( b ){
        kb.pb(b%k);
        b /= k;
    }

    vector<int> kc;
    for(int i=0; i<max(ka.size(),kb.size()); i++){
        if( i >= ka.size() ){ kc.pb((k+kb[i])%k); continue; }
        if( i >= kb.size() ){ kc.pb((k-ka[i])%k); continue; }
        kc.pb((k-ka[i]+kb[i])%k);
    }

    int c = 0;
    int pot = 1;
    for(int i=0; i<kc.size(); i++){
        c += kc[i] * pot;
        pot *= k;
    }

    return c;
}

int XoR(int a,int b,int k){

    vector<int> ka;
    while( a ){
        ka.pb(a%k);
        a /= k;
    }

    vector<int> kb;
    while( b ){
        kb.pb(b%k);
        b /= k;
    }

    vector<int> kc;
    for(int i=0; i<max(ka.size(),kb.size()); i++){
        if( i >= ka.size() ){ kc.pb((k+kb[i])%k); continue; }
        if( i >= kb.size() ){ kc.pb((k+ka[i])%k); continue; }
        kc.pb((k+ka[i]+kb[i])%k);
    }

    int c = 0;
    int pot = 1;
    for(int i=0; i<kc.size(); i++){
        c += kc[i] * pot;
        pot *= k;
    }

    return c;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    int t = clock();
    //tc = 1;
    while( tc-- ){

        int n, k;
        cin >> n >> k;

        vector<int> x(n+1), f(n+1), sx(n+1);
        x.pb(0);
        f.pb(0);
        sx.pb(0);
        ask(0);
        for(int i=1; i<n; i++){

            if( i % 2 ) f[i] = invXoR( i , sx[i-1] , k );
                else f[i] = XoR( i , sx[i-1] , k );

            x[i] = f[i];

            sx[i] = invXoR( sx[i-1] , x[i] , k );

            if( ask(f[i]) ) break;
        }

    }

    return 0;
}