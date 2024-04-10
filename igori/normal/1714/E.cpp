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
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    forn(i, n) a[i] += a[i] % 10;
    forn(i, n) a[i] += a[i] % 10;

    int zero = -1;
    forn(i, n) if (a[i] % 10 == 0) zero = a[i];

    if (zero != -1)
    {
        forn(i, n) if (a[i] != zero)
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        return;
    }

    int flA = 0, flB = 0;
    forn(i, n)
    {
        a[i] %= 20;
        if (a[i] == 2 || a[i] == 4 || a[i] == 8 || a[i] == 16) flA = 1;
        if (a[i] == 6 || a[i] == 12 || a[i] == 14 || a[i] == 18) flB = 1;
    }
    cout << YES[flA + flB == 1];
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