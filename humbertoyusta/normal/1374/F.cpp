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

int tc, n, a[maxn];
vector<int> ans;

bool sorted(){
    for(int i=1; i<n; i++)
        if( a[i] > a[i+1] ) return 0;
    return 1;
}

void shft(int x){
    swap( a[x+2] , a[x+1] );
    swap( a[x+1] , a[x] );
}

void tryl(){
    for(int i=1; i<=n-2; i++){
        ii mn = {mod,-1};
        for(int j=i; j<=n; j++){
            if( mn.f > a[j] ){
                mn = { a[j] , j };
            }
        }
        while( mn.s != i ){
            if( mn.s - 2 >= i ){
                shft(mn.s-2);
                mn.s -= 2;
                ans.pb(mn.s);
            }
            else{
                shft(mn.s-1);
                shft(mn.s-1);
                mn.s -= 1;
                ans.pb(mn.s);
                ans.pb(mn.s);
            }
        }
    }
}

void tryr(){
    for(int i=n; i>=3; i--){
        ii mx = {-1,-1};
        for(int j=1; j<=i; j++){
            if( mx.f <= a[j] ){
                mx = { a[j] , j };
            }
        }
        while( mx.s != i ){
            if( mx.s + 2 <= i ){
                shft(mx.s);
                ans.pb(mx.s);
                mx.s += 2;
            }
            else{
                shft(mx.s-1);
                //shft(mx.s+1);
                ans.pb(mx.s-1);
                mx.s += 1;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){
        ans.clear();
        cin >> n;
        for(int i=1; i<=n; i++)
            cin >> a[i];

        int bu = 10;
        while( bu-- ){
            tryl();
            tryr();
            //if( ans.size() > n * n ) break;
        }

        for(int i=0; i<=3; i++){
            if(i) shft(n-2);
            if( a[n-2] <= a[n-1] && a[n-1] <= a[n] ){
                for(int j=1; j<=i; j++)
                    ans.pb(n-2);
                break;
            }
        }

        //db(a[5])
        //db(a[6])
        if( !sorted() ){
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for( auto i : ans ) cout << i << ' ';
        cout << '\n';
    }


    return 0;
}