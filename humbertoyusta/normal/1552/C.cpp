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
const int maxn = 220;
const int mod2 = 1000000007;
const int mod = 998244353;
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

int cnt[maxn];
ii a[maxn], b[maxn];
int n, k;

int solve(int x,vector<int> v){
    int st = -1;
    for(int i=1; i<=n; i++){
        b[i] = a[i];
        if( a[i] == (ii){0,0} && st == -1 ){
            st = i;
        }
    }
    for(int i=0; i<v.size()/2; i++){
        int nx = v[(i+x)%v.size()];
        int ny = v[(i+x+v.size()/2)%v.size()];
        b[st++] = { min(nx,ny) , max(nx,ny) };
    }

    int cnt = 0;
    for(int i=1; i<n; i++)
        for(int j=i+1; j<=n; j++){
//            db(b[i].f)
//            db(b[i].s)
//            db(b[j].f)
//            db(b[j].s)
            if( b[i].f > b[j].f && b[i].f < b[j].s && b[i].s > b[j].f && b[i].s < b[j].s ) continue;
            if( b[i].f > b[j].f && b[i].f < b[j].s ) cnt ++;
            if( b[i].s > b[j].f && b[i].s < b[j].s ) cnt ++;
//            db(cnt)
        }
    return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    //tc = 1;
    while( tc -- ){

        cin >> n >> k;

        for(int i=1; i<=2*n; i++){
            cnt[i] = 0;
            a[i] = b[i] = {0,0};
        }

        for(int i=1; i<=k; i++){
            cin >> a[i].f >> a[i].s;
            if( a[i].f > a[i].s ){
                swap( a[i].f , a[i].s );
            }
            cnt[a[i].f] ++;
            cnt[a[i].s] ++;
        }

        vector<int> v;
        for(int i=1; i<=2*n; i++){
            if( cnt[i] == 0 ){
                v.pb(i);
            }
        }

        int ans = 0;
        for(int i=0; i<v.size(); i++){
            ans = max( ans , solve(i,v) );
        }
        if( v.empty() )
            ans = solve(0,v);
        cout << ans << '\n';
    }

    return 0;
}