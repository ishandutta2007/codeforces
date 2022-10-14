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
const int maxn = 2020;
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

vector<int> lv[maxn];

vector<int> query(int r,int n){
    cout << "? " << r << '\n';
    cout.flush();
    vector<int> ret(n+1);
    for(int i=1; i<=n; i++){
        cin >> ret[i];
        ret[i] ++;
    }
    return ret;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    tc = 1;
    while( tc -- ){

        int n;
        cin >> n;

        vector<int> p(n+10);
        p[1] = 1;

        vector<int> a = query(1,n);
        int o = 0, e = 0;
        for(int i=1; i<=n; i++){
            lv[a[i]].pb(i);
            o += ( a[i] % 2 == 1 );
            e += ( a[i] % 2 == 0 );
        }

        vector<ii> ans;
        for(int i=1; i<=n; i++){
            if( lv[i].size() == 0 ) break;
            if( ( o <= e && i % 2 == 1 ) || ( e < o && i % 2 == 0 ) ){
                for(int j=0; j<(int)lv[i].size(); j++){
                    int u = lv[i][j];
                    vector<int> b;
                    if( i == 1 ) b = a;
                        else b = query(u,n);
                    for( auto k : lv[i+1] )
                        if( p[k] == 0 && b[k] == 2 ){
                            p[k] = u;
                            ans.pb({u,k});
                        }
                    for( auto k : lv[i-1] )
                        if( b[k] == 2 ){
                            p[u] = k;
                            ans.pb({u,k});
                        }
                }
            }
        }

        cout << "!\n";
        for( auto i : ans )
            cout << i.f << ' ' << i.s << '\n';
        cout.flush();
    }

    return 0;
}