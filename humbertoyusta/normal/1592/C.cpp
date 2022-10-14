#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here -------------------------------------



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while( tc-- ){
        int n, k;
        cin >> n >> k;

        int xr = 0;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
            xr ^= a[i];
        }

        vector<int> g[n];
        for(int i=1; i<n; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool ans = 0;
        if( xr == 0 && k >= 2 ){
            vector<int> b(n);
            function<void(int,int)> dfs = [&](int u,int p){
                b[u] = a[u];
                for( auto v : g[u] ){
                    if( v == p ) continue;
                    dfs(v,u);
                    b[u] ^= b[v];
                }
            };
            dfs(0,0);
            for(int i=1; i<n; i++)
                if( b[i] == b[0] ^ b[i] )
                    ans = 1;
        }
        if( xr != 0 && k >= 3 ){

            vector<int> b(n);
            int cnt = 0;
            function<void(int,int)> dfs = [&](int u,int p){
                b[u] = a[u];
                for( auto v : g[u] ){
                    if( v == p ) continue;
                    dfs(v,u);
                    b[u] ^= b[v];
                }
                if( b[u] == xr ){
                    b[u] = 0;
                    cnt ++;
                }
            };
            dfs(0,0);

            if( b[0] == 0 && cnt >= 3 )
                ans = 1;
        }

        if( ans ) cout << "YES\n";
            else cout << "NO\n";
    }

    return 0;
}