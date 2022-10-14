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
#define lb lower_bound
#define up upper_bound
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin() , x.rend()
#define enl '\n'
typedef pair<int,int> ii;
typedef long double ld;
typedef unsigned long long ull;
/// Constraints:
const int maxn = 35005;
const int maxk = 102;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 1000000007 * 2;
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

int n, k, sgt[maxk][maxn*4], lazy[maxk][maxn*4], lst[maxn], prv[maxn], a[maxn];

void lazyp(int st,int nod,int l,int r){
    sgt[st][nod] += lazy[st][nod];
    if( l != r ){
        lazy[st][2*nod] += lazy[st][nod];
        lazy[st][2*nod+1] += lazy[st][nod];
    }
    lazy[st][nod] = 0;
}

void update(int st,int nod,int l,int r,int x,int y,int val){
    lazyp(st,nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[st][nod] = val;
        lazyp(st,nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(st,2*nod,l,mi,x,y,val);
        update(st,2*nod+1,mi+1,r,x,y,val);
    sgt[st][nod] = min( sgt[st][2*nod] , sgt[st][2*nod+1] );
}

int query(int st,int nod,int l,int r,int x,int y){
    lazyp(st,nod,l,r);
    if( l > y || r < x ) return INF;
    if( l >= x && r <= y ){
        return sgt[st][nod];
    }
    int mi = ( l + r ) >> 1;
    return min( query(st,2*nod,l,mi,x,y), query(st,2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> k;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        prv[i] = lst[a[i]];
        lst[a[i]] = i;
    }

    fill( sgt[0] , sgt[0] + maxn * 4 , INF );
    int dp = 0;
    update(0,1,0,n,0,0,-INF);
    for(int i=1; i<=k; i++){
        fill( sgt[i] , sgt[i] + maxn * 4 , INF );
        for(int j=1; j<=n; j++){
            if( prv[j] ) update(i-1,1,0,n,0,prv[j]-1,j-prv[j]);
            dp = query(i-1,1,0,n,0,j-1);
            //cerr << i << ' ' << j << ' ' << dp << '\n';
            update(i,1,0,n,j,j,-INF+dp);
        }
    }
    cout << dp << '\n';

    return 0;
}