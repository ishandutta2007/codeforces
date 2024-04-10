#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 1000010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
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
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> a(n+2);
        for (int i=1; i<=n; i++)
        {
            cin >> a[i];
        }

        map<int, int> last;
        vector<vector<int>> nxt(n+2, vector<int> (20, n + 1));
        vector<int> prv(n+2);
        for (int i=n; i>=1; i--)
        {
            if (last[a[i]])
            {
                nxt[i][0] = last[a[i]];
                prv[last[a[i]]] = i;
            }
            for (int j=1; j<20; j++)
                nxt[i][j] = nxt[nxt[i][j-1]][j-1];

            last[a[i]] = i;
        }

        vector<int> sr(n+1);
        for (int i=1; i<=m; i++)
        {
            int u, v;
            cin >> u >> v;
            sr[u] = max(sr[u], v);
        }

        vector<int> req[n+2];
        int maxl = n;

        int maxr = 0;
        for (int i=1; i<=n; i++)
        {
            maxr = max(maxr, sr[i]);

            int j = i;
            for (int k=19; k>=0; k--)
                if (nxt[j][k] <= maxr)
                    j = nxt[j][k];

            if (j == i)
                continue;

            int a = i;
            int b = nxt[i][0];
            int c = prv[j];
            int d = j;

            req[1].push_back(c);
            req[a+1].push_back(d);
            maxl = min(maxl, b);
        }

        multiset<int> s;
        int ans = n;
        for (int i=1; i<=maxl; i++)
        {
            for (auto j : req[i])
            {
                if (j > 0)
                {
                    s.insert(j);
                }
                if (j < 0)
                {
                    s.erase(s.lower_bound(j));
                }
            }
            if (s.empty())
                ans = 0;
            else
            {
                ans = min(ans, (int)*s.rbegin() - i + 1);
            }
        }
        cout << ans << '\n';
    }


    return 0;
}