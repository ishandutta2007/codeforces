const int MOD = 1e9 + 7;
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

#define forn(i, n) for (int i = 0; (i) != (n); (i)++)
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

int cx[4] = {-1, 0, 1, 0};
int cy[4] = {0, -1, 0, 1};
string Yes[2] = {"No\n", "Yes\n"};
string YES[2] = {"NO\n", "YES\n"};
string Possible[2] = {"Impossible\n", "Possible\n"};
string POSSIBLE[2] = {"IMPOSSIBLE\n", "POSSIBLE\n"};

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int m;
    cin >> m;
    vi b(m);
    cin >> b;

    vvi nxt(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            nxt[i][j] = m;
            if (j + 1 < m)
                nxt[i][j] = nxt[i][j + 1];
            if (j + 1 < m && b[j + 1] == a[i])
                nxt[i][j] = j + 1;
        }
    }

    vvi dp(n + 1, vi(m + 1, -INF));
    vvi prev(n + 1, vi(m + 1, -INF));
    // dp[i][j] = max LCIS of prefixes [a_0, ..., a_i] [b_0, ..., b_j] containing b_j
    for (int j = 0; j < m; j++)
    {
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[j])
                fl = 1;
            dp[i][j] = fl;
        }
    }
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i + 1][j] < dp[i][j])
            {
                dp[i + 1][j] = dp[i][j];
                prev[i + 1][j] = -1;
            }
            int pos = nxt[i + 1][j];
            if (b[j] < a[i + 1])
            {
                if (dp[i + 1][pos] < dp[i][j] + 1)
                {
                    dp[i + 1][pos] = dp[i][j] + 1;
                    prev[i + 1][pos] = j;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) dp[i].pop_back();
    dp.pop_back();

    //cout << dp << "\n";

    int ans = 0;
    int lst = -1;
    for (int j = 0; j < m; j++)
    {
        if (dp[n - 1][j] > ans)
        {
            ans = dp[n - 1][j];
            lst = j;
        }
    }

    cout << ans << "\n";
    if (ans == 0)
        return;
    vi res;

    for (int i = n - 1; i >= 0; i--)
    {
        int q = prev[i][lst];
        if (q >= 0)
        {
            res.push_back(b[lst]);
            lst = q;
        }
    }
    if (lst != -1)
    {
        res.push_back(b[lst]);
    }
    reverse(all(res));
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}