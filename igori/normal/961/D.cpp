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

int on_line(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z)
{
    return (y.first - x.first) * (z.second - x.second) == (y.second - x.second) * (z.first - x.first);
}

void solve()
{
    int n;
    cin >> n;
    if (n <= 4)
    {
        cout << "YES\n";
        return;
    }

    vector<pair<ll, ll> > p(n);
    forn(i, n) cin >> p[i].first >> p[i].second;

    vector<int> check;
    forn(i, n) if (!on_line(p[0], p[1], p[i])) check.push_back(i);
    if (check.size() == 2)
    {
        cout << "YES\n";
        return;
    }
    check.resize(3);
    for (int a = 0; a < 3; a++)
    {
        for (int b = a + 1; b < 3; b++)
        {
            vector<int> ok(n);
            for (int i = 0; i < n; i++)
            {
                ok[i] = on_line(p[check[a]], p[check[b]], p[i]);
            }
            vector<int> bad;
            for (int i = 0; i < n; i++)
            {
                if (!ok[i]) bad.push_back(i);
            }
            if (bad.size() <= 2)
            {
                cout << "YES\n";
                return;
            }
            int t = 1;
            for (auto e : bad)
            {
                if (!on_line(p[bad[0]], p[bad[1]], p[e])) t = 0;
            }
            if (t)
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}