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
// Problem starts here



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    cin >> tc;
    while( tc-- )
    {
        int n;
        cin >> n;

        vector<int> G[n+1];
        for (int i=1; i<n; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<int> lvl(n+1);
        lvl[1] = 1;
        function<void(int)> dfs = [&](int u)
        {
            for (auto v : G[u])
            {
                if (!lvl[v])
                {
                    lvl[v] = lvl[u] + 1;
                    dfs(v);
                }
            }
        };
        dfs(1);

        for (int i=1; i<=n; i++)
        {
            if (lvl[i] & 1)
                cout << -int(G[i].size()) + 1 - 1 << " \n"[i==n];
            else
                cout << int(G[i].size()) - 1 + 1 << " \n"[i==n];
        }
    }

    return 0;
}