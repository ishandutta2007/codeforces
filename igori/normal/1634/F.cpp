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
    int n, q, mod;
    cin >> n >> q >> mod;

    vector<int> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    vector<int> d(n + 2);
    forn(i, n) d[i + 2] = (a[i] - b[i] + mod) % mod;
    for (int i = n + 1; i >= 2; i--)
        d[i] = (d[i] - d[i - 1] - d[i - 2]) % mod, d[i] = (d[i] + mod) % mod;
    vector<int> fib(n + 2);
    fib[1] = 1, fib[2] = 1;
    for (int i = 3; i <= n + 1; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

    int cnt0 = 0;
    for (int i = 2; i < n + 2; i++) if (d[i] == 0) cnt0++;
    while (q--)
    {
        char t;
        int l, r;
        cin >> t >> l >> r;
        l++, r++;
        if (t == 'A')
        {
            if (r + 1 < n + 2)
            {
                if (d[r + 1] == 0) cnt0--;
                d[r + 1] = (d[r + 1] - fib[r - l + 2] + mod) % mod;
                if (d[r + 1] == 0) cnt0++;
            }
            if (r + 2 < n + 2)
            {
                if (d[r + 2] == 0) cnt0--;
                d[r + 2] = (d[r + 2] - fib[r - l + 1] + mod) % mod;
                if (d[r + 2] == 0) cnt0++;
            }
            if (d[l] == 0) cnt0--;
            d[l] = (d[l] + fib[1]) % mod;
            if (d[l] == 0) cnt0++;
        }
        else
        {
            if (r + 1 < n + 2)
            {
                if (d[r + 1] == 0) cnt0--;
                d[r + 1] = (d[r + 1] + fib[r - l + 2]) % mod;
                if (d[r + 1] == 0) cnt0++;
            }
            if (r + 2 < n + 2)
            {
                if (d[r + 2] == 0) cnt0--;
                d[r + 2] = (d[r + 2] + fib[r - l + 1]) % mod;
                if (d[r + 2] == 0) cnt0++;
            }
            if (d[l] == 0) cnt0--;
            d[l] = (d[l] - fib[1] + mod) % mod;
            if (d[l] == 0) cnt0++;
        }
        cout << YES[cnt0 == n];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << "\n";

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}