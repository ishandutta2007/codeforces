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
const int maxn = 1000010;
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

int n, m, x, k, y, dp[maxn], a[maxn], b[maxn], c[maxn], l[maxn], r[maxn], mx[maxn];
vector<int> v;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> n >> m;

    cin >> x >> k >> y;

    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = INF;
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }

    stack<ii> p;
    p.push({INF,0});
    for(int i=1; i<=n; i++){
        while( p.top().f < a[i] )
            p.pop();
        l[i] = p.top().s;
        p.push({a[i],i});
    }
    while( !p.empty() ) p.pop();
    p.push({INF,n+1});
    for(int i=n; i>=1; i--){
        while( p.top().f < a[i] )
            p.pop();
        r[i] = p.top().s;
        p.push({a[i],i});
    }

    int step = 0;
    v.pb(0);
    for(int i=1; i<=n; i++){
        if( a[i] == b[step+1] ){
            step++;
            v.pb(i);
        }
        c[i] = step;
    }
    v.pb(n+1);

    for(int i=1; i<=n; i++){
        if( v[c[i]] != i )
            mx[c[i]] = max( mx[c[i]] , a[i] );
    }

    int ans = 0;
    bool can = 1;
    for(int i=0; i<v.size()-1; i++){
        if( v[i+1] - 1 == v[i] ) continue;
        if( x > k * y ){
            if( mx[i] < max( a[v[i]] , a[v[i+1]] ) ){
                ans += ( v[i+1] - v[i] - 1 ) * y;
            }
            else{
                if( ( v[i+1] - v[i] - 1 ) < k ){
                    can = 0;
                }
                else{
                    ans += x + ( v[i+1] - v[i] - 1 - ( k ) ) * y;
                }
            }
        }
        else{
            int fx = ( v[i+1] - v[i] - 1 ) % k;
            if( fx != ( v[i+1] - v[i] - 1 ) || mx[i] < max( a[v[i]] , a[v[i+1]] ) ){
                ans += fx * y + ( ( v[i+1] - v[i] - 1 ) / k ) * x;
            }
            else{
                can = 0;
            }
        }
    }

    if( !can || c[n] != m ){ cout << -1 << '\n'; }
        else{ cout << ans << '\n'; }

    return 0;
}