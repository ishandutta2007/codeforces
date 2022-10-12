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

void solve()
{
    const int B = 30;
    int n, m;
    cin >> n >> m;
    vector<vector<int> > forbidden(n + 1, vector<int>(B));
    for (int i = 0; i < m; i++)
    {
        ll l, r, val_or;
        cin >> l >> r >> val_or;
        l--, r--;
        for (int j = 0; j < B; j++)
        {
            if (!((1ll << j) & val_or))
                forbidden[l][j]++, forbidden[r + 1][j]--;
        }
    }
    ll power = 1;
    for (int i = 0; i < n - 1; i++) power = power * 2 % MOD;
    ll ans = 0;
    for (int b = 0; b < B; b++)
    {
        int cnt = 0;
        int forbids = 0;
        for (int i = 0; i < n; i++)
        {
            forbids += forbidden[i][b];
            if (forbids == 0)
                cnt++;
        }
        if (cnt > 0)
        {
            ans = (ans + (1ll << b) * power) % MOD;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

/* Note:
Check constants at the beginning of the code (MOD, INF, INFLL)
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/