    /**   Created by: Humberto Yusta
          Codeforces User: humbertoyusta
          Country: Cuba
          Copyright                    */
#include<bits/stdc++.h>
using namespace std;
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
const ld eps = 1e-9;
const int inf = ((1ll<<31ll)-1ll);
const int INF = (((1ll<<59ll)-1ll)*2ll)+1ll;
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
/// My Code -------------------------------------------------

int n, ans[maxn], ans2[maxn], p[maxn];
ii swp;
pair<ii,int> a[maxn], b[maxn];
priority_queue<int> q;
vector<int> v[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i].f.s >> a[i].f.f;
        a[i].s = i;
        b[i] = a[i];
    }
    stable_sort(a+1,a+n+1);
    for(int i=1; i<=n; i++){
        swap(a[i].f.f,a[i].f.s);
        v[a[i].f.f].pb(i);
    }

    for(int i=1; i<=n; i++){
        for( auto j : v[i] ){
            q.push(-j);
        }
        int x = -q.top();
        q.pop();
        ans[a[x].s] = i;
        ans2[a[x].s] = i;
        p[x] = i;
    }

    while( !q.empty() ) q.pop();
    for(int i=1; i<=n; i++){
        for( auto j : v[i] ){
            q.push(-j);
        }
        int x = -q.top();
        q.pop();
        if( !q.empty() ){
            int y = -q.top();
            if( p[y] <= a[x].f.s && p[x] <= a[y].f.s ){
                swp = { x , y };
                swap( ans2[a[x].s] , ans2[a[y].s] );
                break;
            }
        }
    }

    if( swp == (ii){ 0 , 0 } ){
        cout << "YES\n";
        for(int i=1; i<=n; i++){
            cout << ans[i];
            if( i < n ) cout << ' ';
                else cout << '\n';
        }
    }
    else{
        cout << "NO\n";
        for(int i=1; i<=n; i++){
            cout << ans[i];
            if( i < n ) cout << ' ';
                else cout << '\n';
        }
        for(int i=1; i<=n; i++){
            cout << ans2[i];
            if( i < n ) cout << ' ';
                else cout << '\n';
        }
    }

    return 0;
}