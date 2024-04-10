const int MOD = 998244353;
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
    #define tests

    int n;
    cin >> n;

    vvi a(2, vi(n));
    forn(i, 2) forn(j, n) cin >> a[i][j], a[i][j]++;
    a[0][0] = 0;

    int ans = 2e9;
    int mx = 0;

    vector<vector<int> > to_right(2, vector<int>(n));

    for (int j = 0; j < 2; j++)
    for (int i = n - 1; i >= 0; i--)
    {
        to_right[j][i] = a[j][i] + (n - 1 - i);
        if (i + 1 < n) to_right[j][i] = max(to_right[j][i], to_right[j][i + 1]);
    }

    vector<vector<int> > to_left(2, vector<int>(n + 1));
    for (int j = 0; j < 2; j++)
    {
        to_left[j][n - 1] = a[j][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            to_left[j][i] = max(to_left[j][i + 1] + 1, a[j][i]);
        }
    }
    mx = -1;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < 2; j++)
            {
                mx = max(mx + 1, a[j][i]);
                int st = max(mx + (n - 1 - i), to_right[j][i]);
                int gr = max(st + 1, a[j ^ 1][n - 1]);
                int res = 0;
                if (j == 0) res = max(gr + (n - 1 - i), to_left[1][i]);
                else res = max(gr + (n - 1 - i - 1), to_left[0][i + 1]);

                //cout << st << " " << gr << " " << res << "\n";

                ans = min(ans, res);
            }
        }
        else
        {
            for (int j = 1; j >= 0; j--)
            {
                mx = max(mx + 1, a[j][i]);
                int st = max(mx + (n - 1 - i), to_right[j][i]);
                int gr = max(st + 1, a[j ^ 1][n - 1]);
                int res = 0;
                if (j == 1) res = max(gr + (n - 1 - i), to_left[0][i]);
                else res = max(gr + (n - 1 - i - 1), to_left[1][i + 1]);
                ans = min(ans, res);
            }
        }
    }
    cout << ans << "\n";
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