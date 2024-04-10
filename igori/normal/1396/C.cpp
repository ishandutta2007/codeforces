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

const int N = 1e6 + 40;
const ll INFLL = 1e18;

ll dp[N][3][2][2];

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n);
    forn(i, n) cin >> a[i];
    forn(i, n)
    {
        forn(j, 3)
        {
            forn(k, 2)
            {
                dp[i][j][k][0] = dp[i][j][k][1] = INFLL;
            }
        }
    }
    dp[0][2][0][0] = 0;
    // if boss hp = 1, kill in r1 time
    // if boss hp = 2, spend a[i] * r1 + r3 to kill all
    // if boss hp = 2, spend r2 to get to boss hp = 1 and move to the next room
    for (int i = 0; i < n; i++)
    {
        dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][0] + 2 * d + r1);
        dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][1] + 2 * d + r1);
        dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][0] + 2 * d + r1);
        dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][1] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][0] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][1] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][2][0][0] + a[i] * r1 + r3);
        dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][2][1][0] + a[i] * r1 + r3);
        dp[i][1][0][1] = min(dp[i][1][0][1], dp[i][2][0][0] + min(r2, a[i] * r1 + r1));
        dp[i][1][1][1] = min(dp[i][1][1][1], dp[i][2][1][0] + min(r2, a[i] * r1 + r1));
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][1][0][0] + r1);
        dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][1][1][0] + r1);
        dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][0] + d);
        dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][1] + d);
        dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][0] + d);
        dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][1] + d);
        dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][0] + 2 * d + r1);
        dp[i][2][0][0] = min(dp[i][2][0][0], dp[i][2][1][1] + 2 * d + r1);
        dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][0] + 2 * d + r1);
        dp[i][1][0][0] = min(dp[i][1][0][0], dp[i][1][1][1] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][0] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][0][1][1] + 2 * d + r1);
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][2][0][0] + a[i] * r1 + r3);
        dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][2][1][0] + a[i] * r1 + r3);
        dp[i][1][0][1] = min(dp[i][1][0][1], dp[i][2][0][0] + min(r2, a[i] * r1 + r1));
        dp[i][1][1][1] = min(dp[i][1][1][1], dp[i][2][1][0] + min(r2, a[i] * r1 + r1));
        dp[i][0][0][0] = min(dp[i][0][0][0], dp[i][1][0][0] + r1);
        dp[i][0][1][0] = min(dp[i][0][1][0], dp[i][1][1][0] + r1);
        dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][0] + d);
        dp[i + 1][2][0][0] = min(dp[i + 1][2][0][0], dp[i][0][0][1] + d);
        dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][0] + d);
        dp[i + 1][2][1][0] = min(dp[i + 1][2][1][0], dp[i][1][0][1] + d);
    }
    cout << min(dp[n - 1][0][0][0], dp[n - 1][0][1][0] + d + r1);
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