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

int inq(int x, int y, int mod)
{
    if (y == 0) return 1;
    int l = inq(x, y / 2, mod);
    l = 1ll * l * l % mod;
    if (y % 2) return 1ll * l * x % mod;
    return l;
}

void solve()
{
    #define tests

    int n, m, xr, yr, xd, yd, p;
    cin >> n >> m >> xr >> yr >> xd >> yd >> p;
    xr--, yr--, xd--, yd--;

    vector<int> cx = {1, 1, -1, -1};
    vector<int> cy = {1, -1, 1, -1};
    struct state{
        int x, y;
        int dir;
        bool operator != (state other)
        {
            return other.x != x || other.y != y || other.dir != dir;
        }
    };
    vector<state> q;
    int fl = 0;
    if (xr == 0) fl ^= 2;
    if (yr == 0) fl ^= 1;
    state cur = {xr, yr, fl};
    q.push_back(cur);
    auto ok = [&](int x, int n)
    {
        return 0 <= x && x < n;
    };
    auto apply = [&]()
    {
        if (!ok(cur.x + cx[cur.dir], n)) cur.dir ^= 2;
        if (!ok(cur.y + cy[cur.dir], m)) cur.dir ^= 1;
        cur.x += cx[cur.dir], cur.y += cy[cur.dir];
    };
    apply();
    while (cur != q[0])
    {
        q.push_back(cur);
        apply();
    }

    vector<int> moments;
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i].x == xd || q[i].y == yd)
        {
            moments.push_back(i);
        }
    }

    int k = moments.size();
    // multiply each by p:
    // moments[0]
    // (1-p) * moments[1]
    // (1-p)^2 * moments[2]
    // ...
    // (1-p)^(k-1) * moments[k-1] // val

    // (1-p)^k * (moments[0] + |Q|) = (1-p)^k * moments[0] + (1-p)^k * |Q|
    // ...
    // (1-p)^k * (1-p)^(k-1) * (moments[k - 1] + |Q|) = (1-p)^k * (1-p)^(k-1) * moments[k-1] + (1-p)^k * (1-p)^(k-1) * |Q|

    // W * val + W * f(|Q|)
    // W^2 * val + 2 * W^2 * f(|Q|)

    // val * (1 + W + W^2 + ...) = val * (1 / (1 - W))
    // fQ * (W + 2W^2 + 3W^3 + 4W^4 + ...) = fQ * (W / (1 - W)^2)
    int P = 1ll * p * inq(100, MOD - 2, MOD) % MOD;
    int S = (1 - P + MOD) % MOD;
    int W = 1;
    int val = 0;
    int fQ = 0;
    for (int i = 0; i < k; i++)
    {
        val = (val + 1ll * W * moments[i]) % MOD;
        fQ = (fQ + 1ll * W * q.size()) % MOD;
        W = 1ll * W * S % MOD;
    }
    val = 1ll * val * P % MOD;
    fQ = 1ll * fQ * P % MOD;
    fQ = 1ll * fQ * W % MOD;
    W = (1 - W + MOD) % MOD;
    W = inq(W, MOD - 2, MOD);
    cout << 1ll * (val + 1ll * fQ * W % MOD) * W % MOD << "\n";
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