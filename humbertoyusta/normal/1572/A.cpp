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
        int n;
        cin >> n;

        bool cyc = 0;
        vector<int> g[n];
        for(int i=0; i<n; i++){
            int k;
            cin >> k;
            for(int j=0; j<k; j++){
                int u;
                cin >> u;
                u --;
                if( u == i )
                    cyc = 1;
                g[i].push_back(u);
            }
        }

        vector<int> tp, mk(n);
        function<void(int)> dfs = [&](int u){
            mk[u] = 1;
            for( auto v : g[u] ){
                if( !mk[v] ){
                    dfs(v);
                }
            }
            tp.push_back(u);
        };
        for(int i=0; i<n; i++)
            if( !mk[i] )
                dfs(i);
        reverse(tp.begin(),tp.end());

        vector<int> id(n);
        for(int i=0; i<n; i++)
            id[tp[i]] = i;

        for(int i=0; i<n; i++)
            for( auto j : g[i] )
                if( id[i] > id[j] )
                    cyc = 1;

        int ans = 0;
        vector<int> dp(n);
        for(int i=n-1; i>=0; i--){
            dp[i] = 1;
            for( auto j : g[tp[i]] ){
                dp[i] = max( dp[i] , dp[id[j]] + ( tp[i] < j ) );
            }
            ans = max( ans , dp[i] );
        }

        if( cyc ) cout << -1 << '\n';
            else cout << ans << '\n';
    }

    return 0;
}