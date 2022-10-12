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
    #define tests
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    vector<int> b(m);
    forn(i, m) cin >> b[i];

    int g = b[0];
    forn(i, m) g = __gcd(g, b[i]);

    if (g == 1)
    {
        ll ans = 0;
        forn(i, a.size()) ans += abs(a[i]);
        cout << ans << "\n";
        return;
    }

    vector<vector<int> > Q(g);
    forn(i, n) Q[i % g].push_back(a[i]);
    forn(i, g) sort(all(Q[i]));

    ll ans = 0;
    forn(parity, 2)
    {
        ll tot = 0;
        forn(i, g) forn(j, Q[i].size())
        {
            tot += Q[i][j];
            if (parity && j == 0) tot -= 2 * Q[i][j];
        }
        forn(i, g)
        {
            for (int j = parity; j + 1 < Q[i].size(); j += 2)
            {
                if (Q[i][j] + Q[i][j + 1] < 0)
                    tot -= 2ll * (Q[i][j] + Q[i][j + 1]);
            }
        }
        ans = max(ans, tot);
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    #ifdef tests
    cin >> t;
    #endif
    while (t--)
    {
        solve();
    }
}