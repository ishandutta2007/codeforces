const long long MOD = 998244353;
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

const int N = 1000;

int a[N][N];
int dp2[N][N];
int dp5[N][N];

int g(int x, int y)
{
    if (x == 0) return 100000;
    int c = 0;
    while (x % y == 0) x /= y, c++;
    return c;
}

void solve()
{
    int n;
    cin >> n;
    int fl = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            dp2[i][j] = INF, dp5[i][j] = INF;
            if (a[i][j] == 0) fl = i;
        }
    }
    dp2[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && dp2[i - 1][j] < dp2[i][j]) dp2[i][j] = dp2[i - 1][j];
            if (j > 0 && dp2[i][j - 1] < dp2[i][j]) dp2[i][j] = dp2[i][j - 1];
            dp2[i][j] += g(a[i][j], 2);
        }
    }
    dp5[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > 0 && dp5[i - 1][j] < dp5[i][j]) dp5[i][j] = dp5[i - 1][j];
            if (j > 0 && dp5[i][j - 1] < dp5[i][j]) dp5[i][j] = dp5[i][j - 1];
            dp5[i][j] += g(a[i][j], 5);
        }
    }
    if (fl != -1 && min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]) > 1)
    {
        cout << 1 << "\n";
        for (int i = 0; i < fl; i++) cout << "D";
        for (int i = 0; i < n - 1; i++) cout << "R";
        for (int i = 0; i < n - 1 - fl; i++) cout << "D";
        return;
    }
    if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1])
    {
        cout << dp2[n - 1][n - 1] << "\n";
        string s = "";
        int x = n - 1, y = n - 1;
        for (int i = 0; i < 2 * n - 2; i++)
        {
            int A = x ? dp2[x - 1][y] : INF;
            int B = y ? dp2[x][y - 1] : INF;
            if (A < B) x--, s += "D";
            else y--, s += "R";
        }
        reverse(all(s));
        cout << s;
    }
    else
    {
        cout << dp5[n - 1][n - 1] << "\n";
        string s = "";
        int x = n - 1, y = n - 1;
        for (int i = 0; i < 2 * n - 2; i++)
        {
            int A = x ? dp5[x - 1][y] : INF;
            int B = y ? dp5[x][y - 1] : INF;
            if (A < B) x--, s += "D";
            else y--, s += "R";
        }
        reverse(all(s));
        cout << s;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //cin >> t;
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