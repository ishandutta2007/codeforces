const long long MOD = 998244353;
const long long INF = 1e9;
const long long INFLL = INF * INF;

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
    int n, m;
    cin >> n >> m;
    vector<vvi> g(2, vvi(n));
    forn(i, m)
    {
        int f, t;
        cin >> f >> t;
        f--, t--;
        g[0][f].pb(t);
        g[1][t].pb(f);
    }

    const int K = 20;
    vector dp_small(K, vector(n, INFLL));
    vector dp_big(2, vector(n, INFLL));

    dp_small[0][0] = 0;
    set<pair<ll, vll> > S;
    S.insert({0, {0, 0, 0}});
    while (S.size())
    {
        auto it = *S.begin();
        S.erase(S.begin());

        //cout << it.first << " " << it.second << "\n";

        // go_further
        int gid = it.second[1] % 2;
        int vid = it.second[2];
        int disttype = it.second[0];

        for (auto e : g[gid][vid])
        {
            if (disttype == 0)
            {
                ll dist = dp_small[it.second[1]][vid];
                if (dp_small[it.second[1]][e] > dist + 1)
                {
                    S.erase({dp_small[it.second[1]][e], {0, it.second[1], e}});
                    dp_small[it.second[1]][e] = dist + 1;
                    S.insert({dp_small[it.second[1]][e], {0, it.second[1], e}});
                }
            }
            else
            {
                int st = it.second[1];
                //cout << "were going to " << e << " from " << vid << "\n";
                if (dp_big[st][e] > dp_big[st][vid] + 1)
                {
                    S.erase({dp_big[st][e], {1, st, e}});
                    dp_big[st][e] = dp_big[st][vid] + 1;
                    S.insert({dp_big[st][e], {1, st, e}});
                }
            }
        }

        // reverse
        if (disttype == 0 && it.second[1] + 1 < K)
        {
            ll dist = dp_small[it.second[1]][vid] + (1 << it.second[1]);
            if (dp_small[it.second[1] + 1][vid] > dist)
            {
                S.erase({dp_small[it.second[1] + 1][vid], {0, it.second[1] + 1, vid}});
                dp_small[it.second[1] + 1][vid] = dist;
                S.insert({dp_small[it.second[1] + 1][vid], {0, it.second[1] + 1, vid}});
            }
        }
        else if (disttype == 0 & it.second[1] + 1 == K)
        {
            ll dist = K * INF + (dp_small[it.second[1]][vid] - (1 << (K - 1)) + 1);
            //cout << "were in v = " << vid << ", dist = " << dp_small[it.second[1]][vid] << "\n";
            //cout << "ndist = " << dist << "\n";
            if (dp_big[K % 2][vid] > dist)
            {
                S.erase({dp_big[K % 2][vid], {1, K % 2, vid}});
                dp_big[K % 2][vid] = dist;
                S.insert({dp_big[K % 2][vid], {1, K % 2, vid}});
            }
        }
        else if (disttype == 1)
        {
            ll dist = dp_big[it.second[1]][vid] + INF;
            if (dp_big[it.second[1] ^ 1][vid] > dist)
            {
                S.erase({dp_big[it.second[1] ^ 1][vid], {1, it.second[1] ^ 1, vid}});
                dp_big[it.second[1] ^ 1][vid] = dist;
                S.insert({dp_big[it.second[1] ^ 1][vid], {1, it.second[1] ^ 1, vid}});
            }
        }
    }

    ll ans = INFLL;
    for (int i = 0; i < K; i++)
    {
        if (dp_small[i][n - 1] != INFLL)
            ans = min(ans, dp_small[i][n - 1]);
    }
    if (ans == INFLL)
    {
        ll res = min(dp_big[0][n - 1], dp_big[1][n - 1]);
        ans = binpow(2, res / INF) + res % INF - 1 + MOD;
    }
    cout << ans % MOD << "\n";
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