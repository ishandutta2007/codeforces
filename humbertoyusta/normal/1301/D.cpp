    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = 400010;
const int mod = 1000000007;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 2000000000000000000ll;
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
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int n, m, k;
vector<pair<int,string>> ans;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        int r = min( ( k + 1 ) / 2 , m - 1 );
        int l = min( k / 2 , m - 1 );
        k -= l;
        k -= r;
        int u1 = 0, d1 = 0;
        int u2 = 0, d2 = 0;
        if( i < n ){
            u1 = min( ( k + 1 ) / 2 , m - 1 );
            d1 = min( k / 2 , m - 1 );
        }
        k -= u1;
        k -= d1;
        if( i < n ){
            u2 = min( ( k + 1 ) / 2 , m - 1 );
            d2 = min( k / 2 , m - 1 );
        }
        u2 = d2 = 0;
        k -= u2;
        k -= d2;//db(u1)db(u2)
        int orr = r - u1;
        int orup = d1;
        int oru = u1 - d1;
        int ol = l - u2;
        int olup = d2;
        int olu = u2 - d2;
        if( orr ) ans.pb({orr,"R"});
        if( orup ) ans.pb({orup,"RDU"});
        if( oru ) ans.pb({oru,"RD"});
        if( ol ) ans.pb({ol,"L"});
        if( olup ) ans.pb({olup,"DUL"});
        if( olu )ans.pb({olu,"LD"});
        if( k == 0 ) break;
        else{
            if( i < n ){
                ans.pb({1,"D"});
                k--;
            }
        }
    }


    if( k && ( n - 1 ) > 0 ) {
        ans.pb({min(k,n-1),"U"});
        k -= min(k,n-1);
    }

    if( k ) cout << "NO\n";
    else{
            cout<< "YES\n";
        cout << ans.size() << '\n';
        for( auto i : ans )
            cout << i.f << ' ' << i.s << '\n';
    }

    return 0;
}