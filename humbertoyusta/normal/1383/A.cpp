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
const int maxn = 21;
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

int tc, n, out[maxn], msk[maxn], mk[maxn];
string s, t;
vector<int> g[maxn], g2[maxn];

bool from(int u,int w){
    if( u == w ) return true;
    if( u > w ) return false;
    mk[u] = 1;
    bool res = 0;
    for( auto v : g2[u] ){
        if( !mk[v] ){
            res |= from(v,w);
        }
    }
    return res;
}

int larg(int u){
    mk[u] = 1;
    int res = u;
    for( auto v : g2[u] ){
        if( !mk[v] ){
            res = max( res , larg(v) );
        }
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    srand(time(NULL));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    cin >> tc;
    while( tc-- ){
        cin >> n;

        for(int i=0; i<=20; i++){
            g[i].clear();
            g2[i].clear();
            g[i].pb(i);
            msk[i] = 0;
        }

        cin >> s >> t;

        bool can = 1;
        for(int i=0; i<n; i++){
            if( s[i] < t[i] ){
                if( ( msk[s[i]-'a'] & (1<<(t[i]-'a')) ) == 0 )
                    g[s[i]-'a'].pb((t[i]-'a'));
                msk[s[i]-'a'] |= (1<<(t[i]-'a'));
            }
            if( s[i] > t[i] ) can = 0;
        }

        for(int i=20; i>=0; i--){
            sort(all(g[i]));
        }

        int ans = 0;
        for(int to=0; to<=20; to++){
            for(int i=0; i<=20; i++){
                for(int j=0; j<g[i].size()-1; j++){
                    if( g[i][j] > to || g[i][j+1] > to ) break;
                    for(int k=0; k<=20; k++)
                        mk[k] = 0;
                    if( from(g[i][j],g[i][j+1]) ) continue;
                    ans++;
                    //db(g[i][j])
                    //db(g[i][j+1])
                    for(int k=0; k<=20; k++)
                        mk[k] = 0;
                    g2[larg(g[i][j])].pb(g[i][j+1]);
                }
            }
        }

        if( can == 0 ) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}