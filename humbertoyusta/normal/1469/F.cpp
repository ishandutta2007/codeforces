    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
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
/// rng
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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

int n, k, a[maxn];
multiset<ii> s;

int compute(ii a,int x){
    return min(a.s,x) - a.f + 1;
}

bool f(int x){
    s.clear();
    int res = 1;
    s.insert({0,0});
    int sz1, sz2;
    for(int i=1; i<=n; i++){
        ii it = *s.begin();
        if( it.f + 2 <= x ){
            res --;
            s.erase(s.begin());
            if( it.f < it.s )
                s.insert({it.f+1,it.s});

            sz1 = a[i] / 2;
            sz2 = a[i] - 1 - sz1;
            if( sz1 ){ s.insert({it.f+2,it.f+2+sz1-1}); res += compute({it.f+2,it.f+2+sz1-1},x); }
            if( sz2 ){ s.insert({it.f+2,it.f+2+sz2-1}); res += compute({it.f+2,it.f+2+sz2-1},x); }
        }
        if( res >= k ) return true;
    }

    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(0);
    //srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);

    int l = 1, r = 1000400010;
    bool lst = 0;
    while( l < r ){
        int mi = ( l + r ) >> 1;
        if( f(mi) ) r = mi, lst = 1;
            else l = mi + 1, lst = 0;
    }
    //if( f(l-1) ) l--;
    //if( !f(l) ) l++;

    if( f(l) ) cout << l;
        else cout << -1 << '\n';

    return 0;
}