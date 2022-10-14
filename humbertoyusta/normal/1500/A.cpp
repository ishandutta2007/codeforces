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
const int maxm = 2500010;
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

int tc, n, a[maxn], cnt[maxm];
ii b[maxn];
vector<ii> v[maxm];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]] ++;
        b[i] = { a[i] , i };
    }
    sort(b + 1,b + n + 1);

    vector<int> tmpp;
    for(int i=1; i<maxm; i++){
        if( tmpp.size() >= 1 ) break;
        if( cnt[i] >= 4 )
            tmpp.pb(i);
    }

    if( tmpp.size() >= 1 ){
        vector<int> ans;
        for(int i=1; i<=n; i++){
            if( a[i] == tmpp[0] && ans.size() < 4 ) ans.pb(i);
        }
        cout << "YES\n";
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
        return 0;
    }

    vector<int> tmp;
    for(int i=1; i<maxm; i++){
        if( tmp.size() >= 2 ) break;
        if( cnt[i] >= 2 )
            tmp.pb(i);
    }

    if( tmp.size() >= 2 ){
        vector<int> ans[2];
        for(int i=1; i<=n; i++){
            if( a[i] == tmp[0] && ans[0].size() < 2 ) ans[0].pb(i);
            if( a[i] == tmp[1] && ans[1].size() < 2 ) ans[1].pb(i);
        }
        cout << "YES\n";
        cout << ans[0][0] << ' ' << ans[1][0] << ' ' << ans[0][1] << ' ' << ans[1][1] << '\n';
        return 0;
    }

    vector<int> ans;
    for(int i=1; i<=n; i++){
        if( !ans.empty() ) break;
        for(int j=i+1; j<=n; j++){
            //db( b[i].f )
            //db( b[i].s )
            if( !ans.empty() ) break;
            for( auto k : v[b[j].f-b[i].f] ){
                if( k.f != b[i].s && k.f != b[j].s && k.s != b[i].s && k.s != b[j].s ){
                    ans.pb(k.f);
                    ans.pb(b[j].s);
                    ans.pb(b[i].s);
                    ans.pb(k.s);
                    break;
                }
            }
            v[b[j].f-b[i].f].pb({b[i].s,b[j].s});
        }
    }

    if( ans.empty() ) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
        }

    return 0;
}