const long long MOD = 1e9 + 7;
const long long INF = 1e9 + 10;
const long long INFLL = 4 * INF * INF;

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
#define dbg(x) cerr << __LINE__ << " " << #x << " " << (x) << endl
#define ln cerr << __LINE__ << " fine, thanks" << endl
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

void solve()
{
    int n, k;
    cin >> n >> k;
    vvi a(4, vi(n));
    cin >> a;

    vvi ans;
    vector<vector<pii> > nxt(4, vector<pii>(n));
    for (int i = 0; i < n - 1; i++)
        nxt[1][i] = {1, i + 1};
    nxt[1][n - 1] = {2, n - 1};
    for (int i = n - 1; i > 0; i--)
        nxt[2][i] = {2, i - 1};
    nxt[2][0] = {1, 0};

    int vse = 0;
    while (1)
    {
        int fl = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[1][i] != 0 || a[2][i] != 0)
            {
                fl = 1;
            }
        }
        if (fl == 0)
            break;

        fl = 0;
        for (int r = 1; r <= 2; r++)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[r][i] != 0)
                {
                    int car = a[r][i];
                    pair<int, int> park = {-1, -1};
                    vector<vector<pii> > prev(4, vector<pii>(n, {-1, -1}));
                    prev[r][i] = {r, i};
                    vector<pii> q = {{r, i}};
                    for (int id = 0; id < q.size(); id++)
                    {
                        int x = q[id].first, y = q[id].second;
                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + cx[k], ny = y + cy[k];
                            if (!ok(nx, 4) || !ok(ny, n)) continue;
                            if (prev[nx][ny].first != -1) continue;
                            if (a[nx][ny] == car || (a[nx][ny] == 0 && 1 <= nx && nx <= 2))
                            {
                                if (a[nx][ny] == car) park = {nx, ny};
                                prev[nx][ny] = {x, y};
                                q.push_back({nx, ny});
                            }
                        }
                    }
                    if (park.first != -1)
                    {
                        vector<pii> states;
                        while (prev[park.first][park.second] != park)
                        {
                            states.push_back(park);
                            park = prev[park.first][park.second];
                        }
                        reverse(all(states));
                        for (auto e : states) ans.push_back({car, e.fi + 1, e.se + 1});
                        a[park.first][park.second] = 0;
                        fl = 1;
                    }
                }
            }
        }
        if (fl == 0)
        {
            vse++;
            int suc = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[1][i] == 0 || a[2][i] == 0)
                {
                    pair<int, int> place = {1, i};
                    if (a[1][i] != 0) place = {2, i};

                    for (int j = 0; j < 2 * n; j++)
                    {
                        pii go = nxt[place.first][place.second];
                        int gox = go.fi, goy = go.se;
                        if (a[gox][goy] != 0)
                        {
                            ans.push_back({a[gox][goy], place.fi + 1, place.se + 1});
                        }
                        swap(a[place.fi][place.se], a[gox][goy]);
                        place = go;
                    }

                    suc = 1;
                    break;
                }
            }
            if (suc == 0 || vse == 2 * n)
            {
                cout << -1 << "\n";
                return;
            }
        }
    }

    cout << ans.size() << "\n";
    cout << ans << "\n";
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
    #endif
    while (t--)
    {
        solve();
    }
}