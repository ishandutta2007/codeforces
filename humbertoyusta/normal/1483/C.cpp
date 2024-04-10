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
const int maxn = 300010;
const int mod = 1000000007;
const int mod2 = 998244353;
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = 10000000000000000ll;
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

int n, st[maxn*4], lazy[maxn*4], dp[maxn], a[maxn], b[maxn];
stack<pair<int,ii>> s;

void lazyp(int nod,int l,int r){
    st[nod] += lazy[nod];
    if( l != r ){
        lazy[2*nod] += lazy[nod];
        lazy[2*nod+1] += lazy[nod];
    }
    lazy[nod] = 0;
}

void update(int nod,int l,int r,int x,int y,int val){
    lazyp(nod,l,r);
    if( l > y || r < x ) return;
    if( l >= x && r <= y ){
        lazy[nod] += val;
        lazyp(nod,l,r);
        return;
    }
    int mi = ( l + r ) >> 1;
        update(2*nod,l,mi,x,y,val);
        update(2*nod+1,mi+1,r,x,y,val);
    st[nod] = max( st[2*nod] , st[2*nod+1] );
}

int query(int nod,int l,int r,int x,int y){
    lazyp(nod,l,r);
    if( l > y || r < x ) return -INF;
    if( l >= x && r <= y ) return st[nod];
    int mi = ( l + r ) >> 1;
    return max( query(2*nod,l,mi,x,y) , query(2*nod+1,mi+1,r,x,y) );
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    for(int i=0; i<maxn*4; i++)
        st[i] = -INF;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }

    s.push({-INF,{0,0}});
    update(1,0,n,0,0,INF);
    for(int i=1; i<=n; i++){

        while( s.top().f > a[i] ){
            pair<int,ii> q = s.top();
            s.pop();
            update(1,0,n,s.top().s.f,q.s.f-1,-q.s.s);
        }

        update(1,0,n,s.top().s.f,i-1,b[i]);
        s.push({a[i],{i,b[i]}});

        dp[i] = query(1,0,n,0,i-1);
        update(1,0,n,i,i,INF+dp[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}