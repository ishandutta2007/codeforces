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
    ll x;
    cin >> n >> x;
    vector<ll> a(n + 1);
    forn(i, n) cin >> a[i + 1];
    forn(i, n) a[i + 1] += a[i];
    vector<ll> mx_len(n + 1, -INFLL);
    for (int len = 0; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            mx_len[len] = max(mx_len[len], a[i + len] - a[i]);
        }
    }
    for (int k = 0; k <= n; k++)
    {
        ll ans = 0;
        for (int sel = 0; sel <= n; sel++)
        {
            ll add = x * min(k, sel);
            ans = max(ans, mx_len[sel] + add);
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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