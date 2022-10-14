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
const int maxn = 800010;
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

int n, a[maxn], s[maxn], c[maxn], dp[maxn], st1[maxn], st2[maxn], idu[maxn], idq[maxn];
vector<pair<ii,int>> v;

void update1(int nod,int l,int r,int id,int val){
    if( l == r ){ st1[nod] = val; return; }
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update1(2*nod,l,mi,id,val);
        else update1(2*nod+1,mi+1,r,id,val);
    st1[nod] = min( st1[2*nod], st1[2*nod+1] );
}

void update2(int nod,int l,int r,int id,int val){
    if( l == r ){ st2[nod] = val; return; }
    int mi = ( l + r ) >> 1;
    if( id <= mi ) update2(2*nod,l,mi,id,val);
        else update2(2*nod+1,mi+1,r,id,val);
    st2[nod] = min( st2[2*nod], st2[2*nod+1] );
}

int query1(int nod,int l,int r,int x,int y){
    if( l > r || l > y || r < x ) return INF;
    if( l >= x && r <= y ) return st1[nod];
    int mi = ( l + r ) >> 1;
    return min( query1(2*nod,l,mi,x,y) , query1(2*nod+1,mi+1,r,x,y) );
}

int query2(int nod,int l,int r,int x,int y){
    if( l > r || l > y || r < x ) return INF;
    if( l >= x && r <= y ) return st2[nod];
    int mi = ( l + r ) >> 1;
    return min( query2(2*nod,l,mi,x,y) , query2(2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=0; i<maxn; i++){
        st1[i] = st2[i] = INF;
    }

    cin >> n;

    v.pb({{-INF,-1},-1});
    for(int i=1; i<=n; i++){
        int u, z;
        cin >> u >> z;
        int w = ( i == 1 );
        v.pb({{u,z},w});
    }
    sort(all(v));

    vector<ii> w;
    for(int i=1; i<=n; i++){
        a[i] = v[i].f.f;
        c[i] = v[i].f.s;
        s[i] = c[i] + s[i-1];
//        db(a[i])
//        db(c[i])
//        db(s[i])
//        db(v[i].s)
        w.pb({a[i]+c[i],i});
        w.pb({a[i],n+i});
    }
    sort(all(w));
    for(int i=0; i<2*n; i++){
        if( w[i].s <= n ) idu[w[i].s] = i;
            else idq[w[i].s-n] = i;
    }

    dp[1] = c[n];
    update1(1,0,2*n,idu[1],dp[1]-s[1]-a[1]);
    update2(1,0,2*n,idu[1],dp[1]-s[1]+c[1]);
    //db(dp[1])
    for(int i=2; i<=n; i++){
        dp[i] = query2(1,0,2*n,idq[i],2*n) + s[i-1];
        dp[i] = min( dp[i] , query1(1,0,2*n,0,idq[i]) + s[i-1] + a[i] );
        if( v[i].s ){
            for(int j=0; j<maxn; j++){
                //st1[j] = st2[j] = INF;
            }
        }
        update1(1,0,2*n,idu[i],dp[i]-s[i]-a[i]);
        update2(1,0,2*n,idu[i],dp[i]-s[i]+c[i]);
        //db(dp[i])
    }

    cout << dp[n] << '\n';

    return 0;
}