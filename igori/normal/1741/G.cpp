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

void bfs(int v, vi &dist, vector<vi> &graph)
{
    fill(all(dist), -1);
    dist[v] = 0;
    vi q = {v};
    for (int i = 0; i < (int)q.size(); i++)
    {
        for (auto u : graph[q[i]])
        {
            if (dist[u] == -1)
            {
                dist[u] = dist[q[i]] + 1;
                q.push_back(u);
            }
        }
    }
}

void solve()
{
    #define tests

    int n, m;
    cin >> n >> m;
    vvi g(n);
    forn(i, m)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[f].pb(t);
        g[t].pb(f);
    }

    int f;
    cin >> f;
    vi h(f);
    cin >> h;
    forn(i, f) h[i]--;

    int k;
    cin >> k;
    vi p(k);
    cin >> p;
    forn(i, k) p[i]--;

    vvi dist(1 + k, vi(n));
    bfs(0, dist[0], g);
    forn(i, k) bfs(h[p[i]], dist[1 + i], g);

    vi have_car(f, 1);
    forn(i, k) have_car[p[i]] = 0;

    vi dp(1 << k, 0);
    dp[0] = 1;
    for (int i = 0; i < f; i++)
    {
        if (!have_car[i]) continue;
        vi isokmask(1 << k);
        forn(mask, (1 << k))
        {
            if (mask == 0) continue;

            int ok = 0;
            int D0 = dist[0][h[i]];
            vector<int> perm;
            for (int j = 0; j < k; j++) if (withBit(mask, j)) perm.push_back(j);

            while (1)
            {
                int D1 = dist[0][h[p[perm[0]]]];
                for (int j = 0; j + 1 < perm.size(); j++) D1 += dist[1 + perm[j]][h[p[perm[j + 1]]]];
                D1 += dist[1 + perm.back()][h[i]];
                if (D1 == D0) isokmask[mask] = 1;
                //cout << D0 << " " << D1 << "\n";
                if (!next_permutation(all(perm))) break;
            }

            //cout << "Friend " << i << " can help friends " << perm << " : " << isokmask[mask] << "\n";
        }
        for (int f = (1 << k) - 1; f >= 0; f--)
        {
            for (int a = 0; a < (1 << k); a++)
            {
                if (dp[f] && isokmask[a])
                    dp[f | a] = 1;
            }
        }
    }

    int ans = k;
    for (int i = 0; i < (1 << k); i++)
        if (dp[i]) ans = min(ans, k - popcount(i));
    cout << ans << "\n";
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