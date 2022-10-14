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
const int maxn = 1010;
const int mod = 1000000000;
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
    if( e & 1 ) return qpow(b,e-1) * b;
    int pwur = qpow(b,e>>1);
    return pwur * pwur;
}
int modinv(int x){
    return qpow(x,mod-2);
}
/// My Code -------------------------------------------------

int tc, n, k, a[maxn], color[maxn], sz;
vector<int> v[maxn];

int query(int l,int r){
    cout << "? ";
    cout << ( r - l + 1  ) << ' ';
    for(int i=l; i<r; i++)
        cout << i << ' ';
    cout << r << '\n';
    cout.flush();
    int res;
    cin >> res;
    //cout.flush();
    return res;
}

int32_t main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //cout.setf(ios::fixed); cout.precision(0);
    //srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    cin >> tc;
    while( tc-- ){

        cin >> n >> k;
        for(int i=1; i<=n; i++){
            color[i] = 0;
        }
        for(int i=1; i<=k; i++){
            int u; cin >> u;
            v[i].clear();
            sz += u;
            for(int j=1; j<=u; j++){
                int w; cin >> w;
                v[i].pb(w);
                color[w] = i;
            }
        }

        int mx = query(1,n);
        int id = 0;
        for(int i=10; i>=0; i--){
            if( id + (1<<i) <= n && id + (1<<i) > 0 ){
                if( query(1,id+(1<<i)) < mx )
                    id += (1<<i);
            }
        }
        id++;

        int mx2;
        if( k > 1 || sz < n ){
            cout << "? ";
            vector<int> xx;
            for(int i=1; i<=n; i++)
                if( color[i] != color[id] )
                    xx.pb(i);
            cout << xx.size() << ' ';
            for(int i=0; i<xx.size(); i++){
                cout << xx[i];
                if( i < xx.size() - 1 ) cout << ' ';
                    else cout << '\n';
            }
            cout.flush();

            cin >> mx2;
            //cout.flush();

        }

        cout << "! ";
        for(int i=1; i<=k; i++){
            if( k == 1 && sz == n ){ cout << 0 << '\n'; break; }
            if( color[id] == i ) cout << mx2;
                else cout << mx;
            if( i < k ) cout << ' ';
                else cout << '\n';
        }
        cout.flush();

        string s;
        cin >> s;
        //cout.flush();
        if( s == "Incorrect" ) return 1 / 0;
        if( s == "Correct" ){
            if( tc == 0 ) return 0;
                else continue;
        }
    }


    return 0;
}