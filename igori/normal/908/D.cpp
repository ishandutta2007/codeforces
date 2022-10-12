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

int inq(int x, int y)
{
    if (y == 0) return 1;
    int l = inq(x, y / 2);
    l = 1ll * l * l % MOD;
    if (y % 2) return 1ll * x * l % MOD;
    return l;
}

void solve()
{
    int k, pa, pb;
    cin >> k >> pa >> pb;

    int d = inq(pa + pb, MOD - 2);
    pa = 1ll * pa * d % MOD;
    pb = 1ll * pb * d % MOD;

    vector<vector<int> > dpA(2 * k + 1, vector<int>(2 * k + 1));
    vector<vector<int> > dpB(2 * k + 1, vector<int>(2 * k + 1));
    dpB[0][0] = 1;

    int F = 1ll * pb * pa % MOD * inq(pb, MOD - 2) % MOD * inq(pb, MOD - 2) % MOD;
    int ans = 0;
    vector<int> deg_pa(2 * k + 1);
    deg_pa[0] = 1;
    for (int i = 1; i <= 2 * k; i++)
        deg_pa[i] = 1ll * deg_pa[i - 1] * pa % MOD;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j >= 0)
                ans = (ans + 1ll * dpB[i][j] * deg_pa[max(0, k - i - j - (j == 0))] % MOD * (max(i + j, k) + F)) % MOD;

            int dp = (dpA[i][j] + dpB[i][j]) % MOD;

            if (j >= 1)
                dpB[i + j][j] = (dpB[i + j][j] + 1ll * dp * pb) % MOD,
                dpA[i][j + 1] = (dpA[i][j + 1] + 1ll * dp * pa) % MOD;
            else
                dpA[i][j + 1] = (dpA[i][j + 1] + 1ll * dp) % MOD;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));

    #ifdef LOCAL
    cout << "\n";
    #endif // LOCAL

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif // tests
    while (t--)
    {
        solve();
    }
}