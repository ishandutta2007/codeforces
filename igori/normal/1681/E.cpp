const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 10;
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

#define ok(x, n) (0 <= (x) && (x) < (n))
#define withBit(mask, i) ((mask & (1 << i)) > 0)

ll binpow(ll x, ll y)
{
    if (!y) re 1 % MOD;
    ll l = binpow(x, y / 2);
    if (y % 2) re l * l % MOD * x % MOD;
    re l * l % MOD;
}

#define inq binpow

ll rev(ll x)
{
    return binpow(x, MOD - 2);
}

int _comb_precomputed_combinatorics = 0;
vector<ll> _comb_fact, _comb_ufact, _comb_rev;

inline void _comb_precompute_combinatorics(int _comb_n)
{
    if (_comb_n < 2) _comb_n = 2;
    if (_comb_precomputed_combinatorics >= _comb_n)
        return;
    _comb_fact.resize(_comb_n);
    _comb_ufact.resize(_comb_n);
    _comb_rev.resize(_comb_n);
    _comb_rev[1] = 1;
    for (int i = max(2, _comb_precomputed_combinatorics); i < _comb_n; i++)
        _comb_rev[i] = MOD - _comb_rev[MOD % i] * (MOD / i) % MOD;
    _comb_fact[0] = 1, _comb_ufact[0] = 1;
    for (int i = max(1, _comb_precomputed_combinatorics); i < _comb_n; i++)
        _comb_fact[i] = _comb_fact[i - 1] * i % MOD, _comb_ufact[i] = _comb_ufact[i - 1] * _comb_rev[i] % MOD;
    _comb_precomputed_combinatorics = _comb_n;
}

ll fact(int x)
{
    if (_comb_precomputed_combinatorics <= x)
        _comb_precompute_combinatorics(x + 1);
    return _comb_fact[x];
}

ll cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (_comb_precomputed_combinatorics <= n)
        _comb_precompute_combinatorics(n + 1);
    return _comb_fact[n] * _comb_ufact[n - k] % MOD * _comb_ufact[k] % MOD;
}

template<typename T> istream& operator>>(istream& in, vector<T>& a)
{
    for (int i = 0; i < a.size(); i++)
        in >> a[i];
    return in;
}

template<typename T> ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (auto e : a)
    {
        out << e << " ";
        if (typeid(T) != typeid(int) && typeid(T) != typeid(ll))
            out << "\n";
    }
    return out;
}

const int K = 1080;
const int N = 100020;

ll n;
ll x0[N], y0[N], x1[N], y1[N];

ll dist[N / K + 2][N][2];
ll distB[N / K + 2][N][2];

ll tmpdist[N][2];

ll abs(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
        x0[i]--, y0[i]--, x1[i]--, y1[i]--;
        x0[i]++, y1[i]++;
    }
    for (int L = 0; L < n; L += K)
    {
        dist[L / K][L][1] = abs(x0[L], y0[L], x1[L], y1[L]);
        for (int i = L - 1; i >= 0; i--)
        {
            dist[L / K][i][0] = dist[L / K][i + 1][0] + abs(x0[i], y0[i], x0[i + 1], y0[i + 1]);
            dist[L / K][i][0] = min(dist[L / K][i][0], dist[L / K][i + 1][1] + abs(x0[i], y0[i], x1[i + 1], y1[i + 1]));
            dist[L / K][i][1] = dist[L / K][i + 1][1] + abs(x1[i], y1[i], x1[i + 1], y1[i + 1]);
            dist[L / K][i][1] = min(dist[L / K][i][1], dist[L / K][i + 1][0] + abs(x1[i], y1[i], x0[i + 1], y0[i + 1]));
        }

        distB[L / K][L][0] = abs(x0[L], y0[L], x1[L], y1[L]);
        for (int i = L - 1; i >= 0; i--)
        {
            distB[L / K][i][0] = distB[L / K][i + 1][0] + abs(x0[i], y0[i], x0[i + 1], y0[i + 1]);
            distB[L / K][i][0] = min(distB[L / K][i][0], distB[L / K][i + 1][1] + abs(x0[i], y0[i], x1[i + 1], y1[i + 1]));
            distB[L / K][i][1] = distB[L / K][i + 1][1] + abs(x1[i], y1[i], x1[i + 1], y1[i + 1]);
            distB[L / K][i][1] = min(distB[L / K][i][1], distB[L / K][i + 1][0] + abs(x1[i], y1[i], x0[i + 1], y0[i + 1]));
        }
    }

    int m;
    cin >> m;
    while (m--)
    {
        int r0, c0, r1, c1;
        cin >> r0 >> c0 >> r1 >> c1;
        r0--, c0--, r1--, c1--;

        if (max(r0, c0) > max(r1, c1))
        {
            swap(r0, r1);
            swap(c0, c1);
        }
        if (max(r0, c0) == max(r1, c1))
        {
            cout << abs(r0, c0, r1, c1) << "\n";
            continue;
        }
        ll ans = 1e18;
        int i = max(r0, c0);
        int j = max(r1, c1);

        tmpdist[j][0] = abs(r1, c1, x0[j], y0[j]), tmpdist[j][1] = abs(r1, c1, x1[j], y1[j]);

        int rj = j / K * K;
        for (int jj = j - 1; jj >= rj; jj--)
        {
            tmpdist[jj][0] = tmpdist[jj + 1][0] + abs(x0[jj], y0[jj], x0[jj + 1], y0[jj + 1]);
            tmpdist[jj][0] = min(tmpdist[jj][0], tmpdist[jj + 1][1] + abs(x0[jj], y0[jj], x1[jj + 1], y1[jj + 1]));
            tmpdist[jj][1] = tmpdist[jj + 1][1] + abs(x1[jj], y1[jj], x1[jj + 1], y1[jj + 1]);
            tmpdist[jj][1] = min(tmpdist[jj][1], tmpdist[jj + 1][0] + abs(x1[jj], y1[jj], x0[jj + 1], y0[jj + 1]));
        }

        if (i + 1 >= rj)
        {
            ans = min(ans, tmpdist[i + 1][0] + abs(x0[i + 1], y0[i + 1], r0, c0));
            ans = min(ans, tmpdist[i + 1][1] + abs(x1[i + 1], y1[i + 1], r0, c0));
        }
        else
        {
            ans = min(ans, abs(r0, c0, x0[i + 1], y0[i + 1]) + dist[rj / K][i + 1][0] + tmpdist[rj][0]);
            ans = min(ans, abs(r0, c0, x0[i + 1], y0[i + 1]) + distB[rj / K][i + 1][0] + tmpdist[rj][1]);
            ans = min(ans, abs(r0, c0, x1[i + 1], y1[i + 1]) + dist[rj / K][i + 1][1] + tmpdist[rj][0]);
            ans = min(ans, abs(r0, c0, x1[i + 1], y1[i + 1]) + distB[rj / K][i + 1][1] + tmpdist[rj][1]);
        }
        cout << ans << "\n";
    }
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