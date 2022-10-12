const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

ll inq(ll x, ll y)
{
    if (y == 0) return 1;
    ll l = inq(x, y / 2);
    l = l * l % MOD;
    if (y % 2) return l * x % MOD;
    return l;
}

void solve()
{
    string s, t, g;
    cin >> s >> t >> g;
    vector<int> p(g.size());
    for (int i = 1; i < g.size(); i++)
    {
        p[i] = p[i - 1];
        while (p[i] > 0 && g[p[i]] != g[i])
            p[i] = p[p[i] - 1];
        if (g[p[i]] == g[i])
            p[i]++;
    }
    vector<vector<int> > go(g.size(), vector<int>(26));
    for (int i = 0; i < g.size(); i++)
    {
        if (i) go[i] = go[p[i - 1]];
        go[i][g[i] - 'A'] = i + 1;
    }
    vector<vector<vector<int> > > dp(s.size() + 1, vector<vector<int> >(t.size() + 1, vector<int>(g.size() + 1, -INF)));
    struct state{
        int i, j, k;
        char c;
        state()
        {
            i = 0, j = 0, k = 0, c = '.';
        }
        state(int _i, int _j, int _k, char _c)
        {
            i = _i, j = _j, k = _k, c = _c;
        }
    };
    vector<vector<vector<state> > > prev(s.size() + 1, vector<vector<state> >(t.size() + 1, vector<state>(g.size() + 1)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= s.size(); i++)
    {
        for (int j = 0; j <= t.size(); j++)
        {
            for (int k = 0; k < g.size(); k++)
            {
                if (i < s.size() && dp[i][j][k] > dp[i + 1][j][k])
                {
                    dp[i + 1][j][k] = dp[i][j][k];
                    prev[i + 1][j][k] = {i, j, k, '.'};
                }
                if (j < t.size() && dp[i][j][k] > dp[i][j + 1][k])
                {
                    dp[i][j + 1][k] = dp[i][j][k];
                    prev[i][j + 1][k] = {i, j, k, '.'};
                }
                if (i < s.size() & j < t.size() && s[i] == t[j] && dp[i + 1][j + 1][go[k][s[i] - 'A']] < dp[i][j][k] + 1)
                {
                    dp[i + 1][j + 1][go[k][s[i] - 'A']] = dp[i][j][k] + 1;
                    prev[i + 1][j + 1][go[k][s[i] - 'A']] = {i, j, k, s[i]};
                }
            }
        }
    }
    int ans = -1;
    state id;
    string res = "";
    for (int k = 0; k < g.size(); k++)
    {
        if (dp[s.size()][t.size()][k] > ans)
        {
            ans = dp[s.size()][t.size()][k];
            id = prev[s.size()][t.size()][k];
        }
    }
    while (res.size() < ans)
    {
        if (id.c != '.') res += id.c;
        id = prev[id.i][id.j][id.k];
    }
    reverse(all(res));
    if (res.size() == 0)
    {
        cout << 0 << "\n";
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    for (int tt = 1; tt <= t; tt++)
    {
        solve();
    }
}