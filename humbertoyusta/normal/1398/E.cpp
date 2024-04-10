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

int n, abi1[maxn], abi2[maxn], cnt1[maxn], cnt2[maxn], c1, c2, mx, s1, s2;
vector<ii> compress;
vector<pair<ii,int>> aa;

void update1(int id,int val){
    for( ; id < maxn; id += ( id & -id ) ){
        abi1[id] += val;
        if( val > 0 ) cnt1[id] ++;
            else cnt1[id] --;
    }
}

void update2(int id,int val){
    for( ; id < maxn; id += ( id & -id ) ){
        abi2[id] += val;
        if( val > 0 ) cnt2[id] ++;
            else cnt2[id] --;
    }
}

int query1(int x){
    int count_ = 0, sum_ = 0, id_ = 0;
    for(int i=(1<<17); i>0; i/=2){
        if( count_ + cnt1[id_+i] <= x ){
            sum_ += abi1[id_+i];
            count_ += cnt1[id_+i];
            id_ += i;
        }
    }
    return sum_;
}

int query2(int x){
    int count_ = 0, sum_ = 0, id_ = 0;
    for(int i=(1<<17); i>0; i/=2){
        if( count_ + cnt2[id_+i] <= x ){
            sum_ += abi2[id_+i];
            count_ += cnt2[id_+i];
            id_ += i;
        }
    }
    return sum_;
}

int f(int x){
    if( x > mx ) x = mx;
    if( x < 0 ) x = 0;
    int res = 0;
    if( c1 ){
        if( c2 == 0 ){
            res += s1;
        }
        else{
            int opt = query1(c1-x-1);
            res += ( s1 - opt ) * 2;
            res += opt;
        }
    }
    int opt = query2(x+1);
    res += opt;
    res += ( s2 - opt ) * 2;
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n;

    compress.pb({-1,-1});
    aa.pb({{-1,-1},-1});
    for(int i=1; i<=n; i++){
        int u, v; cin >> u >> v;
        aa.pb({{u,v},0});
        compress.pb({abs(v),i});
    }

    sort(all(compress));
    int cnt = 0;
    for(int i=1; i<compress.size(); i++){
        if( compress[i].f != compress[i-1].f ) cnt++;
        aa[compress[i].s].s = cnt;
    }

    for(int i=1; i<=n; i++){
        if( aa[i].f.f == 0 ){ update1(aa[i].s,aa[i].f.s); c1 = c1 + ( aa[i].f.s > 0 ) - ( aa[i].f.s < 0 ); s1 += aa[i].f.s; }
        if( aa[i].f.f == 1 ){ update2(aa[i].s,aa[i].f.s); c2 = c2 + ( aa[i].f.s > 0 ) - ( aa[i].f.s < 0 ); s2 += aa[i].f.s; }
        int l = 1, r = min( c1 - 1 , c2 - 1 ) - 1;
        mx = min( c1 - 1 , c2 - 1 );
        while( l < r ){
            int mi = ( l + r ) >> 1;
            if( f(mi) - f(mi-1) >= 0 ) l = mi + 1;
                else r = mi;
        }
        cout << max( { f(l-2) , f(l-1) , f(l) , f(l+1) , f(l+2) } ) << '\n';
    }

    return 0;
}