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

void solve()
{
    int n;
    cin >> n;
    vector<int> w(2 * n);
    int ans = 1e9;
    for (int i = 0; i < 2 * n; i++) cin >> w[i];
    for (int i = 0; i < 2 * n; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            vector<int> c;
            for (int k = 0; k < 2 * n; k++)
            {
                if (k == i || k == j) continue;
                c.push_back(w[k]);
            }
            sort(c.begin(), c.end());
            int res = 0;
            for (int k = 0; k < c.size(); k += 2)
                res += c[k + 1] - c[k];
            ans = min(ans, res);
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