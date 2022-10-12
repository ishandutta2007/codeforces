const int LG = 21;
const int FN = 400005;
const long long MOD = 924844033;
const long long INF = 1e9;
const long long INFLL = 1e18;

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};

ll inq(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = inq(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

ll rev(ll x)
{
    return inq(x, MOD - 2);
}

bool __precomputed_combinatorics = 0;
vector<ll> __fact, __ufact, __rev;

void __precompute_combinatorics()
{
    __precomputed_combinatorics = 1;
    __fact.resize(FN);
    __ufact.resize(FN);
    __rev.resize(FN);
    __rev[1] = 1;
    for (int i = 2; i < FN; i++) __rev[i] = MOD - __rev[MOD % i] * (MOD / i) % MOD;
    __fact[0] = 1, __ufact[0] = 1;
    for (int i = 1; i < FN; i++) __fact[i] = __fact[i - 1] * i % MOD, __ufact[i] = __ufact[i - 1] * __rev[i] % MOD;
}

ll fact(int x)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[x];
}

ll cnk(int n, int k)
{
    if (!__precomputed_combinatorics) __precompute_combinatorics();
    return __fact[n] * __ufact[n - k] % MOD * __ufact[k] % MOD;
}

const int N = 1000001;
const int K = 1003;
const double PI = acos(-1);

int n, m, n1, n2, n3;

vector<pair<vi, vi> > bw;
vector<int> graph[N];
int c[N];
vi b, w;

void dfs(int v, int in)
{
    c[v] = in;
    if (in == 1) b.push_back(v);
    else w.push_back(v);
    for (auto u : graph[v])
    {
        if (c[u] == c[v])
        {
            cout << "NO";
            exit(0);
        }
        if (c[u] == 0)
        {
            dfs(u, 3 - in);
        }
    }
}

vector<int> knapsack;
int dp[5001][5001];
int pr[5001][5001];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b, a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int min_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == 0)
        {
            b.clear();
            w.clear();
            dfs(i, 1);
            if (b.size() > w.size()) swap(b, w);
            bw.push_back({b, w});
            min_count += min(b.size(), w.size());
            knapsack.push_back(max(b.size(), w.size()) - min(b.size(), w.size()));
        }
    }
    dp[0][0] = 1;
    if (min_count > n2) cout << "NO", exit(0);
    for (int i = 0; i < knapsack.size(); i++)
    {
        for (int alr = 0; alr + knapsack[i] <= n; alr++)
        {
            if (dp[i][alr])
            {
                dp[i + 1][alr + knapsack[i]] = 1;
                pr[i + 1][alr + knapsack[i]] = knapsack[i];
                dp[i + 1][alr] = 1;
                pr[i + 1][alr] = 0;
            }
        }
    }
    if (dp[knapsack.size()][n2 - min_count])
    {
        cout << "YES\n";
        vector<int> ans(n);
        int sel = n2 - min_count;
        vector<int> items;
        for (int i = knapsack.size(); i > 0; i--)
        {
            if (knapsack[i - 1] <= sel && dp[i - 1][sel - knapsack[i - 1]])
            {
                sel -= knapsack[i - 1];
                items.push_back(knapsack[i - 1]);
            }
            else
            {
                items.push_back(0);
            }
        }
        reverse(all(items));
        for (int i = 0; i < knapsack.size(); i++)
        {
            if (items[i] == 0)
            {
                for (auto e : bw[i].first) ans[e] = 2;
            }
            else
            {
                for (auto e : bw[i].second) ans[e] = 2;
            }
        }
        forn(i, ans.size())
        {
            if (ans[i] == 0)
            {
                if (n1)
                {
                    n1--;
                    cout << 1;
                }
                else
                {
                    n3--;
                    cout << 3;
                }
            }
            else
                cout << ans[i];
        }
    }
    else
    {
        cout << "NO";
    }
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/