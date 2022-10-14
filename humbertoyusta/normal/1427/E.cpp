    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
/// Pragmas:
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
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
const int maxn = 1000010;
const int mod = 1000000007;
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
#define lg(x) 63 - __builtin_clzll(x)
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

vector<int> vx;
int cnt;
struct pr{int a, b, o;};
vector<pr> prnt;

int g(int val){
    int res = 0;
    while( val % 2 == 0 ){ val >>= 1; res ++; }
    return res;
}

void solve(int x){

    if( x == 1 ) return;
    set<int> s, vx;
    s.insert(x);
    s.insert(mod);

    for(int i=1; i<=5; i++){
        set<int> w;
        w.insert(mod);
        for( auto i : s )
            for( auto j : s ){
                if( i == mod || j == mod ) continue;
                if( *s.lower_bound(i+j) != i + j && *w.lower_bound(i+j) != i + j && i + j <= 5 * x ){
                    w.insert(i+j);
                    prnt.pb({i,j,0});
                    if( ( i + j ) % 2 ) vx.insert(i+j);
                }
                if( *s.lower_bound((i^j)) != ( i ^ j ) && *w.lower_bound((i^j)) != ( i ^ j ) && (i ^ j) <= 5 * x ){
                    w.insert(i^j);
                    prnt.pb({i,j,1});
                    if( ( i ^ j ) % 2 ) vx.insert((i^j));
                }
            }
        for( auto i : w ){
            s.insert(i);
            if( i == 1 ) return;
        }
    }

    vector<ii> vy;

        for(auto i : vx)
            if( i < 2 * x )
                vy.pb({__builtin_popcountll(i)-lg(i),i});

    if( vy.empty() ){
        for(auto i : vx)
            if( i < 3 * x )
                vy.pb({__builtin_popcountll(i)-lg(i),i});
    }

    if( vy.empty() ){
        for(auto i : vx)
            if( i < 6 * x )
                vy.pb({__builtin_popcountll(i)-lg(i),i});
    }
    sort(all(vy));

    return solve(vy[rand()%min((int)vy.size(),10ll)].s);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    int n;
    cin >> n;
    //n = rsolve(n);
    //n = rsolve(n);db(n)
    solve(n);
    while( prnt.size() > 100000 ) solve(n);

    cout << prnt.size() << '\n';
    for( auto i : prnt ){
        if( i .o == 0 ) cout << i.a << " + " << i.b << '\n';
        if( i .o == 1 ) cout << i.a << " ^ " << i.b << '\n';
    }

    return 0;
}